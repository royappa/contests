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

class BoxLoader {
public:
int mostItems(int boxX, int boxY, int boxZ, int itemX, int itemY, int itemZ) 
{
	vector<int> v1, v2;
	v1.push_back(boxX); v1.push_back(boxY); v1.push_back(boxZ);
	v2.push_back(itemX); v2.push_back(itemY); v2.push_back(itemZ);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int m = 0;
	do
	{
		m = max(m, (v1[0]/v2[0])*(v1[1]/v2[1])*(v1[2]/v2[2]));
	}
	while (next_permutation(v2.begin(), v2.end()));
	return m;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 100;
	int p1 = 98;
	int p2 = 81;
	int p3 = 3;
	int p4 = 5;
	int p5 = 7;
	BoxLoader * obj = new BoxLoader();
	clock_t start = clock();
	int my_answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 7560;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int p0 = 10;
	int p1 = 10;
	int p2 = 10;
	int p3 = 9;
	int p4 = 9;
	int p5 = 11;
	BoxLoader * obj = new BoxLoader();
	clock_t start = clock();
	int my_answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int p0 = 201;
	int p1 = 101;
	int p2 = 301;
	int p3 = 100;
	int p4 = 30;
	int p5 = 20;
	BoxLoader * obj = new BoxLoader();
	clock_t start = clock();
	int my_answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 100;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int p0 = 913;
	int p1 = 687;
	int p2 = 783;
	int p3 = 109;
	int p4 = 93;
	int p5 = 53;
	BoxLoader * obj = new BoxLoader();
	clock_t start = clock();
	int my_answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 833;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int p0 = 6;
	int p1 = 5;
	int p2 = 4;
	int p3 = 3;
	int p4 = 2;
	int p5 = 1;
	BoxLoader * obj = new BoxLoader();
	clock_t start = clock();
	int my_answer = obj->mostItems(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p6 = 20;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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

