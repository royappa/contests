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

class TheLuckyBasesDivTwo {
public:
typedef long long LL;

bool lucky(LL x)
{
	if (x == 0) return false;
	while (x)
	{
		int d = x%10;
		if (d != 4 && d != 7) return false;
		x /= 10;
	}
	return true;
}

void factorize(LL x, vector<LL> &v)
{
	for (LL d = 2; d*d <= x; d++)
	{
		if (x % d == 0) v.push_back(d);
		if (x % (x/d) == 0) v.push_back(x/d);
	}
	v.push_back(x);
}

bool luckyBase(LL n, LL B)
{
	while (n)
	{
		if (n%B != 4 && n%B != 7) return false;
		n /= B;
	}
	return true;
}

long long find(long long n)
{
	if (lucky(n)) return -1;

	if (n < 4) return 0;

	vector<LL> v;
	factorize(n-4, v); // all bases in which the last digit is 4
	factorize(n-7, v); // all bases in which the last digit is 7
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int r = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (luckyBase(n, v[i]))
			r++;
	}
	return r;
}
};


//Powered by [KawigiEdit]

double test0() {
	long long p0 = 255LL;
	TheLuckyBasesDivTwo * obj = new TheLuckyBasesDivTwo();
	clock_t start = clock();
	long long my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
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
	long long p0 = 4LL;
	TheLuckyBasesDivTwo * obj = new TheLuckyBasesDivTwo();
	clock_t start = clock();
	long long my_answer = obj->find(p0);
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	long long p0 = 13LL;
	TheLuckyBasesDivTwo * obj = new TheLuckyBasesDivTwo();
	clock_t start = clock();
	long long my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	long long p0 = 60LL;
	TheLuckyBasesDivTwo * obj = new TheLuckyBasesDivTwo();
	clock_t start = clock();
	long long my_answer = obj->find(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 2LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

