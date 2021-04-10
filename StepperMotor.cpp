#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class StepperMotor {
public:
	int rotateToNearest(int, int, vector <int>);
};

int StepperMotor::rotateToNearest(int n, int current, vector <int> target) 
{
	int nt = target.size();
	vector<int> steps(nt);
	//printf("%d %d\n", sizeof(int), sizeof(long));
	long long stepMin = 100000000000LL;
	long long stepPlus, stepMinus;
	for (int i = 0; i < nt; i++)
	{
		target[i] = ((target[i]%n)+n)%n;
		if (current < target[i])
		{
			stepPlus = target[i] - current;
			stepMinus = current + (n-target[i]);
		}
		else
		{
			stepPlus = (n-current)+target[i];
			stepMinus = current-target[i];
		}
		stepMinus = -stepMinus;
		printf("%ld %ld %ld %ld %ld : %ld\n", n, stepPlus, stepMinus, current, target[i], stepMin);
		if (stepPlus <= (long long) abs((long double) stepMin))
		{
			stepMin = stepPlus;
		}
		if ((long long) abs((long double) stepMinus) < (long long) abs((long double) stepMin))
		{
			stepMin = stepMinus;
		}
	}
	return (int) stepMin;		
}

double test0() {
	int p0 = 10;
	int p1 = 0;
	int t2[] = {-2, -3, 4, 5, 6, 9999999};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StepperMotor * obj = new StepperMotor();
	clock_t start = clock();
	int my_answer = obj->rotateToNearest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int p0 = 2;
	int p1 = 314159;
	int t2[] = {10, 8, 6, 4, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StepperMotor * obj = new StepperMotor();
	clock_t start = clock();
	int my_answer = obj->rotateToNearest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int p0 = 1;
	int p1 = -2147483648;
	int t2[] = {-2147483648, -2147483648, 2147483647, 2147483647};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StepperMotor * obj = new StepperMotor();
	clock_t start = clock();
	int my_answer = obj->rotateToNearest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int p0 = 23;
	int p1 = 10;
	int t2[] = {64077, -567273, 105845, -279980, 35557,
-286190, -652879, -431665, -634870, -454044};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StepperMotor * obj = new StepperMotor();
	clock_t start = clock();
	int my_answer = obj->rotateToNearest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -11;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	int p0 = 1000000000;
	int p1 = 1403466951;
	int t2[] = {1233321992, 11423750, 1356595134, 1130863021, 1183514764,
1943494859, 1714480374, 1529875954, 1738756510, 1190153525};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StepperMotor * obj = new StepperMotor();
	clock_t start = clock();
	int my_answer = obj->rotateToNearest(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -46871817;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}

//Powered by [KawigiEdit]

int main() {
int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
