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

class AllButOneDivisor {
public:
int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(vector<int> &v, int m)
{
	int K = v.size();
	int t = 1;
	for (int i = 0; i < K; i++)
	{
		if ((m&(1<<i)) == 0) continue;
		t = (t*v[i])/gcd(t,v[i]);
	}
	return t;
}

bool eligible(vector<int> v, int t, int m)
{
	int K = v.size();
	for (int i = 0; i < K; i++)
	{
		if ((m&(1<<i)) != 0) continue;
		if (t%v[i] == 0) return false;
	}
	return true;
}

int getMinimum(vector <int> v)
{
	int K = v.size();
	int r = -1;
	for (int i = 0; i < (1<<K); i++)
	{
		if (__builtin_popcount(i) != K-1) continue;
		int t = lcm(v, i);
		if (eligible(v,t,i) && (r == -1 || t < r))
		{
			r = t;
		}
	}
	return r;
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {2,3,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AllButOneDivisor * obj = new AllButOneDivisor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int t0[] = {2,4,3,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AllButOneDivisor * obj = new AllButOneDivisor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int t0[] = {3,2,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AllButOneDivisor * obj = new AllButOneDivisor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int t0[] = {6,7,8,9,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AllButOneDivisor * obj = new AllButOneDivisor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 360;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int t0[] = {10,6,15};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	AllButOneDivisor * obj = new AllButOneDivisor();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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

