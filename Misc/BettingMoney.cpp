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

class BettingMoney {
public:
int moneyMade(vector <int> a, vector <int> c, int r) 
{
	int again = 0, bgain = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (i != r)
		{
			again += a[i]*100;
		}
		else
		{
			bgain += c[i]*a[i];
		}
	}
	return again-bgain;
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {10,20,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {20,30,40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1;
	BettingMoney * obj = new BettingMoney();
	clock_t start = clock();
	int my_answer = obj->moneyMade(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3400;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int t0[] = {200,300,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10,10,10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 2;
	BettingMoney * obj = new BettingMoney();
	clock_t start = clock();
	int my_answer = obj->moneyMade(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 49000;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int t0[] = {100,100,100,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,5,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	BettingMoney * obj = new BettingMoney();
	clock_t start = clock();
	int my_answer = obj->moneyMade(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 29500;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int t0[] = {5000,5000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	BettingMoney * obj = new BettingMoney();
	clock_t start = clock();
	int my_answer = obj->moneyMade(p0, p1, p2);
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int t0[] = {100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	BettingMoney * obj = new BettingMoney();
	clock_t start = clock();
	int my_answer = obj->moneyMade(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1000;
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

