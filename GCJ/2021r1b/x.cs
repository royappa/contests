using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Transactions;
using Docktor2.SlimUtils;
using Docktor2.DataAccess.Caching.ClientSettings;
using Docktor2.Business.Emails;
using Docktor2.Business.InmateMedicationManagementManager;
using Docktor2.Business.InmateMedicationManagementManager.TasksAndScheduales;
using Docktor2.DataAccess;
using Docktor2.DataAccess.BusinessModels;
using Docktor2.DataAccess.BusinessModels.Enumerators;
using Docktor2.DataAccess.Utility;
using Telerik.Web.UI;
using Docktor2.Business.AutoRenewedOrdersManager;
using System.Text;
using LogHelper;
using Docktor2.Business.Interfaces;
using Docktor2.Utils;
using System.IO;
using Docktor2.DataAccess.BusinessModels.Pharmacy;
using Newtonsoft.Json;
using Docktor2.DataAccess.Security;
using System.IO;
using Docktor2.Business.Utility;
using Docktor2.Business.InmateMedicationManagementManager.InmateDashboard;
using static Constants;
using Docktor2.Business.InmateMedicationManagementManager.InmateDashboard;
using System.Data.Entity.Core.Objects.DataClasses;
using System.Web;

namespace Docktor2.Business.PharmacyOrdersManager
{
    public class PharmacyManager
    {
        #region Properties

        private EFUnitOfWork _efUnitOfWork;
        private EFUnitOfWork EfUnitOfWork => _efUnitOfWork ?? (_efUnitOfWork = new EFUnitOfWork());

        private SystemOptionManager _systemOptionManager;
        private SystemOptionManager SystemOptionManager => _systemOptionManager ?? (_systemOptionManager = new SystemOptionManager());

        private PharmacyOrderRepository _pharmacyOrderRepository;
        private PharmacyOrderRepository PharmacyOrderRepository => _pharmacyOrderRepository
            ?? (_pharmacyOrderRepository = new PharmacyOrderRepository(new EFRepository<PharmacyOrder>(), EfUnitOfWork));

        private PharmacyDeliveryRepository _pharmacyDeliveryRepository;
        private PharmacyDeliveryRepository PharmacyDeliveryRepository => _pharmacyDeliveryRepository
            ?? (_pharmacyDeliveryRepository = new PharmacyDeliveryRepository(new EFRepository<PharmacyDelivery>(), EfUnitOfWork));

        private OrderRepository _orderRepository;
        private OrderRepository OrderRepository => _orderRepository ?? (_orderRepository = new OrderRepository(new EFRepository<Order>(), EfUnitOfWork));

        private OrderCurrentQuantityLogRepository _orderCurrentQuantityLogRepository;
        private OrderCurrentQuantityLogRepository OrderCurrentQuantityLogRepository => _orderCurrentQuantityLogRepository
            ?? (_orderCurrentQuantityLogRepository = new OrderCurrentQuantityLogRepository(new EFRepository<OrderCurrentQuantityLog>(), EfUnitOfWork));

        private TasksManager _tasksManager;
        private TasksManager TasksManager => _tasksManager ?? (_tasksManager = new TasksManager());

        private AutoRenewManager _autoRenewManager;
        private AutoRenewManager AutoRenewManager => _autoRenewManager ?? (_autoRenewManager = new AutoRenewManager(EfUnitOfWork));

        private PafManager _pafManager;
        private PafManager PafManager => _pafManager ?? (_pafManager = new PafManager(EfUnitOfWork));

        private DocumentsManager _documentsManager;
        private DocumentsManager DocumentsManager => _documentsManager ?? (_documentsManager = new DocumentsManager(EfUnitOfWork));

        private MedicationOrdersManager _medicationOrdersManager;
        private MedicationOrdersManager MedicationOrdersManager => _medicationOrdersManager ?? (_medicationOrdersManager = new MedicationOrdersManager(EfUnitOfWork));

        private IPharmacyInterfaceManager _pharmacyInterfaceManager;
        private IPharmacyInterfaceManager PharmacyInterfaceManager
        {
            get
            {
                if (_pharmacyInterfaceManager != null) return _pharmacyInterfaceManager;

                var pharmacyType = SystemOptionManager.GetPharmacyType();
                if (pharmacyType == (int)PharmacyTypes.Kalos)
                {
                    return _pharmacyInterfaceManager ?? (_pharmacyInterfaceManager = new PharmacyManagerKalos());
                }
                else if (pharmacyType == (int)PharmacyTypes.Diamond)
                {
                    return _pharmacyInterfaceManager ?? (_pharmacyInterfaceManager = new PharmacyManagerDiamond());
                }
                throw new NotImplementedException("Pharmacy interface not implemented");
            }
        }

        private PharmacySubmissionRepository _pharmacySubmissionRepository;
        private PharmacySubmissionRepository PharmacySubmissionRepository => _pharmacySubmissionRepository
            ?? (_pharmacySubmissionRepository = new PharmacySubmissionRepository(new EFRepository<PharmacySubmission>(), EfUnitOfWork));

        private PharmacySubmissionResponseRepository _pharmacySubmissionResponseRepository;
        private PharmacySubmissionResponseRepository PharmacySubmissionResponseRepository => _pharmacySubmissionResponseRepository
            ?? (_pharmacySubmissionResponseRepository = new PharmacySubmissionResponseRepository(new EFRepository<PharmacySubmissionResponse>(), EfUnitOfWork));

        private PharmacySubmissionEventRepository _pharmacySubmissionEventRepository;
        private PharmacySubmissionEventRepository PharmacySubmissionEventRepository => _pharmacySubmissionEventRepository
            ?? (_pharmacySubmissionEventRepository = new PharmacySubmissionEventRepository(new EFRepository<PharmacySubmissionEvent>(), 
                EfUnitOfWork));

        private FtpUtility _ftpUtility;
        private FtpUtility FtpUtility => _ftpUtility ?? (_ftpUtility = new FtpUtility(SystemOptionManager.GetCipsSftpHost(),
            SystemOptionManager.GetCipsSftpPort(), SystemOptionManager.GetCipsSftpUserName(),
            SystemOptionManager.GetCipsSftpPassword(), SystemOptionManager.GetCipsRetryAttempts(),
            SystemOptionManager.GetCipsRetryAttemptsGap()));

        private string _cipsTempOutAckFilesPath => Path.Combine(SystemOptionManager.GetCipsTempOutFilesPath(), "HS", "ACK");

        private string _cipsProcessedHsFilesPath => Path.Combine(SystemOptionManager.GetCipsProcessedFilesPath(), "HS");

        private string _cipsProcessedHsAckFilesPath => Path.Combine(SystemOptionManager.GetCipsProcessedFilesPath(), "HS", "ACK");

        private string _cipsProcessedFilesPath => Path.Combine(SystemOptionManager.GetCipsProcessedFilesPath(), "CIPS");

        #endregion

        #region Methods

        public Order GetOrderByPharmacyId(double selectedPharmacyOrderId)
        {
            return
                PharmacyOrderRepository.All().Where(p => p.Id == selectedPharmacyOrderId).Select(p => p.Order).
                    FirstOrDefault();
        }

        public decimal GetPharmacyOrderQuantity(int id)
        {
            return GetPharmacyOrderById(id).Quantity;
        }

        public decimal GetTotalSelectedPharmacyOrderDeliveredQuantity(int selectedPharmacyOrderId, int medicationId)
        {
            return PharmacyDeliveryRepository.GetTotalDeliveredPharmacyOrderQuantity(selectedPharmacyOrderId,
                                                                                     medicationId);
        }

        public PharmacyOrder CheckIfNeedToCreatePharmacyOrder(LightOrder orderToUpdate, bool isMedDelivered)
        {
            if (SystemOptionManager.IsNonQohMode() || !isMedDelivered) return null;

            if ((orderToUpdate.MedicationIsOnsitePharmacy || orderToUpdate.DoNotSendToPharmacy) &&
                orderToUpdate.CurrentQuantity == 0)
            {
                OrderRepository.UpdateOrderOnSitePharmacyCurrentRefillAndQuantityWithLightOrder(orderToUpdate);
                return null;
            }

            if (orderToUpdate.IsCalendarOrder || orderToUpdate.IsHomeMedication || /*orderToUpdate.IsRecurrenceOrder ||*/
                CheckIfOrderHasPharmacyOrder(orderToUpdate.Id))
            {
                return null;
            }

            if (orderToUpdate.IsRecurrenceOrder)
            {
                if (orderToUpdate.Refills != orderToUpdate.CurrentRefill)
                {
                    Order order = OrderRepository.All().FirstOrDefault(p => p.Id == orderToUpdate.Id);
                    var nextOrderDates = order.OrderCalenders
                            .Where(p =>
                                p.Date >= DateTimeUtility.CurrentDateTime
                                && order.MedicationsDeliveries
                                    .Where(t => ((int)(t.DeliveryDate - p.Date).TotalHours) == 0)
                                    .Count() == 0)
                                    .Select(p => p.Date).ToList();

                    if (nextOrderDates.Count == 0)
                        return null;

                    //Find number of deliveries to check against quantity, either days left setting (system options) or count of deliveries, whichever is lower.
                    int daysLeftToCreatePharmOrder = GetNumbersOfDaysLeftToCreatePharmacyOrder();
                    int k = (nextOrderDates.Count >= daysLeftToCreatePharmOrder) ? daysLeftToCreatePharmOrder : nextOrderDates.Count;

                    if (order.CurrentQuantity < k * (decimal)orderToUpdate.Dose)
                    {
                        //Removed the bit where it would order less than the original order if it wasn't needed.  
                        //Medications don't work like that, they have to refill the amount that was given initially.                        
                        return CreatePharmacyOrderWithRefillQuantityWithLightOrder(orderToUpdate);
                    }
                }

                return null;
            }
            else
            {
                float quantityPerDay = CalculateQuantityPerDay(orderToUpdate);
                float numberOfDayThatQuantityOnJailWillCover = orderToUpdate.Type != (int)OrderType.KOP && quantityPerDay > 0 ?
                                                                ((float)orderToUpdate.CurrentQuantity / quantityPerDay) : 1;
                if (numberOfDayThatQuantityOnJailWillCover <= GetNumbersOfDaysLeftToCreatePharmacyOrder())
                {
                    if (orderToUpdate.Refills != orderToUpdate.CurrentRefill)
                    {
                        return CreatePharmacyOrderWithRefillQuantityWithLightOrder(orderToUpdate);
                    }
                    else if(!orderToUpdate.IsAutoRenewed)
                    {
                        //if no Refills OR all Refills are filled out and Med Order has child order
                        //then create pharmacy order for child order if not created already
                        return CheckPharmacyOrderForChildMedOrder(orderToUpdate);
                    }
                }
            }

            #region Auto Renew Order
            if (orderToUpdate.IsAutoRenewed)
            {
                var or = OrderRepository.GetOrderWithCalendarsById(orderToUpdate.Id);
                if (AutoRenewManager.IsAutoRenewNeeded(or))
                {
                    or = AutoRenewManager.RenewOrder(or);
                    SendOrderToPharmacy(or, or.PAF.Inmate, null, false);

                    if (Configurations.AutoDelivery)
                        foreach (PharmacyOrder pharmacyOrder in or.PharmacyOrders)
                        {
                            if (pharmacyOrder.PharmacyDeliveries.Count == 0)
                                QuickDeliverPharmacyOrder(pharmacyOrder.Id, pharmacyOrder.Quantity,
                                                                          or.MedicationId.Value);
                        }
                }
            }
            #endregion

            return null;
        }

        public bool CheckIfOrderHasPharmacyOrder(long orderId)
        {
            return CountOfNotAcceptedDeliveries(orderId) > 0;
        }

        public bool IsOrderInThresholdRange(long orderId, bool checkIfNoRefillLeft = true)
        {
            var order = OrderRepository.All().FirstOrDefault(x => x.Id == orderId);
            if (order == null || (checkIfNoRefillLeft && order.RefillsLeft > 0) || 
                !order.IsActive || order.AsDirected || order.CurrentQuantity <= 0)
                return false;

            var thresholdDaysToCreatePharmacyOrder = GetNumbersOfDaysLeftToCreatePharmacyOrder();
            if (order.IsRecurrenceOrder)
            {
                var nextOrderDates = order.OrderCalenders.Where(p => p.Date >= DateTimeUtility.CurrentDateTime
                                                                && order.MedicationsDeliveries.Where(t =>
                                                                    ((int)(t.DeliveryDate - p.Date).TotalHours) == 0).Count() == 0
                                                                ).Select(p => p.Date).ToList();
                return nextOrderDates.Count != 0 && order.CurrentQuantity <= (Math.Min(nextOrderDates.Count, thresholdDaysToCreatePharmacyOrder) * (decimal)order.Dose);
            }

            float quantityPerDay = CalculateQuantityPerDay(order);
            float daysLeftInCurrentQty = order.Type != (int)OrderType.KOP && quantityPerDay > 0 ? ((float)order.CurrentQuantity / quantityPerDay) : 1;
            return daysLeftInCurrentQty <= thresholdDaysToCreatePharmacyOrder;
        }

        public PharmacyOrder CheckAndCreatePharmacyOrderForMedChildOrder(LightOrder lightParentOrder)
        {
            return CheckPharmacyOrderForChildMedOrder(lightParentOrder);
        }

        /// <summary>
        /// check all child med orders and if pharmacy order has not been created, create for that order.
        /// usually this is consumed by Healthsecure service.
        /// and helpful when parent order is end dated (due to order end date) before quantity finished
        /// and that causing child orders not being sent to pharmacy
        /// </summary>
        /// <returns></returns>
        public void CheckAndCreatePharmacyOrderForChildOrders()
        {
            if (SystemOptionManager.GetPharmacyImmediateEndDateMode())
            {
                int thresholdDays = GetNumbersOfDaysLeftToCreatePharmacyOrder();
                DateTime today = DateTimeUtility.CurrentDateTime;
                int linkedOrderType = (int)LinkedChildMedOrderType.StartChildWhenParentCompleted;
                using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, CustomTransactionOptions.TransactionOption))
                {
                    var orders =
                            (
                                from parentOrder in OrderRepository.All().Include(p => p.PAF).Include(p => p.PAF.Inmate)
                                join childOrderJoin in OrderRepository.All().Include(c => c.PharmacyOrders)
                                    on parentOrder.Id equals childOrderJoin.ParentId into childOrders
                                from childOrder in childOrders.DefaultIfEmpty()
                                where 
                                    parentOrder.PAF.Inmate.Status //only active inmate
                                    && !parentOrder.IsAutoRenewed //order must not be auto-renewed
                                    && (!parentOrder.Refills.HasValue || parentOrder.Refills.Value == parentOrder.CurrentRefill) //no refill left
                                    && parentOrder.OrderEndDate != null && DbFunctions.DiffDays(today, parentOrder.OrderEndDate.Value) <= thresholdDays //order end date is within threshold no. of days
                                    && childOrder != null && (childOrder.OrderEndDate == null || DbFunctions.DiffMinutes(today, childOrder.OrderEndDate.Value) > 0) //child order must be active
                                    && childOrder.LinkedChildOrderType.HasValue && childOrder.LinkedChildOrderType.Value == linkedOrderType //child order must be of type 'Start when Parent Completed'
                                    && !childOrder.DoNotSendToPharmacy && !childOrder.PharmacyOrders.Any() //no pharmacy order created
                                select parentOrder
                            ).ToList();
                    foreach(var order in orders)
                    {
                        CheckPharmacyOrderForChildMedOrder(order);
                    }
                    transactionScope.Complete();
                }
            }
        }

        private PharmacyOrder CheckPharmacyOrderForChildMedOrder(LightOrder lightParentOrder)
        {
            Order parentOrder = OrderRepository.GetOrderWithCalendarsById(lightParentOrder.Id);
            if (parentOrder.Childs.Any(x => x.IsActive && !x.DoNotSendToPharmacy))
            {
                foreach (Order childOrder in parentOrder.Childs.Where(x => x.IsActive))
                {
                    Order order = OrderRepository.All().Include(p => p.PAF).Include(p => p.PAF.Inmate)
                                    .Include(x => x.PharmacyOrders).FirstOrDefault(x => x.Id == childOrder.Id);
                    if (order != null && order.PharmacyOrders.Count == 0)
                    {
                        var pharmacyOrder = new PharmacyOrder
                        {
                            OrderId = order.Id,
                            CreationDate = DateTimeUtility.CurrentDateTime,
                            Quantity = order.Quantity ?? 0,
                            Status = (int)PharmacyOrderStatus.WaitingFromPharmacy
                        };
                        SavePharmacyOrder(pharmacyOrder);

                        if (!order.DataEntry)
                        {
                            SendOrderToPharmacy(order, order.PAF.Inmate, null, false);
                        }

                        //if DataEntry or ProfileOnly then accept the pharmacy order
                        if (order.DataEntry || order.ProfileOnly)
                        {
                            var pharmacyDelivery = PharmacyDeliveryRepository.All().FirstOrDefault(x => x.PharmacyOrderId == pharmacyOrder.Id);
                            if (pharmacyDelivery != null)
                            {
                                if (Configurations.PaperPharmacy && string.IsNullOrWhiteSpace(order.RXNumber))
                                {
                                    order.RXNumber = "NoRx";
                                    OrderRepository.Save();
                                }
                                var userId = SecurityManager.GetCurrentUserId() ?? order.EnteredByUserId;
                                UpdateMedicationRecievedQuantity(pharmacyDelivery.DeliveredQuantity, order.RXO, false);
                                AcceptPharmacyOrder(order.PAF.InmateId, DateTimeUtility.CurrentDateTime, DateTimeUtility.CurrentDateTime,
                                    order.PAF.Inmate.LocationId, userId, null, order.RXO, false);
                            }
                        }
                        return pharmacyOrder;
                    }
                }
            }

            return null;
        }

        private PharmacyOrder CreatePharmacyOrderWithRefillQuantityWithLightOrder(LightOrder lightOrder)
        {
            #region Check if there are not accepted pharmay deliveries yet

            //Use PharmacyOrderStatus.Accept to check that there is no order with zero filled
            //Use PharmacyOrderStatus.SentToJail to check if there is quantity still not deliveried from pharmacy
            int countOfNotAcceptedDeliveries = CountOfNotAcceptedDeliveries(lightOrder.Id);

            #endregion

            if (lightOrder.CurrentRefill != lightOrder.Refills && countOfNotAcceptedDeliveries == 0)
            {
                var order = OrderRepository.All().Include(p => p.PAF).Include(p => p.PAF.Inmate).FirstOrDefault(p => p.Id == lightOrder.Id);
                if (order == null) return null;

                if (order.Quantity != null)
                {
                    var quantityOfRefill = (int)order.Quantity;
                    var pharmacyOrder = new PharmacyOrder
                    {
                        OrderId = order.Id,
                        CreationDate = DateTimeUtility.CurrentDateTime,
                        Quantity = quantityOfRefill,
                        Status = (int)PharmacyOrderStatus.WaitingFromPharmacy
                    };
                    SavePharmacyOrder(pharmacyOrder);
                    SendOrderToPharmacy(order, order.PAF.Inmate, null, true);
                    return pharmacyOrder;
                }
            }
            return null;
        }

        public PharmacyOrder CreatePharmacyOrderWithRefillQuantity(Order order)
        {
            #region Check if there are not accepted pharmay deliveries yet

            //Use PharmacyOrderStatus.Accept to check that there is no order with zero filled
            //Use PharmacyOrderStatus.SentToJail to check if there is quantity still not deliveried from pharmacy
            int countOfNotAcceptedDeliveries = CountOfNotAcceptedDeliveries(order.Id);

            #endregion

            if (order.CurrentRefill != order.Refills && countOfNotAcceptedDeliveries == 0)
            {
                if (order.Quantity != null)
                {
                    var quantityOfRefill = (int)order.Quantity;
                    var pharmacyOrder = new PharmacyOrder
                    {
                        OrderId = order.Id,
                        CreationDate = DateTimeUtility.CurrentDateTime,
                        Quantity = quantityOfRefill,
                        Status = (int)PharmacyOrderStatus.WaitingFromPharmacy
                    };
                    SavePharmacyOrder(pharmacyOrder);
                    SendOrderToPharmacy(order, order.PAF.Inmate, null, true);
                    return pharmacyOrder;
                }
            }
            return null;
        }

        private int CountOfNotAcceptedDeliveries(long orderId)
        {
            return PharmacyOrderRepository.All().Count(
                p =>
                p.OrderId == orderId && p.Status != (int)PharmacyOrderStatus.Accept &&
                (p.IsDeleted == null || p.IsDeleted == false));
        }

        private float CalculateQuantityPerDay(LightOrder order)
        {
            return (float)(order.Dose * (DeliveryPeriodsManager.DeliveryPeriods.FirstOrDefault(dp => dp.Id == order.DeliveryPeriodId)?.DeliveryPeriodsTimes.Count ?? 0));
        }

        private int GetNumbersOfDaysLeftToCreatePharmacyOrder()
        {
            return SystemOptionManager.GetNumberOfDaysLeftToCreatePharmacyOrder();
        }

        private void SavePharmacyOrder(PharmacyOrder pharmacyOrder)
        {
            PharmacyOrderRepository.Add(pharmacyOrder);
            PharmacyOrderRepository.Save();

            if (Configurations.AutoDelivery)
            {
                int? pharmacyOrderMedicationId =
                    OrderRepository.All().Where(p => p.Id == pharmacyOrder.OrderId).Select(p => p.MedicationId).
                        FirstOrDefault();

                if (pharmacyOrderMedicationId.HasValue)
                    QuickDeliverPharmacyOrder(pharmacyOrder.Id, pharmacyOrder.Quantity, pharmacyOrderMedicationId.Value);
            }
        }

        private void DelieverPharmacyOrder(int pharmacyOrderId, int medicationId, decimal quantityToDeliver,
                                           PharmacyOrderStatus pharmacyOrderStatus)
        {
            var pharmacyDelivery = GetNewPharmacyDelivery(medicationId, pharmacyOrderId, quantityToDeliver, pharmacyOrderStatus);
            PharmacyDeliveryRepository.Add(pharmacyDelivery);
            PharmacyDeliveryRepository.Save();
        }

        public Order GetOrderByIDWithInmateID(long orderId)
        {
            Order order =
                OrderRepository.All().Include(p => p.PAF).Include(p => p.PAF.Inmate).FirstOrDefault(p => p.Id == orderId);
            return order;
        }

        public List<PharmacyDelivery> LoadPharmacyDeliveriesByPharmacyOrderId(int selectedPharmacyOrderId)
        {
            return
                PharmacyDeliveryRepository.All().Include(p => p.Medication).Where(
                    n => n.PharmacyOrderId == selectedPharmacyOrderId).ToList();
        }

        public int GetPharmacyOrderMedicationId(int pharmacyOrderId)
        {
            int? medicationId = GetPharmacyOrderById(pharmacyOrderId).Order.MedicationId;
            if (medicationId != null)
            {
                int medId = medicationId.Value;
                return medId;
            }
            return 0;
        }

        public PharmacyOrder GetPharmacyOrderById(int id) => PharmacyOrderRepository.All().FirstOrDefault(x => x.Id == id);

        public void UpdatePharmacyOrderStatus(int pharmacyOrderId, PharmacyOrderStatus sentToJail)
        {
            PharmacyOrderRepository.UpdatePhrmacyOrderStatus(pharmacyOrderId, (int)sentToJail);
        }

        public void PharmacyOrderManuallySent(int pharmacyOrderId)
        {
            var pharmacyOrder = PharmacyOrderRepository.All().FirstOrDefault(x => x.Id == pharmacyOrderId);
            if (pharmacyOrder == null) return;

            pharmacyOrder.IsManuallySentToPharmacy = true;
            PharmacyOrderRepository.Save();
        }

        private decimal GetTotalSelectedPharmacyOrderDeliveredQuantity(decimal selectedPharmacyOrderId)
        {
            return PharmacyDeliveryRepository.GetTotalDeliveredPharmacyOrderQuantity(selectedPharmacyOrderId);
        }

        public bool UpdateMedOrderRXRequiredStatus(int pharmacyOrderId)
        {
            var pharmacyOrder = PharmacyOrderRepository.All().FirstOrDefault(x => x.Id == pharmacyOrderId);
            if (pharmacyOrder == null || pharmacyOrder.Order.RXRequiredInNextPharmacyDelivery) return false;

            pharmacyOrder.Order.RXRequiredInNextPharmacyDelivery = true;
            PharmacyOrderRepository.Save();
            return true;
        }

        public bool SaveMedOrderRXNumber(int pharmacyOrderId, string rxNumber)
        {
            var pharmacyOrder = PharmacyOrderRepository.All().FirstOrDefault(x => x.Id == pharmacyOrderId);
            if (pharmacyOrder == null) return false;
            if (IsRXNumberExist(pharmacyOrder.Order.Id, rxNumber)) return false;

            pharmacyOrder.Order.RXRequiredInNextPharmacyDelivery = false;
            pharmacyOrder.Order.RXNumber = rxNumber;
            PharmacyOrderRepository.Save();
            return true;
        }

        public bool SaveMedOrderRXNumberById(int orderId, string rxNumber)
        {
            var order = OrderRepository.All().FirstOrDefault(x => x.Id == orderId);
            if (order == null) return false;
            if (IsRXNumberExist(orderId, rxNumber)) return false;

            order.RXNumber = rxNumber;
            order.RXRequiredInNextPharmacyDelivery = true;
            OrderRepository.Save();
            return true;
        }

        public string GetMedicationOrderRXNumber(long orderId)
        {
            var order = OrderRepository.All().FirstOrDefault(x => x.Id == orderId);
            return order != null && !string.IsNullOrWhiteSpace(order.RXNumber) ? order.RXNumber : string.Empty;
        }

        public Dictionary<long, string> GetMedicationOrderRXNumberByIds(List<long> orderIds)
        {
            return OrderRepository.All().Where(x => orderIds.Contains(x.Id)).ToDictionary(x => x.Id, x => x.RXNumber);
        }

        public bool IsOrderHasValidRXNumber(int orderId)
        {
            return OrderRepository.All().Any(x => x.Id == orderId && x.RXNumber != null && x.RXNumber != string.Empty &&
                                                  !x.RXRequiredInNextPharmacyDelivery);
        }

        private bool IsRXNumberExist(long orderId, string rxNumber)
        {
            return OrderRepository.All().Any(x => x.RXNumber == rxNumber && x.Id != orderId);
        }

        #region Pharmacy Delivery

        public void QuickDeliverPharmacyOrder(int pharmacyOrderId, decimal quantity, int medicationId)
        {
            decimal remainingQuantityToDeliver = GetSelectedPharmacyOrderQuantityToDeliver(pharmacyOrderId, quantity);
            if (remainingQuantityToDeliver > 0)
            {
                using (
                    var transactionScope = new TransactionScope(TransactionScopeOption.Required,
                                                                CustomTransactionOptions.TransactionOption))
                {
                    DelieverPharmacyOrder(pharmacyOrderId, medicationId, remainingQuantityToDeliver,
                                          PharmacyOrderStatus.SentToJail);
                    UpdatePharmacyOrderStatus(pharmacyOrderId, PharmacyOrderStatus.SentToJail);
                    transactionScope.Complete();
                }
            }
        }

        public void DeliverPharmacyOrder(int pharmacyOrderId, int medicationId, decimal orderQuantity,
                                         decimal deliveriedQuantity)
        {
            decimal remainingQuantityToDeliver = GetSelectedPharmacyOrderQuantityToDeliver(pharmacyOrderId,
                                                                                           orderQuantity);

            PharmacyOrderStatus pharmacyOrderStatus = (deliveriedQuantity >= remainingQuantityToDeliver)
                                                          ? PharmacyOrderStatus.SentToJail
                                                          : PharmacyOrderStatus.SentToJailPartialy;

            using (
                var transactionScope = new TransactionScope(TransactionScopeOption.Required,
                                                            CustomTransactionOptions.TransactionOption))
            {
                DelieverPharmacyOrder(pharmacyOrderId, medicationId, deliveriedQuantity, pharmacyOrderStatus);
                UpdatePharmacyOrderStatus(pharmacyOrderId, pharmacyOrderStatus);
                transactionScope.Complete();
            }
        }

        public void DeliveryAllPharmacyOrders(int? selectedInmateId, DateTime? startDate, DateTime? endDate,
                                              List<int> locations)
        {
            List<LightPharmacyOrder> pharmacyOrders = PharmacyOrderRepository.DeliveryAllPharmacyOrders(
                selectedInmateId, startDate, endDate, locations);
            using (
                var transactionScope = new TransactionScope(TransactionScopeOption.Required,
                                                            CustomTransactionOptions.TransactionOption))
            {
                foreach (LightPharmacyOrder lightPharmacyOrder in pharmacyOrders)
                {
                    decimal remainingQuantityToDeliver = GetSelectedPharmacyOrderQuantityToDeliver(lightPharmacyOrder);
                    DelieverPharmacyOrder(lightPharmacyOrder.Id, lightPharmacyOrder.MedicationId.Value,
                                          remainingQuantityToDeliver, PharmacyOrderStatus.SentToJail);
                    UpdatePharmacyOrderStatus(lightPharmacyOrder.Id, PharmacyOrderStatus.SentToJail);
                }
                transactionScope.Complete();
            }
        }

        private decimal GetSelectedPharmacyOrderQuantityToDeliver(LightPharmacyOrder lightPharmacyOrder)
        {
            decimal orderQuantity = lightPharmacyOrder.Quantity;
            decimal deliveredQuantity = GetTotalSelectedPharmacyOrderDeliveredQuantity(lightPharmacyOrder.Id);
            return Math.Max(orderQuantity - deliveredQuantity, 0);
        }

        public decimal GetSelectedPharmacyOrderQuantityToDeliver(int pharmacyOrderId, decimal quantity)
        {
            decimal orderQuantity = quantity;
            decimal deliveredQuantity = GetTotalSelectedPharmacyOrderDeliveredQuantity(pharmacyOrderId);
            return Math.Max(orderQuantity - deliveredQuantity, 0);
        }

        public void AcceptAllPharmacyOrder(int? selectedInmateId, DateTime? startDate, DateTime? endDate,
                                           int selectedLocation, Guid userId,
                                           List<int> excludedPharmacyRecievingPharmacyOrdersIds)
        {
            if (excludedPharmacyRecievingPharmacyOrdersIds == null)
            {
                excludedPharmacyRecievingPharmacyOrdersIds = new List<int>();
            }

            DateTime date = DateTimeUtility.CurrentDateTime;
            if (startDate == null)
            {
                startDate = date;
            }
            if (endDate == null)
            {
                endDate = date;
            }

            //0002238: 0010175: Pharmacy Request Cutoff Time

            if (date.Date == endDate.Value.Date)
            {
                DateTime cutoff = Configurations.PharmacyRequestCutoffTime;
                endDate = new DateTime(endDate.Value.Year, endDate.Value.Month, endDate.Value.Day, cutoff.Hour,
                                       cutoff.Minute, 0);
            }

            else
            {
                endDate = new DateTime(endDate.Value.Year, endDate.Value.Month, endDate.Value.Day, 23,
                                       59, 59);
            }

            var locations = new List<int>();
            locations.AddRange(LocationsManager.GetAllChildLocations(selectedLocation).Select(p => p.Id));

            List<PharmacyOrder> pharmacyOrders =
                PharmacyOrderRepository.GetPharmacyOrdersByInmateAndDate(selectedInmateId, (DateTime)startDate,
                                                                         (DateTime)endDate,
                                                                         locations);

            var deliveriedOrders = new List<int>();
            using (
                var transactionScope = new TransactionScope(TransactionScopeOption.Required,
                                                            CustomTransactionOptions.TransactionOption))
            {
                foreach (PharmacyOrder pharmacyOrder in pharmacyOrders)
                {
                    if (excludedPharmacyRecievingPharmacyOrdersIds.Contains(pharmacyOrder.Id) ||
                        (Configurations.PaperPharmacy && (string.IsNullOrWhiteSpace(pharmacyOrder.Order.RXNumber) ||
                        pharmacyOrder.Order.RXRequiredInNextPharmacyDelivery)))
                    {
                        continue;
                    }
                    deliveriedOrders.Add(pharmacyOrder.Id);

                    AcceptPharmacyOrder(pharmacyOrder, userId);
                }

                OrderRepository.Save();
                PharmacyOrderRepository.Save();

                Logger.Instance.LogInfo("Pharmacy Orders Accept",
                                          string.Format(
                                              "StartDate: {0}, EndDate{1}, InmateId:{2}, LocationId:{3}, ExecludedIds:{4}, DeliveriedOrders:{5}",
                                              startDate.ToString(), endDate.ToString(), selectedInmateId.ToString(),
                                              selectedLocation.ToString(),
                                              string.Join(",", excludedPharmacyRecievingPharmacyOrdersIds),
                                              string.Join(",", deliveriedOrders)));

                transactionScope.Complete();
            }
        }

        public void AcceptPharmacyOrder(int? selectedInmateId, DateTime? startDate, DateTime? endDate,
                                           int selectedLocation, Guid userId,
                                           List<int> excludedPharmacyRecievingPharmacyOrdersIds,
                                           string rxoNumber, bool canRxoBeRxNumber)
        {
            if (excludedPharmacyRecievingPharmacyOrdersIds == null)
            {
                excludedPharmacyRecievingPharmacyOrdersIds = new List<int>();
            }

            var date = DateTimeUtility.CurrentDateTime;
            if (startDate == null)
            {
                startDate = date;
            }
            if (endDate == null)
            {
                endDate = date;
            }

            //0002238: 0010175: Pharmacy Request Cutoff Time
            endDate = date.Date == endDate.Value.Date
                ? endDate.Value.Date.Add(Configurations.PharmacyRequestCutoffTime.TimeOfDay)
                : endDate.Value.GetEndTimeOfDay();

            var rxNumber = rxoNumber;
            if (canRxoBeRxNumber && SystemOptionManager.GetPharmacyType() != (int)PharmacyTypes.Legacy)
            {
                rxoNumber = GetActivePharmacyResponseByRxNumberOrRxo(rxoNumber)?.Order?.RXO;
            }

            var pharmacyOrder = PharmacyOrderRepository.GetActivePharmacyOrderByRxo(rxoNumber);
            if (pharmacyOrder == null || excludedPharmacyRecievingPharmacyOrdersIds.Contains(pharmacyOrder.Id))
            {
                Logger.Instance.LogInfo("0013600: Pharmacy Scanning issue", new StringBuilder()
                        .AppendLine(DateTimeUtility.CurrentDateTime.ToDateTimeString())
                        .AppendLine("Docktor2.Business.PharmacyOrdersManager.AcceptPharmacyOrder")
                        .AppendLine("CutOffTime => " + Configurations.PharmacyRequestCutoffTime)
                        .AppendLine("CurrentDate => " + date.Date.ToDateTimeString())
                        .AppendLine("EndDate => " + endDate.Value.ToDateTimeString())
                        .AppendLine("ExcIds.Count => " + excludedPharmacyRecievingPharmacyOrdersIds.Count)
                        .AppendLine("PharmacyOrder is null => " + pharmacyOrder.IsNull())
                        .AppendLine("RXO Number => " + rxoNumber)
                        .AppendLine("ExcIds.Contains => " + (pharmacyOrder != null && excludedPharmacyRecievingPharmacyOrdersIds.Contains(pharmacyOrder.Id)))
                        .ToString());

                return;
            }

            //do not accept pharmacy order if RXNumber is not entered
            if (Configurations.PaperPharmacy && string.IsNullOrWhiteSpace(pharmacyOrder.Order.RXNumber)) return;

            using (var transactionScope = new TransactionScope(TransactionScopeOption.Required, CustomTransactionOptions.TransactionOption))
            {
                var order = pharmacyOrder.Order;

                if (!order.IsFromStock && !order.TaperId.HasValue && SystemOptionManager.GetPharmacyImmediateEndDateMode() && IsNewFill(order))
                {
                    var currentDateTime = DateTimeUtility.CurrentDateTime;

                    if (!order.StartDateTime.HasValue || order.StartDateTime.Value < DateTimeUtility.CurrentDateTime)
                    {
                        if (order.Days.HasValue)
                        {
                            order.OrderEndDate = currentDateTime.AddDays(order.Days.Value * ((order.Refills ?? 0) + 1));
                        }
                        else if (order.StartDateTime.HasValue && order.OrderEndDate.HasValue)
                        {
                            order.OrderEndDate = currentDateTime.AddMinutes((order.OrderEndDate.Value - order.StartDateTime.Value).TotalMinutes);
                        }
                        else if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Recurrence)
                        {
                            order.OrderEndDate = order.OrderCalenders.MaxOrDefault(x => x.Date);
                        }
                        order.StartDateTime = currentDateTime; 
                    }

                    if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Recurrence &&
                        order.OrderCalenders.Any() && order.OrderCalenders.Min(x => x.Date) < currentDateTime)
                    {
                        var orderFirstOccurrence = order.OrderCalenders.Min(x => x.Date);
                        foreach (var orderCalendarsGroup in order.OrderCalenders.GroupBy(x => x.RecurrencePattern).OrderBy(x => x.Min(y => y.Date)))
                        {
                            var firstOccurrence = orderCalendarsGroup.Min(x => x.Date);
                            var startFrom = firstOccurrence == orderFirstOccurrence
                                ? currentDateTime
                                : currentDateTime.AddDays((firstOccurrence - orderFirstOccurrence).TotalDays);

                            var recurrenceRule = RecurrenceHelper.ShiftRecurrenceFromDateTime(startFrom, orderCalendarsGroup.Key);

                            var index = 0;
                            var occurrences = recurrenceRule.Occurrences.ToArray();
                            foreach (var orderCalender in orderCalendarsGroup)
                            {
                                orderCalender.Date = occurrences[index++];
                                orderCalender.RecurrencePattern = recurrenceRule.ToString();
                                orderCalender.RecurrenceEndDate = recurrenceRule.Range.RecursUntil;
                            }
                        }

                        order.OrderEndDate = order.OrderCalenders.Max(x => x.Date);
                    }
                }

                var pharmacyDelivery = pharmacyOrder.PharmacyDeliveries.FirstOrDefault(p => p.Status != (int)PharmacyOrderStatus.Accept);

                AcceptPharmacyOrder(pharmacyOrder, userId);

                if (canRxoBeRxNumber && SystemOptionManager.GetPharmacyType() != (int)PharmacyTypes.Legacy && !string.IsNullOrWhiteSpace(rxNumber))
                {
                    var pharmacyResponse = PharmacySubmissionResponseRepository.All()
                        .FirstOrDefault(x => !x.IsReceived && (x.RxdRxNumber == rxNumber || x.Order.RXO == rxNumber));

                    if (pharmacyResponse != null)
                    {
                        pharmacyResponse.IsReceived = true;
                        PharmacySubmissionResponseRepository.Save();
                    }
                }

                OrderRepository.Save();
                PharmacyOrderRepository.Save();

                Logger.Instance.LogInfo("Pharmacy Orders Accept", string.Format("StartDate: {0}, EndDate{1}, InmateId:{2}, LocationId:{3}, ExecludedIds:{4}, DeliveriedOrder:{5}",
                    startDate?.ToDateTimeString(), endDate?.ToDateTimeString(), selectedInmateId?.ToString() ?? string.Empty, selectedLocation,
                    string.Join(",", excludedPharmacyRecievingPharmacyOrdersIds), pharmacyOrder.Id));

                transactionScope.Complete();
            }
        }

        private void AcceptPharmacyOrder(PharmacyOrder pharmacyOrder, Guid userId)
        {
            Order order = OrderRepository.All().FirstOrDefault(p => p.Id == pharmacyOrder.OrderId);

            //Skip orders from previous bookings.
            if (order == null) return;

            decimal orderCurrentQuantity = order.CurrentQuantity;

            foreach (PharmacyDelivery pharmacyDelivery in pharmacyOrder.PharmacyDeliveries)
            {
                if (pharmacyDelivery.Status != (int)PharmacyDeliveryStatus.Accept)
                {
                    pharmacyDelivery.Status = (int)PharmacyDeliveryStatus.Accept;
                    pharmacyDelivery.ApprovedDate = DateTimeUtility.CurrentDateTime;
                    pharmacyDelivery.ApprovedByUserId = userId;
                    if (pharmacyDelivery.RecievedQuantity == null)
                    {
                        pharmacyDelivery.RecievedQuantity = pharmacyDelivery.DeliveredQuantity;
                        order.CurrentQuantity = order.CurrentQuantity + pharmacyDelivery.DeliveredQuantity;
                    }
                    else
                    {
                        order.CurrentQuantity = order.CurrentQuantity + pharmacyDelivery.RecievedQuantity.Value;
                    }
                }
            }

            //set true to force user to enter RX value for the next Pharmacy Delivery
            if (Configurations.PaperPharmacy)
                order.RXRequiredInNextPharmacyDelivery = true;

            //DC parent order if child is of LinkedChildMedOrderType.DCParentWhenChildReceivedInPharmacy
            if(order.ParentId.HasValue && order.LinkedChildOrderType.HasValue &&
                order.LinkedChildOrderType.Value == (int)LinkedChildMedOrderType.DCParentWhenChildReceivedInPharmacy)
            {
                var parentOrder = OrderRepository.All().FirstOrDefault(p => p.Id == order.ParentId.Value);
                if(parentOrder != null && (!parentOrder.OrderEndDate.HasValue || parentOrder.OrderEndDate.Value > DateTimeUtility.CurrentDateTime))
                {
                    parentOrder.DiscontinueNote = "D/C by child when received from pharmacy";
                    parentOrder.OrderEndDate = DateTimeUtility.CurrentDateTime;
                    parentOrder.DiscontinueActiveChild = false;
                    parentOrder.DiscontinueActiveParent = false;
                    MedicationOrdersManager.UpdateDiscontinueOrder(parentOrder, userId);
                }
            }

            if (order.StartDateTime == null)
            {
                order.StartDateTime = DateTimeUtility.CurrentDateTime;

                if (order.TaperId != null && order.TaperOrders.OrderBy(p => p.Id).First().StartDate == null)
                {
                    PafManager.ScheduleTaper(order, order.Taper, DateTimeUtility.CurrentDateTime);

                    OrderRepository.Save();
                    if (order.OtherOrder != null)
                    {
                        TasksManager.AddOtherOrderTasks(order.OtherOrder);
                    }
                }

                if (order.TaperId == null && order.OtherOrder != null && order.CreateNonMedOrder)
                {
                    order.OtherOrder.Stage = (int)OtherOrderStage.Scheduled_InProgress;
                    var otherOrderSchedules = new List<OtherOrderSchedule>();

                    if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Calendar)
                    {
                        foreach (OrderCalender orderCalender in order.OrderCalenders)
                        {
                            var nonMedOrderSchedule = new OtherOrderSchedule();
                            nonMedOrderSchedule.ScheduleDate = orderCalender.Date;
                            nonMedOrderSchedule.RecurrencePattern = orderCalender.RecurrencePattern;
                            nonMedOrderSchedule.RecurrenceEndDate = orderCalender.RecurrenceEndDate;
                            otherOrderSchedules.Add(nonMedOrderSchedule);
                        }
                    }
                    else if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Recurrence)
                    {
                        foreach (OrderCalender orderCalender in order.OrderCalenders)
                        {
                            if (otherOrderSchedules.Count(p =>
                                                          p.RecurrencePattern == orderCalender.RecurrencePattern) ==
                                0)
                            {
                                var nonMedOrderSchedule = new OtherOrderSchedule();
                                nonMedOrderSchedule.ScheduleDate = orderCalender.Date;
                                nonMedOrderSchedule.RecurrencePattern = orderCalender.RecurrencePattern;
                                nonMedOrderSchedule.RecurrenceEndDate = orderCalender.RecurrenceEndDate;
                                otherOrderSchedules.Add(nonMedOrderSchedule);
                            }
                        }
                    }
                    else
                    {
                        DeliveryPeriod deliveryPeriod =
                            DeliveryPeriodsManager.DeliveryPeriods.FirstOrDefault(
                                p => p.Id == order.DeliveryPeriodId);
                        if (deliveryPeriod != null)
                        {
                            foreach (
                                DeliveryPeriodsTime deliveryPeriodsTimes in deliveryPeriod.DeliveryPeriodsTimes)
                            {
                                var nonMedOrderSchedule = new OtherOrderSchedule();
                                var recurrenceRange = new RecurrenceRange();
                                recurrenceRange.Start = new DateTime(DateTimeUtility.CurrentDateTime.Year, DateTimeUtility.CurrentDateTime.Month,
                                                                     DateTimeUtility.CurrentDateTime.Day,
                                                                     deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                         .
                                                                         Hours,
                                                                     deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                         .
                                                                         Minutes,
                                                                     deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                         .
                                                                         Seconds);
                                recurrenceRange.RecursUntil = new DateTime(DateTime.MaxValue.Year,
                                                                           DateTime.MaxValue.Month,
                                                                           DateTime.MaxValue.Day,
                                                                           deliveryPeriodsTimes.DeliveryTime.
                                                                               StartTime.
                                                                               Hours,
                                                                           deliveryPeriodsTimes.DeliveryTime.
                                                                               StartTime.
                                                                               Minutes,
                                                                           deliveryPeriodsTimes.DeliveryTime.
                                                                               StartTime.
                                                                               Seconds);

                                var recurrenceRule = new DailyRecurrenceRule(1, recurrenceRange);

                                if (deliveryPeriodsTimes.DeliveryTime.StartTime < DateTimeUtility.CurrentDateTime.TimeOfDay)
                                {
                                    recurrenceRange.Start = recurrenceRange.Start.AddDays(1);
                                }
                                nonMedOrderSchedule.ScheduleDate = recurrenceRange.Start;
                                nonMedOrderSchedule.RecurrencePattern = recurrenceRule.ToString();
                                nonMedOrderSchedule.RecurrenceEndDate = recurrenceRange.RecursUntil;
                                otherOrderSchedules.Add(nonMedOrderSchedule);
                            }
                        }
                    }

                    List<OtherOrderSchedule> orderedOtherOrderSchedules =
                        otherOrderSchedules.OrderBy(p => p.ScheduleDate).ToList();
                    foreach (OtherOrderSchedule orderedOtherOrderSchedule in orderedOtherOrderSchedules)
                    {
                        order.OtherOrder.OtherOrderSchedules.Add(orderedOtherOrderSchedule);
                    }
                    OrderRepository.Save();
                    if (order.OtherOrder != null)
                    {
                        TasksManager.AddOtherOrderTasks(order.OtherOrder);
                    }
                }
            }

            if (pharmacyOrder.PharmacyDeliveries.All(p => p.Status == (int)PharmacyDeliveryStatus.Accept)
                && pharmacyOrder.Quantity <= pharmacyOrder.PharmacyDeliveries.Sum(p => p.RecievedQuantity))
            {
                pharmacyOrder.Status = (int)PharmacyOrderStatus.Accept;
            }

            if (pharmacyOrder.Status == (int)PharmacyOrderStatus.SentToJail &&
                pharmacyOrder.PharmacyDeliveries.Sum(p => p.RecievedQuantity) < pharmacyOrder.Quantity)
            {
                pharmacyOrder.Status = (int)PharmacyOrderStatus.SentToJailPartialy;

                if (Configurations.AutoDelivery)
                {
                    decimal quantity = GetSelectedPharmacyOrderQuantityToDeliver(pharmacyOrder.Id,
                                                                                 order.Quantity.Value);
                    DeliverPharmacyOrder(pharmacyOrder.Id, order.MedicationId.Value, order.Quantity.Value,
                                         quantity);
                }
            }

            if (order.CurrentQuantity != orderCurrentQuantity)
            {
                var orderCurrentQuantityLog = new OrderCurrentQuantityLog();
                orderCurrentQuantityLog.CurrentQuantity = order.CurrentQuantity;
                orderCurrentQuantityLog.ModificationDate = DateTimeUtility.CurrentDateTime;
                orderCurrentQuantityLog.OrderId = order.Id;
                OrderCurrentQuantityLogRepository.Add(orderCurrentQuantityLog);
                OrderCurrentQuantityLogRepository.Save();
            }
        }

        public void AcceptAllPharmacyOrderIncaseDontRefill(int selectedPharmacyOrderId, Guid userId)
        {
            PharmacyOrder pharmacyOrder =
                PharmacyOrderRepository.All().FirstOrDefault(p => p.Id == selectedPharmacyOrderId);

            using (
                var transactionScope = new TransactionScope(TransactionScopeOption.Required,
                                                            CustomTransactionOptions.TransactionOption))
            {
                Order order = OrderRepository.All().FirstOrDefault(p => p.Id == pharmacyOrder.OrderId);

                foreach (PharmacyDelivery pharmacyDelivery in pharmacyOrder.PharmacyDeliveries)
                {
                    if (pharmacyDelivery.Status != (int)PharmacyDeliveryStatus.Accept)
                    {
                        pharmacyDelivery.IsDeleted = true;
                        pharmacyDelivery.Status = (int)PharmacyDeliveryStatus.Accept;
                        pharmacyDelivery.ApprovedDate = DateTimeUtility.CurrentDateTime;
                        pharmacyDelivery.ApprovedByUserId = userId;
                        if (pharmacyDelivery.RecievedQuantity == null)
                        {
                            pharmacyDelivery.RecievedQuantity = pharmacyDelivery.DeliveredQuantity;
                        }
                    }
                }

                if (order != null && order.StartDateTime == null)
                {
                    order.StartDateTime = DateTimeUtility.CurrentDateTime;

                    if (order.TaperId != null && order.TaperOrders.OrderBy(p => p.Id).First().StartDate == null)
                    {
                        DateTime orderStartDate = DateTimeUtility.CurrentDateTime;
                        TimeSpan startDateTime = orderStartDate.TimeOfDay;

                        if (order.OtherOrder != null)
                        {
                            order.OtherOrder.Stage = (int)OtherOrderStage.Scheduled_InProgress;
                        }

                        for (int qfdIndex = 0; qfdIndex < order.TaperOrders.Count; qfdIndex++)
                        {
                            QFD qfD = order.Taper.QFDs.OrderBy(p => p.Id).ToList()[qfdIndex];
                            // How Many Times Inmate take This Order In QFD
                            int numberOfDeliveryTimes = qfD.DeliveryPeriod.DeliveryPeriodsTimes.Count *
                                                        qfD.NumberOfDays;

                            // How Many Times Inmate take This Order In Day
                            int numberOfDeliveryTimesPerDay = qfD.DeliveryPeriod.DeliveryPeriodsTimes.Count;
                            int currentDeliveryTimeIndex = 0;
                            List<DeliveryPeriodsTime> deliveryPeriodsTimes =
                                qfD.DeliveryPeriod.DeliveryPeriodsTimes.OrderBy(
                                    p => p.DeliveryTime.StartTime).ToList();

                            if (qfdIndex == 0)
                            {
                                //the nearest delivery time of current time
                                DeliveryPeriodsTime deliveryPeriodsTime =
                                    qfD.DeliveryPeriod.DeliveryPeriodsTimes.OrderBy(
                                        p => p.DeliveryTime.StartTime).
                                        FirstOrDefault(p =>
                                                       ((p.DeliveryTime.StartTime - startDateTime).TotalMinutes > 0 &&
                                                        (p.DeliveryTime.EndTime - startDateTime).TotalMinutes > 0)) ??
                                    qfD.DeliveryPeriod.DeliveryPeriodsTimes.OrderBy(
                                        p => p.DeliveryTime.StartTime).First();

                                currentDeliveryTimeIndex = deliveryPeriodsTimes.IndexOf(deliveryPeriodsTime);

                                for (int interval = 0; interval < numberOfDeliveryTimes; interval++)
                                {
                                    if ((currentDeliveryTimeIndex % numberOfDeliveryTimesPerDay == 0 &&
                                         currentDeliveryTimeIndex != 0) || orderStartDate < DateTimeUtility.CurrentDateTime)
                                    {
                                        orderStartDate = orderStartDate.AddDays(1);
                                    }

                                    DeliveryTime deliveryTime = deliveryPeriodsTimes[
                                        currentDeliveryTimeIndex % numberOfDeliveryTimesPerDay].DeliveryTime;

                                    orderStartDate = new DateTime(orderStartDate.Year, orderStartDate.Month,
                                                                  orderStartDate.Day,
                                                                  deliveryTime.StartTime.Hours,
                                                                  deliveryTime.StartTime.Minutes, 0);

                                    if (orderStartDate < DateTimeUtility.CurrentDateTime)
                                    {
                                        orderStartDate = orderStartDate.AddDays(1);
                                    }

                                    if (interval == 0)
                                    {
                                        order.TaperOrders.ToList()[qfdIndex].StartDate =
                                            new DateTime(orderStartDate.Year,
                                                         orderStartDate.Month,
                                                         orderStartDate.Day,
                                                         deliveryTime.StartTime
                                                             .Hours,
                                                         deliveryTime.StartTime
                                                             .Minutes, 0);
                                    }
                                    if (interval == numberOfDeliveryTimes - 1)
                                    {
                                        order.TaperOrders.ToList()[qfdIndex].EndDate =
                                            new DateTime(orderStartDate.Year,
                                                         orderStartDate.Month,
                                                         orderStartDate.Day,
                                                         deliveryTime.EndTime.
                                                             Hours,
                                                         deliveryTime.EndTime.
                                                             Minutes, 0);
                                    }

                                    if (order.OtherOrder != null)
                                    {
                                        TimeSpan deliveryTimeStartTime = deliveryTime.StartTime;

                                        var nonMedOrderScheduleDate = new DateTime(orderStartDate.Year,
                                                                                   orderStartDate.Month,
                                                                                   orderStartDate.Day,
                                                                                   deliveryTimeStartTime.
                                                                                       Hours,
                                                                                   deliveryTimeStartTime.
                                                                                       Minutes, 0);

                                        var nonMedOrderSchedule = new OtherOrderSchedule();
                                        nonMedOrderSchedule.ScheduleDate = nonMedOrderScheduleDate;
                                        order.OtherOrder.OtherOrderSchedules.Add(nonMedOrderSchedule);
                                    }

                                    currentDeliveryTimeIndex++;
                                }
                            }
                            else
                            {
                                orderStartDate = orderStartDate.AddDays(1);
                                for (int interval = 0; interval < numberOfDeliveryTimes; interval++)
                                {
                                    if (currentDeliveryTimeIndex % numberOfDeliveryTimesPerDay == 0 &&
                                        currentDeliveryTimeIndex != 0)
                                    {
                                        orderStartDate = orderStartDate.AddDays(1);
                                    }

                                    DeliveryTime deliveryTime = deliveryPeriodsTimes[
                                        currentDeliveryTimeIndex % numberOfDeliveryTimesPerDay].
                                        DeliveryTime;

                                    if (interval == 0)
                                    {
                                        order.TaperOrders.ToList()[qfdIndex].StartDate =
                                            new DateTime(orderStartDate.Year,
                                                         orderStartDate.Month,
                                                         orderStartDate.Day,
                                                         deliveryTime.StartTime
                                                             .Hours,
                                                         deliveryTime.StartTime
                                                             .Minutes, 0);
                                    }
                                    if (interval == numberOfDeliveryTimes - 1)
                                    {
                                        order.TaperOrders.ToList()[qfdIndex].EndDate =
                                            new DateTime(orderStartDate.Year,
                                                         orderStartDate.Month,
                                                         orderStartDate.Day,
                                                         deliveryTime.EndTime.
                                                             Hours,
                                                         deliveryTime.EndTime.
                                                             Minutes, 0);
                                    }

                                    if (order.OtherOrder != null)
                                    {
                                        TimeSpan deliveryTimeStartTime = deliveryTime.StartTime;
                                        var nonMedOrderScheduleDate = new DateTime(orderStartDate.Year,
                                                                                   orderStartDate.Month,
                                                                                   orderStartDate.Day,
                                                                                   deliveryTimeStartTime.
                                                                                       Hours,
                                                                                   deliveryTimeStartTime.
                                                                                       Minutes, 0);

                                        var nonMedOrderSchedule = new OtherOrderSchedule();
                                        nonMedOrderSchedule.ScheduleDate = nonMedOrderScheduleDate;
                                        order.OtherOrder.OtherOrderSchedules.Add(nonMedOrderSchedule);
                                    }

                                    currentDeliveryTimeIndex++;
                                }
                            }
                        }

                        order.OrderEndDate = SystemOptionManager.IsNonQohMode()
                            ? null
                            : order.TaperOrders?.OrderBy(p => p.Id).LastOrDefault()?.EndDate;

                        OrderRepository.Save();
                        if (order.OtherOrder != null)
                        {
                            TasksManager.AddOtherOrderTasks(order.OtherOrder);
                        }
                    }
                    if (order.TaperId == null && order.OtherOrder != null && order.CreateNonMedOrder)
                    {
                        order.OtherOrder.Stage = (int)OtherOrderStage.Scheduled_InProgress;
                        var otherOrderSchedules = new List<OtherOrderSchedule>();

                        if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Calendar)
                        {
                            foreach (OrderCalender orderCalender in order.OrderCalenders)
                            {
                                var nonMedOrderSchedule = new OtherOrderSchedule();
                                nonMedOrderSchedule.ScheduleDate = orderCalender.Date;
                                nonMedOrderSchedule.RecurrencePattern = orderCalender.RecurrencePattern;
                                nonMedOrderSchedule.RecurrenceEndDate = orderCalender.RecurrenceEndDate;
                                otherOrderSchedules.Add(nonMedOrderSchedule);
                            }
                        }
                        else if (order.DeliveryPeriodId == (int)DeliveryPeriodType.Recurrence)
                        {
                            foreach (OrderCalender orderCalender in order.OrderCalenders)
                            {
                                if (otherOrderSchedules.Count(p =>
                                                              p.RecurrencePattern == orderCalender.RecurrencePattern) ==
                                    0)
                                {
                                    var nonMedOrderSchedule = new OtherOrderSchedule();
                                    nonMedOrderSchedule.ScheduleDate = orderCalender.Date;
                                    nonMedOrderSchedule.RecurrencePattern = orderCalender.RecurrencePattern;
                                    nonMedOrderSchedule.RecurrenceEndDate = orderCalender.RecurrenceEndDate;
                                    otherOrderSchedules.Add(nonMedOrderSchedule);
                                }
                            }
                        }
                        else
                        {
                            DeliveryPeriod deliveryPeriod =
                                DeliveryPeriodsManager.DeliveryPeriods.FirstOrDefault(
                                    p => p.Id == order.DeliveryPeriodId);
                            if (deliveryPeriod != null)
                            {
                                foreach (
                                    DeliveryPeriodsTime deliveryPeriodsTimes in deliveryPeriod.DeliveryPeriodsTimes)
                                {
                                    var nonMedOrderSchedule = new OtherOrderSchedule();
                                    var recurrenceRange = new RecurrenceRange();
                                    recurrenceRange.Start = new DateTime(DateTimeUtility.CurrentDateTime.Year, DateTimeUtility.CurrentDateTime.Month,
                                                                         DateTimeUtility.CurrentDateTime.Day,
                                                                         deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                             .
                                                                             Hours,
                                                                         deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                             .
                                                                             Minutes,
                                                                         deliveryPeriodsTimes.DeliveryTime.StartTime
                                                                             .
                                                                             Seconds);
                                    recurrenceRange.RecursUntil = new DateTime(DateTime.MaxValue.Year,
                                                                               DateTime.MaxValue.Month,
                                                                               DateTime.MaxValue.Day,
                                                                               deliveryPeriodsTimes.DeliveryTime.
                                                                                   StartTime.
                                                                                   Hours,
                                                                               deliveryPeriodsTimes.DeliveryTime.
                                                                                   StartTime.
                                                                                   Minutes,
                                                                               deliveryPeriodsTimes.DeliveryTime.
                                                                                   StartTime.
                                                                                   Seconds);

                                    var recurrenceRule = new DailyRecurrenceRule(1, recurrenceRange);

                                    if (deliveryPeriodsTimes.DeliveryTime.StartTime < DateTimeUtility.CurrentDateTime.TimeOfDay)
                                    {
                                        recurrenceRange.Start = recurrenceRange.Start.AddDays(1);
                                    }
                                    nonMedOrderSchedule.ScheduleDate = recurrenceRange.Start;
                                    nonMedOrderSchedule.RecurrencePattern = recurrenceRule.ToString();
                                    nonMedOrderSchedule.RecurrenceEndDate = recurrenceRange.RecursUntil;
                                    otherOrderSchedules.Add(nonMedOrderSchedule);
                                }
                            }
                        }

                        List<OtherOrderSchedule> orderedOtherOrderSchedules =
                            otherOrderSchedules.OrderBy(p => p.ScheduleDate).ToList();
                        foreach (OtherOrderSchedule orderedOtherOrderSchedule in orderedOtherOrderSchedules)
                        {
                            order.OtherOrder.OtherOrderSchedules.Add(orderedOtherOrderSchedule);
                        }
                        OrderRepository.Save();
                        if (order.OtherOrder != null)
                        {
                            TasksManager.AddOtherOrderTasks(order.OtherOrder);
                        }
                    }
                }

                if (pharmacyOrder.PharmacyDeliveries.All(p => p.Status == (int)PharmacyDeliveryStatus.Accept)
                    && pharmacyOrder.Quantity <= pharmacyOrder.PharmacyDeliveries.Sum(p => p.RecievedQuantity))
                {
                    pharmacyOrder.Status = (int)PharmacyOrderStatus.Accept;
                }

                if (pharmacyOrder.Status == (int)PharmacyOrderStatus.SentToJail &&
                    pharmacyOrder.PharmacyDeliveries.Sum(p => p.RecievedQuantity) < pharmacyOrder.Quantity)
                {
                    pharmacyOrder.Status = (int)PharmacyOrderStatus.SentToJailPartialy;
                }
                pharmacyOrder.IsDeleted = true;
                OrderRepository.Save();
                PharmacyOrderRepository.Save();
                transactionScope.Complete();
            }
        }

        public PharmacyDelivery GetNewPharmacyDelivery(int medId, int pharmacyOrderId, decimal quantityToDeliver, 
            PharmacyOrderStatus pharmacyOrderStatus)
        {
            return new PharmacyDelivery
            {
                DeliveredMedicationId = medId,
                PharmacyOrderId = pharmacyOrderId,
                DeliveredQuantity = quantityToDeliver,
                Status = (int)pharmacyOrderStatus,
                DeliveryDate = DateTimeUtility.CurrentDateTime,
            };
        }

        public PharmacyOrder GetNewPharmacyOrder(long orderId, decimal quantity, bool includePharmacyDelivery,
            PharmacyOrderStatus pharmacyOrderStatus)
        {
            var pharmacyOrder = new PharmacyOrder
            {
                OrderId = orderId,
                Quantity = quantity,
                Status = (int)pharmacyOrderStatus,
                CreationDate = DateTimeUtility.CurrentDateTime,
                PharmacyDeliveries = new EntityCollection<PharmacyDelivery>()
            };

            if (!includePharmacyDelivery) return pharmacyOrder;

            var order = GetOrderByIDWithInmateID(orderId);
            if (order?.MedicationId != null)
            {
                pharmacyOrder.PharmacyDeliveries.Add(GetNewPharmacyDelivery(order.MedicationId.Value, 0, 
                    quantity, pharmacyOrderStatus)); 
            }

            return pharmacyOrder;
        }

        public void UpdateRecievedQuantityByPharmacyDeliveryId(decimal? recievedQuantity, int pharmacyDeliveryId,
            string note, int? substituteMedicationId, string orderComment = null)
        {
            var pharmacyDelivery = PharmacyDeliveryRepository.All().FirstOrDefault(x => x.Id == pharmacyDeliveryId);
            if (pharmacyDelivery == null) return;

            pharmacyDelivery.RecievedQuantity = recievedQuantity;
            pharmacyDelivery.Notes = note;

            var order = pharmacyDelivery.PharmacyOrder?.Order;
            if (substituteMedicationId.HasValue && order != null)
            {
                order.OrigMedicationId = order.MedicationId;
                order.MedicationId = substituteMedicationId.Value;
                if (!string.IsNullOrWhiteSpace(orderComment))
                {
                    order.Other = (order.Other?.Length ?? 0) == 0 ? orderComment : $"{order.Other}{Environment.NewLine}{orderComment}";
                }
                pharmacyDelivery.DeliveredMedicationId = substituteMedicationId.Value;
            }
            PharmacyDeliveryRepository.Save();
        }

        public void UpdateMedicationRecievedQuantity(decimal recievedQuantity, string rxo, bool canRxoBeRxNumber)
        {
            PharmacySubmissionResponse pharmacyResponse = null;

            var pharmacyType = SystemOptionManager.GetPharmacyType().ToEnum(PharmacyTypes.Legacy);
            if (canRxoBeRxNumber && pharmacyType != PharmacyTypes.Legacy)
            {
                pharmacyResponse = GetActivePharmacyResponseByRxNumberOrRxo(rxo);
                if (pharmacyResponse?.Order == null) return;

                rxo = pharmacyResponse.Order.RXO;
            }

            var pharmacyDelivery = PharmacyDeliveryRepository.All()
                .FirstOrDefault(p => p.Status != (int)PharmacyOrderStatus.Accept && p.PharmacyOrder.Order.RXO == rxo);

            if (pharmacyDelivery != null)
            {
                pharmacyDelivery.RecievedQuantity = recievedQuantity;
                PharmacyDeliveryRepository.Save();
            }
            else if (pharmacyType != PharmacyTypes.Legacy && pharmacyResponse?.Order != null)
            {
                var pharmacyOrder = GetNewPharmacyOrder(pharmacyResponse.OrderId, recievedQuantity, true, PharmacyOrderStatus.SentToJail);
                PharmacyOrderRepository.Add(pharmacyOrder);
                PharmacyOrderRepository.Save();
            }
        }

        public int GetNumberOfNotAcceptDelivery(int id)
        {
            return PharmacyOrderRepository.All().First(p => p.Id == id).PharmacyDeliveries.Count(
                p => p.Status != (int)PharmacyDeliveryStatus.Accept);
        }

        public DateTime GetLastPharmcyReqDateByOrderid(long orderId)
        {
            return
                PharmacyOrderRepository.All().Where(p => p.OrderId == orderId).Select(p => p.CreationDate).
                    OrderByDescending(p => p).FirstOrDefault();
        }

        public RxoDetails GetRxoDetail(string rxo, bool forActivePharmacyOrderOnly = true)
        {
            PharmacySubmissionResponse pharmacyResponse = null;

            var pharmacyType = SystemOptionManager.GetPharmacyType().ToEnum(PharmacyTypes.Legacy);
            if (pharmacyType != PharmacyTypes.Legacy)
            {
                pharmacyResponse = GetActivePharmacyResponseByRxNumberOrRxo(rxo);
                if (pharmacyResponse?.Order == null) return null;

                rxo = pharmacyResponse.Order.RXO;
            }

            var lightPharmacyOrder = PharmacyOrderRepository.GetLightPharmacyOrderByRxo(rxo, DateTimeUtility.CurrentDateTime)
                ?.FirstOrDefault(x => !forActivePharmacyOrderOnly || x.IsValid);
            if (lightPharmacyOrder == null) return null;

            lightPharmacyOrder.ActivePharmacyResponse = pharmacyResponse;
            return GetRxoDetail(lightPharmacyOrder, pharmacyType);
        }

        public RxoDetails GetRxoDetail(LightPharmacyOrder pharmacyOrder, PharmacyTypes pharmacyType)
        {
            if (string.IsNullOrWhiteSpace(pharmacyOrder.InmateFullLocation) && pharmacyOrder.InmateLocationId.HasValue)
            {
                var facilityLevel = SystemOptionManager.GetValue<int>(SystemOptionsField.FacilityLevel);
                pharmacyOrder.InmateFullLocation = LocationsManager.GetFullLocation(facilityLevel,
                    pharmacyOrder.InmateLocationId.Value);
            }

            if (pharmacyType != PharmacyTypes.Legacy)
            {
                var order = pharmacyOrder.ActivePharmacyResponse.Order;

                return new RxoDetails
                {
                    OrderRxo = pharmacyOrder.Rxo,
                    Rxo = pharmacyOrder.ActivePharmacyResponse.RxdRxNumber,
                    QuantityValue = IsPillMed(pharmacyOrder.ActivePharmacyResponse.Form) 
                        ? Convert.ToDecimal(pharmacyOrder.ActivePharmacyResponse.DispensedQuantity)
                        : order.Quantity ?? pharmacyOrder.Quantity,
                    ReceivedQuantity = pharmacyOrder.RecievedQuantity ?? 0,
                    Inmate = pharmacyOrder.InmateFullName,
                    Medication = $"{pharmacyOrder.TaperName} {(order?.Medication.MedicationCode != pharmacyOrder.ActivePharmacyResponse.NdcCode && order?.Medication.Name.ToUpper() != pharmacyOrder.ActivePharmacyResponse.SubstitutedMedicationName?.ToUpper() ? $"<br />({pharmacyOrder.ActivePharmacyResponse.SubstitutedMedicationName})" : string.Empty)}",
                    Info = string.Join(" ", new List<string>
                    {
                        pharmacyOrder.SourceTypeText,
                        pharmacyOrder.Others,
                        pharmacyOrder.InmateMedAllergies,
                        pharmacyOrder.DiscontinuedString
                    }
                        .Where(p => !string.IsNullOrWhiteSpace(p))),
                    Ordered = (int)pharmacyOrder.Quantity,
                    ReqDate = pharmacyOrder.ActualOrderedDate.ToDateTimeString(),
                    Rlsd = pharmacyOrder.IsInmateReleased,
                    IsDiscontinued = pharmacyOrder.IsDiscontinued,
                    InmateFullLocation = pharmacyOrder.InmateFullLocation,
                    ShowMedOrderSyncPopup = CanSyncMedOrderFromPharmacyInterface(pharmacyOrder.ActivePharmacyResponse.Id),
                    PharmacyResponseId = pharmacyOrder.ActivePharmacyResponse.Id
                };
            }
            else
            {
                return new RxoDetails
                {
                    OrderRxo = pharmacyOrder.Rxo,
                    Rxo = pharmacyOrder.Rxo,
                    QuantityValue = pharmacyOrder.LastRecievedQuantity.HasValue && pharmacyOrder.IsValid
                        ? pharmacyOrder.LastRecievedQuantity.Value
                        : (pharmacyOrder.RecievedQuantity.HasValue
                            ? Math.Max(pharmacyOrder.Quantity - pharmacyOrder.RecievedQuantity.Value, 0)
                            : pharmacyOrder.Quantity),
                    ReceivedQuantity = pharmacyOrder.RecievedQuantity ?? 0,
                    Inmate = pharmacyOrder.InmateFullName,
                    Medication = pharmacyOrder.TaperName,
                    Info = string.Join(" ", new List<string>
                    {
                        pharmacyOrder.SourceTypeText,
                        pharmacyOrder.Others,
                        pharmacyOrder.InmateMedAllergies,
                        pharmacyOrder.DiscontinuedString
                    }.Where(p => !string.IsNullOrWhiteSpace(p))
                        .Select(t => t)),
                    Ordered = (int)pharmacyOrder.Quantity,
                    ReqDate = pharmacyOrder.ActualOrderedDate.ToDateTimeString(),
                    Rlsd = pharmacyOrder.IsInmateReleased,
                    IsDiscontinued = pharmacyOrder.IsDiscontinued,
                    InmateFullLocation = pharmacyOrder.InmateFullLocation
                };
            }
        }

        private bool CanSyncMedOrderFromPharmacyInterface(int responseId)
        {
            var pharmacyResponse = PharmacySubmissionResponseRepository.All().FirstOrDefault(x => x.Id == responseId);
            if (pharmacyResponse == null) return false;

            //Should show only for first fill
            if (!IsNewFill(pharmacyResponse.Order)) return false;

            if (CanUpdateMedFromPharmacyInterface(pharmacyResponse)) return true;

            if (CanUpdateDoseFromPharmacyInterface(pharmacyResponse)) return true;

            return false;
        }

        private bool IsNewFill(Order order)
        {
            if (order == null) return false;
            if (order.PharmacyOrders.Any(x => x.PharmacyDeliveries.Any(y => (y.IsDeleted == null || y.IsDeleted == false) && y.Status == (int)PharmacyOrderStatus.Accept)))
            {
                return false;
            }
            return true;
        }

        public bool CanUpdateMedFromPharmacyInterface(PharmacySubmissionResponse pharmacyResponse)
        {
            if (pharmacyResponse == null) return false;

            var medication = pharmacyResponse.Order?.Medication;
            if (medication == null) return false;

            return medication.MedicationCode != pharmacyResponse.NdcCode && 
                medication.Name?.ToUpper() != pharmacyResponse.SubstitutedMedicationName?.ToUpper() && 
                !IsPillMed(pharmacyResponse?.Form);
        }

        public bool CanUpdateDoseFromPharmacyInterface(PharmacySubmissionResponse pharmacyResponse)
        {
            var order = pharmacyResponse?.Order;
            if (order == null) return false;

            return CanUpdateDoseFromPharmacyInterface(order.Dose, pharmacyResponse.Dose, pharmacyResponse.Form);
        }

        private bool CanUpdateDoseFromPharmacyInterface(double? existingDose, double newDose, string medForm)
        {
            return existingDose != newDose && IsPillMed(medForm);
        }

        public bool IsPillMed(string medForm)
        {
            if (string.IsNullOrWhiteSpace(medForm)) return false;

            medForm = medForm.ToUpper();

            var isPillMed = SystemOptionManager.GetDiamondPillMedCodes()
                .Split(new string[] { "," }, StringSplitOptions.RemoveEmptyEntries)
                .Select(x => x.Trim())
                .Any(x => x.ToUpper() == medForm);

            return isPillMed;
        }

        public bool IsPharmacyOrderFaxFileExist(int pharmacyOrderId)
        {
            var pharmacyOrder = PharmacyOrderRepository.All().Include(x => x.PharmacyOrderFax).FirstOrDefault(x => x.Id == pharmacyOrderId);
            if (pharmacyOrder == null || pharmacyOrder.PharmacyOrderFax == null) return false;
            return File.Exists(DocumentsManager.GetDocumentPath(Constants.SessionKeys.PharmacyOrderPrintFax, pharmacyOrder.PharmacyOrderFax.FileName));
        }

        public List<RxoDetails> GetRxoDetails(List<LightPharmacyOrder> pharmacyOrders)
        {
            if (pharmacyOrders == null) return null;

            var pharmacyType = SystemOptionManager.GetPharmacyType().ToEnum(PharmacyTypes.Legacy);

            return pharmacyType == PharmacyTypes.Legacy
                ? pharmacyOrders.Select(x => GetRxoDetail(x, pharmacyType)).ToList()
                : pharmacyOrders.Where(x => x.ActivePharmacyResponse != null)
                    .Select(x => GetRxoDetail(x, pharmacyType))
                    .ToList();
        }

        #endregion

        #region Pharmacy Interface

        public PharmacySubmission AddPharmacySubmission(long orderId, Guid userId, 
            PharmacySubmissionType pharmacySubmissionType)
        {
            var pharmacySubmission = new PharmacySubmission
            {
                OrderId = orderId,
                FileName = $"{Guid.NewGuid()}.hl7",
                Type = (byte) pharmacySubmissionType,
                UserId = userId,
                CreationDate = DateTimeUtility.CurrentDateTime
            };

            PharmacySubmissionRepository.Add(pharmacySubmission);
            PharmacySubmissionRepository.Save();

            return pharmacySubmission;
        }

        public void AddPharmacySubmissionResponse(PharmacySubmissionResponse response)
        {
            if (response == null) return;

            PharmacySubmissionResponseRepository.Add(response);
            PharmacySubmissionResponseRepository.Save();

            AddPharmacyResponseTrackingEvent(response.OrderId, null, PharmacySubmissionEventType.FillDispensed,
                $"Dispenesed Quantity: {response.DispensedQuantity}");
        }

        public void AddPharmacySubmissionEvent(string fileName, string pharmacyOrderId, long? orderId,
            PharmacySubmissionEventType eventType, PharmacySubRespUnknownOrder unknownPatientData, string note,
            bool isHidden, int? pharmacySubmissionId, int? medicinesSubstitutionLogId = null)
        {
            PharmacySubmissionEventRepository.Add(new PharmacySubmissionEvent
            {
                PharmacyOrderId = pharmacyOrderId,
                OrderId = !orderId.HasValue || orderId.Value <= 0 ? null : orderId,
                FileName = fileName,
                NonExistentPatientData = unknownPatientData == null ? null : JsonConvert.SerializeObject(unknownPatientData),
                EventType = (int)eventType,
                Notes = note,
                CreatedOn = DateTimeUtility.CurrentDateTime,
                PharmacySubmissionId = pharmacySubmissionId,
                IsHidden = isHidden,
                MedicinesSubstitutionLogId = medicinesSubstitutionLogId
            });
            PharmacySubmissionEventRepository.Save();
        }

        public PharmacySubmissionEvent GetPharmacySubmissionEventById(int id)
        {
            return PharmacySubmissionEventRepository.All().FirstOrDefault(x => x.Id == id);
        }

        public List<PharmacySubmissionEvent> GetPharmacySubmissionEvents(bool includeHidden, long? orderId)
        {
            var events = PharmacySubmissionEventRepository.All();

            if (!includeHidden)
            {
                events = events.Where(x => !x.IsHidden);
            }

            if (orderId.HasValue)
            {
                events = events.Where(x => x.OrderId == orderId);
            }

            return events.ToList();
        }

        public void HidePharmacySubmissionEvent(int eventId)
        {
            var pharmacyEvent = PharmacySubmissionEventRepository.All().FirstOrDefault(x => x.Id == eventId);
            if (pharmacyEvent == null) return;

            pharmacyEvent.IsHidden = true;
            PharmacySubmissionEventRepository.Save();
        }

        /// <summary>
        /// Sends order details to pharmacy.
        /// </summary>
        /// <param name="orderId"></param>
        /// <param name="discontinueDate">Send if discontinued</param>
        /// <param name="refillInProgress"></param>
        public void SendOrderToPharmacy(long orderId, DateTime? discontinueDate, bool refillInProgress)
        {
            var order = OrderRepository.All().FirstOrDefault(x => x.Id == orderId);
            if (order == null) return;

            SendOrderToPharmacy(order, order.PAF.Inmate, discontinueDate, refillInProgress);
        }

        /// <summary>
        /// Sends order details to pharmacy.
        /// </summary>
        /// <param name="order"></param>
        /// <param name="inmate"></param>
        /// <param name="discontinueDate">Send if discontinued</param>
        /// <param name="refillInProgress"></param>
        public void SendOrderToPharmacy(Order order, Inmate inmate, DateTime? discontinueDate, bool refillInProgress)
        {
            if (order?.PAF == null || inmate == null ||
                (order.CreateVerbalOrder == false && (order.PAF.SbarId.HasValue || order.PAF.BMSId.HasValue))) return;

            var currentUserId = SecurityManager.GetCurrentUserId();
            if (!currentUserId.HasValue) return;

            PharmacySubmissionType pharmacySubmissionType;
            PharmacySubmission pharmacySubmission;

            switch (SystemOptionManager.GetPharmacyType())
            {
                case (int)PharmacyTypes.Kalos:
                case (int)PharmacyTypes.Diamond:
                    if (discontinueDate.HasValue)
                        pharmacySubmissionType = PharmacySubmissionType.Cancel;
                    else if (order.ProfileOnly)
                        pharmacySubmissionType = PharmacySubmissionType.ProfileOnly;
                    else if (refillInProgress)
                        pharmacySubmissionType = PharmacySubmissionType.Refill;
                    else
                        pharmacySubmissionType = PharmacySubmissionType.NewFill;

                    pharmacySubmission = AddPharmacySubmission(order.Id, currentUserId.Value, pharmacySubmissionType);
                    if (pharmacySubmissionType != PharmacySubmissionType.Cancel && pharmacySubmissionType != PharmacySubmissionType.Discontinue)
                    {
                        GenerateAndUploadFileToPharmacy(pharmacySubmission);
                    }
                    else
                    {
                        CancelPharmacyOrder(pharmacySubmission);
                    }
                    break;
                default:
                    EmailsUtility.SendEmailToPharmacy(order, inmate, discontinueDate, refillInProgress, discontinueDate.HasValue);
                    break;
            }
        }

        public void GenerateAndUploadFileToPharmacy(int pharmacySubmissionId)
        {
            var pharmacySubmission = PharmacySubmissionRepository.All().FirstOrDefault(x => x.Id == pharmacySubmissionId);
            GenerateAndUploadFileToPharmacy(pharmacySubmission);
        }

        public void GenerateAndUploadFileToPharmacy(PharmacySubmission pharmacySubmission)
        {
            if (pharmacySubmission == null || pharmacySubmission.FilePlacedTime.HasValue) return;

            string filePath;
            try
            {
                var outputDirectory = SystemOptionManager.GetCipsTempOutFilesPath();
                if (!Directory.Exists(outputDirectory)) Directory.CreateDirectory(outputDirectory);

                filePath = PharmacyInterfaceManager.GenerateFile(pharmacySubmission, outputDirectory);
                AddPharmacyResponseTrackingEvent(pharmacySubmission.OrderId, pharmacySubmission.Id, 
                    PharmacySubmissionEventType.FileGenerated, null);

                UploadFileToPharmacy(pharmacySubmission, filePath);
            }
            catch (Exception ex)
            {
                AddPharmacySubmissionEvent(null, null, pharmacySubmission.OrderId, PharmacySubmissionEventType.ValidationFailed,
                    null, ex.Message, true, pharmacySubmission.Id);

                Logger.Instance.LogException($"An error occurred while generating/uploading the file to SFTP. Submission ID: {pharmacySubmission.Id}", ex);
                pharmacySubmission.IsFailed = true;
                PharmacySubmissionRepository.Save();
                return;
            }
        }

        private void UploadFileToPharmacy(PharmacySubmission pharmacySubmission, string filePath)
        {
            if (pharmacySubmission == null || pharmacySubmission.FilePlacedTime.HasValue || string.IsNullOrWhiteSpace(filePath)) return;

            try
            {
                FtpUtility.UploadFile($"{SystemOptionManager.GetCipsSftpInFolderPath()}/{pharmacySubmission.FileName}", filePath, true);
                pharmacySubmission.IsFailed = false;
                pharmacySubmission.FilePlacedTime = DateTimeUtility.CurrentDateTime;
                PharmacySubmissionRepository.Save();
                AddPharmacyResponseTrackingEvent(pharmacySubmission.OrderId, pharmacySubmission.Id,
                    PharmacySubmissionEventType.FileUploadedToSftp, null);
            }
            catch (Exception ex)
            {
                Logger.Instance.LogException($"An error occurred while generating/uploading the file to SFTP. Submission ID: {pharmacySubmission.Id}", ex);
                pharmacySubmission.IsFailed = true;
                PharmacySubmissionRepository.Save();
                AddPharmacyResponseTrackingEvent(pharmacySubmission.OrderId, pharmacySubmission.Id,
                    PharmacySubmissionEventType.UploadingFileToSftpFailed, null);
                return;
            }

            try
            {
                if (!Directory.Exists(_cipsProcessedHsFilesPath)) Directory.CreateDirectory(_cipsProcessedHsFilesPath);

                File.Move(filePath, $"{_cipsProcessedHsFilesPath}{Path.DirectorySeparatorChar}{pharmacySubmission.FileName}");
            }
            catch (Exception ex)
            {
                Logger.Instance.LogException($"CIPS: An error occurred while moving \"{pharmacySubmission.FileName}\" file to processed folder.", ex);
            }
        }

        public void CancelPharmacyOrder(PharmacySubmission pharmacySubmission)
        {
            if ((pharmacySubmission.Type == (int)PharmacySubmissionType.Cancel || pharmacySubmission.Type == (int)PharmacySubmissionType.Discontinue) && 
                pharmacySubmission.Order.OrderEndDate.HasValue &&
                pharmacySubmission.Order.OrderEndDate.Value <= DateTimeUtility.CurrentDateTime)
            {
                GenerateAndUploadFileToPharmacy(pharmacySubmission);
            }
        }

        public void UploadGeneratedFailedSubmissions()
        {
            if (SystemOptionManager.GetPharmacyType() == (int)PharmacyTypes.Legacy) return;

            var outFolderPath = SystemOptionManager.GetCipsTempOutFilesPath();
            if (!Directory.Exists(outFolderPath)) Directory.CreateDirectory(outFolderPath);

            if (!Directory.Exists(_cipsTempOutAckFilesPath)) Directory.CreateDirectory(_cipsTempOutAckFilesPath);
            if (!Directory.Exists(_cipsProcessedHsAckFilesPath)) Directory.CreateDirectory(_cipsProcessedHsAckFilesPath);

            var pharmacyType = SystemOptionManager.GetPharmacyType().ToEnum(PharmacyTypes.Legacy);

            //Upload failed med orders
            foreach (var pharmacySubmission in PharmacySubmissionRepository.All()
                .Where(x => x.FilePlacedTime == null &&
                            x.Type != (int)PharmacySubmissionType.Cancel &&
                            x.Type != (int)PharmacySubmissionType.Discontinue).ToList())
            {
                if (string.IsNullOrWhiteSpace(pharmacySubmission.FileName) ||
                    !File.Exists($"{outFolderPath}{Path.DirectorySeparatorChar}{pharmacySubmission.FileName}")) continue;

                var filePath = $"{outFolderPath}{Path.DirectorySeparatorChar}{pharmacySubmission.FileName}";
                UploadFileToPharmacy(pharmacySubmission, filePath);
            }

            //Upload acknowledgement messages
            foreach (var filePath in Directory.GetFiles(_cipsTempOutAckFilesPath))
            {
                //TODO: need to set Order ID in phase - 2 of Diamond work
                UploadAckMessage(filePath, SystemOptionManager.GetCipsSftpInFolderPath(), _cipsProcessedHsAckFilesPath, null);
            }
        }

        public void SubmitDiscontinuedOrders()
        {
            if (SystemOptionManager.GetPharmacyType() == (int)PharmacyTypes.Legacy) return;

            var pharmacyType = SystemOptionManager.GetPharmacyType().ToEnum(PharmacyTypes.Legacy);
            var currentTime = DateTimeUtility.CurrentDateTime;
            foreach (var pharmacySubmission in PharmacySubmissionRepository.All().Where(x => 
                (x.Type == (int)PharmacySubmissionType.Cancel || x.Type == (int)PharmacySubmissionType.Discontinue) && 
                !x.IsFailed &&
                x.FilePlacedTime == null && 
                x.Order.OrderEndDate.HasValue && x.Order.OrderEndDate.Value <= currentTime).ToList())
            {
                try
                {
                    CancelPharmacyOrder(pharmacySubmission);
                }
                catch (Exception ex)
                {
                    Logger.Instance.LogException($"{pharmacyType.GetDisplayName()}: Error notifying pharmacy of cancelled order.", ex);
                }
            }
        }

        public void ProcessResponseFiles()
        {
            var pharmacyType = SystemOptionManager.GetPharmacyType();
            if (pharmacyType == (int)PharmacyTypes.Legacy) return;

            var responses = PharmacyInterfaceManager.ProcessResponseFiles();
            var exceptionFileDirectory = SystemOptionManager.GetCipsExceptionFilesPath();

            if (!Directory.Exists(_cipsProcessedFilesPath)) Directory.CreateDirectory(_cipsProcessedFilesPath);
            if (!Directory.Exists(exceptionFileDirectory)) Directory.CreateDirectory(exceptionFileDirectory);
            if (!Directory.Exists(_cipsProcessedHsAckFilesPath)) Directory.CreateDirectory(_cipsProcessedHsAckFilesPath);

            var sftpInFolderPath = SystemOptionManager.GetCipsSftpInFolderPath();

            foreach (var response in responses)
            {
                if (response.Value == null || string.IsNullOrWhiteSpace(response.Value.MessageType))
                {
                    var fileName = FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);
                    Logger.Instance.LogException($"{pharmacyType.ToEnum<PharmacyTypes>()?.GetDisplayName()} Pharmacy Interface: Inlvalid File Format {fileName}",
                        new InvalidDataException($"Invalid File Format: {fileName}"));

                    continue;
                }
                else if (response.Value.MessageType?.ToLower() == Hl7MessageTypes.RDS.ToLower())
                {
                    ProcessRdsMessage(response, pharmacyType, _cipsProcessedFilesPath, exceptionFileDirectory);
                }
                else if (response.Value.MessageType?.ToLower() == Hl7MessageTypes.ORR.ToLower())
                {
                    ProcessOrrMessage(response, pharmacyType, _cipsProcessedFilesPath, exceptionFileDirectory);
                }
                GenerateAckMessage(response.Value, pharmacyType, sftpInFolderPath, _cipsProcessedHsAckFilesPath);
            }
        }

        private void ProcessRdsMessage(KeyValuePair<string, PharmacySubmissionResponse> response, int pharmacyType,
            string succeededFileDirectory, string exceptionFileDirectory)
        {
            var fileName = Path.GetFileName(response.Key);
            var pharmacyResponse = response.Value;
            Order order = null;
            try
            {
                using (var transaction = new TransactionScope(TransactionScopeOption.Required, CustomTransactionOptions.TransactionOption))
                {
                    var uniqueFileName = FileUtility.GetUniqueFileNameFromDirectory(succeededFileDirectory, fileName);

                    order = OrderRepository.All().FirstOrDefault(x => x.Id == pharmacyResponse.OrderId);
                    if (order == null)
                    {
                        LogPharmacyResponseException(pharmacyResponse, null, Path.GetFileName(response.Key), true,
                            PharmacySubmissionEventType.UnrecognizedMedOrder, null);
                        FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                        transaction.Complete();
                        return;
                    }
                    else if (order.PAF.Inmate.OffenderId != pharmacyResponse.InmateOffenderId)
                    {
                        LogPharmacyResponseException(pharmacyResponse, order.Id, Path.GetFileName(response.Key), true,
                            PharmacySubmissionEventType.OffenderIdNotMatched, null);
                        FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                        transaction.Complete();
                        return;
                    }
                    else if (string.IsNullOrWhiteSpace(pharmacyResponse.RxdRxNumber))
                    {
                        LogPharmacyResponseException(pharmacyResponse, order.Id, Path.GetFileName(response.Key), false,
                            PharmacySubmissionEventType.MissingRxNumber, null);
                        FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                        transaction.Complete();
                        return;
                    }
                    else if (PharmacySubmissionResponseRepository.All().Any(x => x.RxdRxNumber == pharmacyResponse.RxdRxNumber))
                    {
                        LogPharmacyResponseException(pharmacyResponse, order.Id, Path.GetFileName(response.Key), false,
                            PharmacySubmissionEventType.DuplicateRxNumber, null);
                        FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                        transaction.Complete();
                        return;
                    }

                    if (order.Dose != (int)DeliveryDoseType.AsDirected && pharmacyResponse.Dose != order.Dose && 
                        IsPillMed(pharmacyResponse.Form) && !IsNewFill(order))
                    {
                        LogPharmacyResponseException(pharmacyResponse, order.Id, Path.GetFileName(response.Key), false,
                            PharmacySubmissionEventType.UnitsUpdateRejected, "#Units can't be updated of ongoing order.");
                        FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                        transaction.Complete();
                        return;
                    }

                    var inmate = order.PAF?.Inmate;
                    if (inmate != null)
                    {
                        inmate.FirstName = pharmacyResponse.PatientFirstName ?? inmate.FirstName;
                        inmate.MiddleName = pharmacyResponse.PatientMiddleName ?? inmate.MiddleName;
                        inmate.LastName = pharmacyResponse.PatientLastName ?? inmate.LastName;
                        inmate.Sex = string.IsNullOrWhiteSpace(pharmacyResponse.PatientSex)
                            ? inmate.Sex
                            : pharmacyResponse.PatientSex.ToUpper()[0] == 'M';
                        inmate.DateOfBirth = pharmacyResponse.PatientDob ?? inmate.DateOfBirth;
                        OrderRepository.Save();
                    }

                    pharmacyResponse.FileName = uniqueFileName;
                    AddPharmacySubmissionResponse(pharmacyResponse);

                    FileUtility.MoveFile(response.Key, $"{succeededFileDirectory}{Path.DirectorySeparatorChar}{uniqueFileName}");

                    transaction.Complete();
                }
            }
            catch (Exception ex)
            {
                LogPharmacyResponseException(pharmacyResponse, order?.Id, Path.GetFileName(response.Key), false,
                    PharmacySubmissionEventType.PharmacyException, null);
                FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);

                Logger.Instance.LogException("An error occurred while finalizing the pharmacy response in the database.", ex);
            }
        }

        private void ProcessOrrMessage(KeyValuePair<string, PharmacySubmissionResponse> response, int pharmacyType,
            string succeededFileDirectory, string exceptionFileDirectory)
        {
            var pharmacyResponse = response.Value;
            if (pharmacyResponse == null) return;

            if (pharmacyResponse.AcknowledgementCode?.ToLower() == DiamondPharmacyAcknowledgementCodes.ApplicationAccept.ToLower())
            {
                if (pharmacyResponse.OrderControl?.ToLower() == DiamondPharmacyOrderControlCodes.StatusChange.ToLower())
                {
                    ProcessRdsMessage(response, pharmacyType, succeededFileDirectory, exceptionFileDirectory);
                }
                else
                {
                    var uniqueFileName = FileUtility.GetUniqueFileNameFromDirectory(succeededFileDirectory, Path.GetFileName(response.Key));
                    FileUtility.MoveFile(response.Key, $"{succeededFileDirectory}{Path.DirectorySeparatorChar}{uniqueFileName}");
                }
            }
            else
            {
                var eventType = pharmacyResponse.AcknowledgementCode?.ToLower() == DiamondPharmacyAcknowledgementCodes.ApplicationReject.ToLower()
                    ? PharmacySubmissionEventType.ApplicationRejected
                    : PharmacySubmissionEventType.ApplicationError;

                try
                {
                    var orderId = pharmacyResponse.OrderId == 0 ? (long?)null : pharmacyResponse.OrderId;
                    LogPharmacyResponseException(pharmacyResponse, orderId, Path.GetFileName(response.Key), true, eventType, 
                        $"{pharmacyResponse.ErrorMessage} (Message#: {pharmacyResponse.ResponseToMessageControlId})");
                    FileUtility.MoveFileWithUniqueName(response.Key, exceptionFileDirectory);
                }
                catch (Exception ex)
                {
                    var uniqueFileName = FileUtility.GetUniqueFileNameFromDirectory(exceptionFileDirectory, Path.GetFileName(response.Key));
                    var filePath = $"{exceptionFileDirectory}{Path.DirectorySeparatorChar}{uniqueFileName}";
                    FileUtility.MoveFile(response.Key, filePath);
                    Logger.Instance.LogException($"An error occurred while processing ORR response for RXO: {pharmacyResponse.OrderRxo}. File moved to: {filePath}", ex);
                }
            }
        }

        private void GenerateAckMessage(PharmacySubmissionResponse response, int pharmacyType, string sftpInFolderPath,
            string succeededFileDirectory)
        {
            if (pharmacyType == (int)PharmacyTypes.Diamond)
            {
                try
                {
                    if (!Directory.Exists(_cipsTempOutAckFilesPath)) Directory.CreateDirectory(_cipsTempOutAckFilesPath);

                    var fileName = $"{Guid.NewGuid()}.hl7";
                    var filePath = PharmacyInterfaceManager.GenerateAckFile(fileName, response.MessageControlId, _cipsTempOutAckFilesPath);
                    AddPharmacyResponseTrackingEvent(response.OrderId, null, PharmacySubmissionEventType.AckFileGenerated, null);

                    UploadAckMessage(filePath, sftpInFolderPath, succeededFileDirectory, response.OrderId);
                }
                catch (Exception ex)
                {
                    Logger.Instance.LogException($"An error occurred while generating ACK file. RXO: {response.OrderRxo}", ex);
                    AddPharmacyResponseTrackingEvent(response.OrderId, null, PharmacySubmissionEventType.AckFileGenerationFailed, null);
                }
            }
        }

        private void UploadAckMessage(string filePath, string sftpInFolderPath, string succeededFileDirectory, long? orderId)
        {
            string fileName = Path.GetFileName(filePath);
            try
            {
                FtpUtility.UploadFile($"{sftpInFolderPath}{Path.DirectorySeparatorChar}{fileName}", filePath, true);
                AddPharmacyResponseTrackingEvent(orderId, null, PharmacySubmissionEventType.AckFileUploadedToSftp, null);
                File.Move(filePath, $"{succeededFileDirectory}{Path.DirectorySeparatorChar}{fileName}");
            }
            catch (Exception ex)
            {
                Logger.Instance.LogException($"An error occurred while uploading ACK file to SFTP. File Name: {fileName}", ex);
                AddPharmacyResponseTrackingEvent(orderId, null, PharmacySubmissionEventType.UploadingAckFileToSftpFailed, null);
            }
        }

        private void LogPharmacyResponseException(PharmacySubmissionResponse pharmacyResponse, long? orderId, string fileName,
            bool logPatientData, PharmacySubmissionEventType eventType, string note, int? medicinesSubstitutionLogId = null)
        {
            var patientData = logPatientData && pharmacyResponse != null
                ? new PharmacySubRespUnknownOrder
                {
                    OffenderId = pharmacyResponse.InmateOffenderId,
                    OrderRxo = pharmacyResponse.OrderRxo,
                    FirstName = pharmacyResponse.PatientFirstName,
                    MiddleName = pharmacyResponse.PatientMiddleName,
                    LastName = pharmacyResponse.PatientLastName,
                    Dob = pharmacyResponse.PatientDob,
                    Gender = pharmacyResponse.PatientSex,
                    RxNumber = pharmacyResponse.RxdRxNumber
                }
                : null;

            AddPharmacySubmissionEvent(fileName, pharmacyResponse?.PharmacyOrderId, orderId,
                eventType, patientData, note, false, null, medicinesSubstitutionLogId);
        }

        private void AddPharmacyResponseTrackingEvent(long? orderId, int? pharmacySubmissionId,
            PharmacySubmissionEventType eventType, string note)
        {
            AddPharmacySubmissionEvent(null, null, orderId, eventType, null, note, true, pharmacySubmissionId);
        }

        public PharmacySubmissionResponse GetPharmacySubmissionResponseById(int id)
        {
            var pharmacySubmissionResponse = PharmacySubmissionResponseRepository.All().FirstOrDefault(x => x.Id == id);
            return pharmacySubmissionResponse;
        }

        public RxoDetails SyncOrderFromPharmacy(int pharmacySubmissionResponseId, int locationId,
            DateTime? startDate, DateTime? endDate, string selectedRxo, SyncOrderFromPharmacyVm syncOrderFromPharmacyVm)
        {
            if (!CanSyncMedOrderFromPharmacyInterface(pharmacySubmissionResponseId)) return null;

            using (var transaction = new TransactionScope(TransactionScopeOption.Required, CustomTransactionOptions.TransactionOption))
            {
                var pharmacyResponse = PharmacySubmissionResponseRepository.All().FirstOrDefault(x => x.Id == pharmacySubmissionResponseId);
                if (pharmacyResponse == null || pharmacyResponse.IsReceived) return null;

                var order = pharmacyResponse.Order;
                var oldSig = order.SIGText;
                
                //Update Dose
                if (order.Dose != (int)DeliveryDoseType.AsDirected && syncOrderFromPharmacyVm.NewUnits != order.Dose)
                {
                    order.Dose = syncOrderFromPharmacyVm.NewUnits;
                }

                //Update Quantity
                if (!order.Quantity.HasValue || order.Quantity.Value != Convert.ToDecimal(syncOrderFromPharmacyVm.AddToQoh))
                {
                    order.Quantity = Convert.ToDecimal(syncOrderFromPharmacyVm.AddToQoh);

                    var pharmacyOrder = order.PharmacyOrders.FirstOrDefault();
                    if (pharmacyOrder != null)
                    {
                        pharmacyOrder.Quantity = Convert.ToDecimal(order.Quantity);
                        var pharmacyDelivery = pharmacyOrder.PharmacyDeliveries.FirstOrDefault();
                        if (pharmacyDelivery != null)
                        {
                            pharmacyDelivery.DeliveredQuantity = Convert.ToDecimal(order.Quantity);
                        }
                    }

                    if (!IsPillMed(pharmacyResponse.Form))
                    {
                        LogPharmacyResponseException(pharmacyResponse, order.Id, null, false, PharmacySubmissionEventType.StrengthSubstitution, null);
                    }
                }

                //Update Medication
                if (syncOrderFromPharmacyVm.MedicationId.HasValue && order.MedicationId != syncOrderFromPharmacyVm.MedicationId)
                {
                    //Log substitutions
                    var newMedication = MedicationsManager.GetMedicationById(syncOrderFromPharmacyVm.MedicationId.Value);
                    pharmacyResponse.Order.MedicinesSubstitutionLogs.Add(new MedicinesSubstitutionLog
                    {
                        MedicationId = order.MedicationId.Value,
                        CreatedOn = DateTimeUtility.CurrentDateTime,
                        OldNdc = order.Medication.MedicationCode,
                        OldMedName = order.Medication.Name,
                        OldSig = oldSig,
                        NewNdc = newMedication?.MedicationCode,
                        NewMedName = newMedication?.Name,
                        NewSig = order.SIGText,
                        Comments = syncOrderFromPharmacyVm.Comments
                    });

                    order.OrigMedicationId = order.MedicationId;
                    order.MedicationId = syncOrderFromPharmacyVm.MedicationId;

                    PharmacySubmissionResponseRepository.Save();

                    LogPharmacyResponseException(pharmacyResponse, order.Id, null, false, PharmacySubmissionEventType.ReviewMedSubstitution, 
                        null, pharmacyResponse.Order.MedicinesSubstitutionLogs.FirstOrDefault()?.Id);
                }

                //Update Comment
                order.Other = syncOrderFromPharmacyVm.Comments;

                PharmacySubmissionResponseRepository.Save();

                var rxoDetails = ReceiveMedication(selectedRxo, pharmacyResponse.Order.PAF.InmateId, startDate, endDate,
                    locationId, syncOrderFromPharmacyVm.AddToQoh.TryParseDecimal() ?? 0);

                transaction.Complete();
                return rxoDetails;
            }
        }

        public List<string> GetReceivedPharmacyResponseRxNumbers(long orderId)
        {
            var rxNumbers = PharmacySubmissionResponseRepository.All()
                .Where(x => x.OrderId == orderId && x.IsReceived)
                .OrderBy(x => x.CreationDate)
                .Select(x => x.RxdRxNumber)
                .ToList();
            return rxNumbers;
        }

        public string GetFirstPharmacyResponseRxNumber(long orderId)
        {
            return PharmacySubmissionResponseRepository.All()
                .Where(x => x.OrderId == orderId)
                .OrderBy(x => x.CreationDate)
                .FirstOrDefault()?
                .RxdRxNumber;
        }

        public PharmacySubmissionResponse GetActivePharmacyResponseByRxNumberOrRxo(string rxNumber)
        {
            return PharmacySubmissionResponseRepository.All().FirstOrDefault(x => !x.IsReceived &&
                (x.RxdRxNumber == rxNumber || x.Order.RXO == rxNumber));
        }

        public RxoDetails ReceiveMedication(string selectedRxo, int? selectedInmateId,
            DateTime? startDate, DateTime? endDate, int selectedLocationId, decimal receivedQuantity)
        {
            var userId = SecurityManager.GetCurrentUserId();
            if (!userId.HasValue) return null;

            var rxoDetailsContainer = HttpContext.Current.Session[SessionKeys.RxoDetailsContainer] as List<RxoDetails>;

            var el = rxoDetailsContainer?.FirstOrDefault(x => x.Rxo == selectedRxo || x.OrderRxo == selectedRxo) ?? GetRxoDetail(selectedRxo);
            if (el == null || el.IsDiscontinued) return null;

            var excludedPharmacyRecievingPharmacyOrdersIds = (List<int>)HttpContext.Current.Session["ExcludedPharmacyRecieving"] ?? new List<int>();

            UpdateMedicationRecievedQuantity(receivedQuantity, selectedRxo, true);
            AcceptPharmacyOrder(selectedInmateId, startDate, endDate,
                selectedLocationId, userId.Value, excludedPharmacyRecievingPharmacyOrdersIds, selectedRxo, true);

            el.QuantityValue -= receivedQuantity;

            var pharmacyType = SystemOptionManager.GetPharmacyType();

            if (rxoDetailsContainer != null)
            {
                if (el.QuantityValue <= 0 || pharmacyType != (int)PharmacyTypes.Legacy)
                {
                    rxoDetailsContainer.Remove(el);
                }
            }

            if (pharmacyType != (int)PharmacyTypes.Legacy)
            {
                el.ReceivedQuantity += receivedQuantity + el.QuantityValue;
                el.QuantityValue = 0;   //Force set to let client side remove this RX# from list.
                AddProcessedRxoDetailsToTempCache(el);
            }

            HttpContext.Current.Session[SessionKeys.RxoDetailsContainer] = rxoDetailsContainer;
            return el;
        }

        private void AddProcessedRxoDetailsToTempCache(RxoDetails el)
        {
            var processedRxoes = HttpContext.Current.Session[SessionKeys.TempProcessedRxoDetailsContainer] as List<RxoDetails>;
            if (processedRxoes == null)
            {
                processedRxoes = new List<RxoDetails>();
            }

            processedRxoes.RemoveAll(x => x.Rxo == el.Rxo || x.OrderRxo == el.OrderRxo);
            processedRxoes.Add(el);
            HttpContext.Current.Session[SessionKeys.TempProcessedRxoDetailsContainer] = processedRxoes;
        }

        public void LinkPharmacyEventToMedOrder(int orderId, int pharmacyEventId, bool resendHl7File)
        {
            var pharmacyEvent = PharmacySubmissionEventRepository.All().FirstOrDefault(x => x.Id == pharmacyEventId);
            if (pharmacyEvent == null) return;

            var order = OrderRepository.All().FirstOrDefault(x => x.Id == orderId);
            if (order == null) return;

            pharmacyEvent.OrderId = orderId;

            if (resendHl7File)
            {
                ResendOrderToPharmacy(pharmacyEvent, order);
            }

            PharmacySubmissionEventRepository.Save();
        }

        public void ResendOrderToPharmacy(int pharmacyEventId)
        {
            var pharmacyEvent = PharmacySubmissionEventRepository.All().FirstOrDefault(x => x.Id == pharmacyEventId);
            if (pharmacyEvent?.Order == null) return;

            ResendOrderToPharmacy(pharmacyEvent, pharmacyEvent.Order);

            PharmacySubmissionEventRepository.Save();
        }

        private void ResendOrderToPharmacy(PharmacySubmissionEvent pharmacyEvent, Order order)
        {
            var discontinueDate = !order.OrderEndDate.HasValue || order.OrderEndDate.Value > DateTimeUtility.CurrentDateTime
                ? null
                : order.OrderEndDate;
            SendOrderToPharmacy(order, order.PAF.Inmate, discontinueDate, order.CurrentRefill != 0);

            var resentNote = $"Re-sent on: {DateTimeUtility.CurrentDateTime.ToDateTimeString()}";
            pharmacyEvent.Notes = string.IsNullOrWhiteSpace(pharmacyEvent.Notes)
                ? resentNote
                : $"{pharmacyEvent.Notes}{Environment.NewLine}{resentNote}";
            pharmacyEvent.HideResendAction = true;
        }

        #endregion

        #endregion

        #region Constructor

        public PharmacyManager(EFUnitOfWork unitOfWork = null)
        {
            _efUnitOfWork = unitOfWork;
        }

        #endregion
    }
}