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

class NCMultiplication {
public:
	long long findFactors(vector <int>);
};

typedef long long LL;
typedef vector<int> vi;

bool matches(LL f, LL f2, vi d)
{
	int n = d.size();
	vector<int> fd, f2d;

	while (f > 0)
	{
		fd.push_back(f%10LL);
		f /= 10LL;
	}
	while (f2 > 0)
	{
		f2d.push_back(f2%10LL);
		f2 /= 10LL;
	}
	vector<int> r(n,0);
	for (int i = 0; i < f2d.size(); i++)
	{
		for (int j = 0; j < fd.size(); j++)
		{
			r[j+i] += fd[j]*f2d[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (r[i] != d[i])
			return false;
	}
	return true;
}


long long NCMultiplication::findFactors(vector <int> digits)
{
	LL num = 0;

	for (int i = 0; i < digits.size(); i++)
	{
		num = 10*num+digits[i];
	}
	LL f = 2LL;
	LL mm = 100000000000000LL;
	LL bestA = -1LL;
	reverse(digits.begin(), digits.end());
	while (f*f <= num)
	{
		if (num % f == 0LL)
		{
			LL f2 = num / f;
			if (matches(f, f2, digits))
			{
				LL A = max(f, f2);
				LL B = min(f, f2);
				if (A-B < mm)
				{
					mm = A-B;
					bestA = A;
				}
			}
		}
		f++;
	}
	return bestA;
}


double test0() {
	int t0[] = {3,21,30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 36LL;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {15,3,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 512LL;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {4,20,25};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 25LL;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int t0[] = {6,61,124,129,90,27};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 6773LL;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	int t0[] = {8,14,22,95,125,120,73,9,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = -1LL;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test5() {
	int t0[] = {6, 5, 32, 68, 113, 143, 143, 124, 100, 75, 48, 23, 7, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	NCMultiplication * obj = new NCMultiplication();
	clock_t start = clock();
	long long my_answer = obj->findFactors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 65864431LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
