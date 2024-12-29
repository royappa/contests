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

class Ordered {
public:
	string getType(vector <int>);
};

int gcd(int a, int b) { return b==0? a : gcd(b,a%b); }

string Ordered::getType(vector <int> v) 
{
	bool nonasc = true, nondesc = true, dupes = false;
	int n = v.size();
	for (int i = 1; i < n; i++)
	{
		if (nondesc) nondesc =v[i-1] <= v[i];
		if (nonasc) nonasc = v[i-1] >= v[i];
		if (v[i-1] == v[i]) dupes = true;
	}
	bool asc = nondesc && !dupes;
	bool desc = nonasc && !dupes;
	if (asc || desc)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			sum += v[i];
		}
		int g = gcd(sum, n);
		sum /= g;
		n /= g;

		char buf[100];
		sprintf(buf, "%s %d/%d", (asc ? "ASCENDING" : "DESCENDING"), sum, n);
		return buf;
	}
	if (nonasc || nondesc)
	{
		vector<int> freq(1001, 0);
		for (int i = 0; i < n; i++)
		{
			freq[v[i]]++;
		}
		int m = 0;
		for (int i = 0; i <= 1000; i++)
		{
			m = max(m, freq[i]);
		}
		char buf[100];
		sprintf(buf, "%s %d", (nonasc ? "NONASCENDING" : "NONDESCENDING"), m);
		return buf;
	}
	return "NOTHING";
}


double test0() {
	int t0[] = {1,2,4,11};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ASCENDING 9/2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {1,2,2,2,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NONDESCENDING 3";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {6,5,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "DESCENDING 4/1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int t0[] = {5,5,4,4,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NONASCENDING 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	int t0[] = {1,2,3,4,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NOTHING";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test5() {
	int t0[] = {1000,999,998};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "DESCENDING 999/1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test6() {
	int t0[] = {999,1000,1000,1000,1000,1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NONDESCENDING 5";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test7() {
	int t0[] = {1,1000,1,1000,1,1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NOTHING";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test8() {
	int t0[] = {1,2,3,4,5,6,7,8,9,10,
11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,51};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "ASCENDING 638/25";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test9() {
	int t0[] = {2,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NONASCENDING 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test10() {
	int t0[] = {1,2,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Ordered * obj = new Ordered();
	clock_t start = clock();
	string my_answer = obj->getType(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NONDESCENDING 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	time = test7();
	if (time < 0)
		errors = true;
	
	time = test8();
	if (time < 0)
		errors = true;
	
	time = test9();
	if (time < 0)
		errors = true;
	
	time = test10();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
