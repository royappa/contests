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

class AstronomicalRecordsEasy {
public:

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int minimalPlanets(vector <int> A, vector <int> B) 
{
	int g;
	g = A[0];
	for (int i = 0; i < A.size(); i++)
	{
		g = gcd(g, A[i]);
	}
	for (int i = 0; i < A.size(); i++)
	{
		A[i] /= g;
	}
	g = B[0];
	for (int i = 0; i < B.Size(); i++)
	{
		g = gcd(g, B[i]);
	}
	for (int i = 0; i < B.size(); i++)
	{
		B[i] /= g;
	}	
}

};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,4,6,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int t0[] = {1,2,3,5,6,8,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,4,5,6,7,8,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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
	int t0[] = {1,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6,7,8,9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int t0[] = {200,500};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {100,200,300,400,600,700,800,900};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 9;
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

double test5() {
	int t0[] = {1,2,3,4,5,6,7,8,9,10,11,12};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6,7,8,9,10,11,12,13,14,15};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	AstronomicalRecordsEasy * obj = new AstronomicalRecordsEasy();
	clock_t start = clock();
	int my_answer = obj->minimalPlanets(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 15;
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
	
	if (argc < 2 || atoi(argv[1]) == 5) {
		time = test5();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

