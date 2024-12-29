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

class BrokenMatches {
public:
int restoreLength(vector <int> lenA, vector <int> lenB, vector <int> lenC) 
{
	int a = accumulate(lenA.begin(), lenA.end(), 0);
	int b = accumulate(lenB.begin(), lenB.end(), 0);
	int c = accumulate(lenC.begin(), lenC.end(), 0);
	return (a+b+c)/lenA.size();	
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BrokenMatches * obj = new BrokenMatches();
	clock_t start = clock();
	int my_answer = obj->restoreLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 9;
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
	int t0[] = {1,5}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,8}
;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,1}
;
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BrokenMatches * obj = new BrokenMatches();
	clock_t start = clock();
	int my_answer = obj->restoreLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {5,3,3,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,2,6,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,4,1,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BrokenMatches * obj = new BrokenMatches();
	clock_t start = clock();
	int my_answer = obj->restoreLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int t0[] = {13,25,18,2,32};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {22,15,16,17,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8,26,17,21,17};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BrokenMatches * obj = new BrokenMatches();
	clock_t start = clock();
	int my_answer = obj->restoreLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 50;
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
	int t0[] = {21,36,4,18,28,29,14,30,32,7}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {20,36,9,4,18,37,17,7,11,50}
;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {13,19,3,15,24,9,26,35,22,6}
;
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	BrokenMatches * obj = new BrokenMatches();
	clock_t start = clock();
	int my_answer = obj->restoreLength(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 60;
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

