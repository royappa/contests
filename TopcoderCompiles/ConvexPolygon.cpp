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

class ConvexPolygon {
public:
double findArea(vector <int> x, vector <int> y) 
{
	double sum = 0;
	int n = x.size();
	for (int i = 0; i < n; i++)
	{
		sum += x[i]*y[(i+1)%n]-x[(i+1)%n]*y[i];
	}
	return abs(sum/2.0);		
}
};


//Powered by [KawigiEdit]
double test0() {
	int t0[] = {0,0,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ConvexPolygon * obj = new ConvexPolygon();
	clock_t start = clock();
	double my_answer = obj->findArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int t0[] = {-10000,-10000,10000,10000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10000,-10000,-10000,10000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ConvexPolygon * obj = new ConvexPolygon();
	clock_t start = clock();
	double my_answer = obj->findArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 4.0E8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int t0[] = {100,80,30,-30,-80,-100,-80,-30,30,80};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,58,95,95,58,0,-58,-95,-95,-58};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ConvexPolygon * obj = new ConvexPolygon();
	clock_t start = clock();
	double my_answer = obj->findArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 29020.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int t0[] = {-1646,-9172,-9830,-9802,-9749,-9474,-8668,-6832,120,8380,9338,9307,8042};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-9998,-8619,-7863,3976,4541,5975,8127,9500,9612,8734,5216,-9042,-9689};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ConvexPolygon * obj = new ConvexPolygon();
	clock_t start = clock();
	double my_answer = obj->findArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 3.55115104E8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int t0[] = {-6010,-7937,-8782,-9506,-9654,-9852,-9854,-9998,-9999,-9996,-9901,-9811,
-9444,-8798,-8580,-2085,6842,8339,9827,9946,9993,9959,9940,9855,9657,
8504,8262,7552,6326,5537,4723};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-9976,-9947,-9873,-9739,-9654,-8501,-8475,-5009,475,4926,7078,8673,9417,
9785,9820,9974,9986,9979,9862,9211,-5070,-6599,-7121,-8624,-8912,-9710,
-9766,-9863,-9914,-9941,-9962};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ConvexPolygon * obj = new ConvexPolygon();
	clock_t start = clock();
	double my_answer = obj->findArea(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 3.939960635E8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main(int argc, char **argv) {
	double time;
	bool errors = false;
	
	if (argc < 2 || atoi(argv[1]) == 0) {
		time = test0();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 1) {
		time = test1();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 2) {
		time = test2();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 3) {
		time = test3();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 4) {
		time = test4();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

