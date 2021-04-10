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
#include <string.h>

using namespace std;

class BunnyComputer {
public:
int n, k;
vector<int> v;

int memo[51];

int f(int p)
{
	/* DP
	if (p >= n || p+k+1 >= n)
		return 0;
	int &r = memo[p];
	if (r != -1)
		return r;
	return r = max(v[p]+v[p+k+1]+f(p+2*(k+1)), f(p+k+1));
	*/
	// editorial
	int mn = 1<<30, count = 0, sum = 0;
	int x = 0;
	for (int i = p; i < n; i += k+1)
	{
		count++;
		sum += v[i];
		if (x%2 == 0)
			mn = min(mn, v[i]);
		x++;
	}
	return count%2 == 0 ? sum : sum-mn;
}

int getMaximum(vector <int> v_, int k_) 
{
	v = v_;
	n = v.size();
	k = k_;
	int r = 0;
	memset(memo, -1, sizeof(memo));
	
	for (int i = 0; i <= k; i++)
	{
		r += f(i);
	}
	return r;
}

};


//Powered by [KawigiEdit]
double test0() {
	int t0[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	BunnyComputer * obj = new BunnyComputer();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 28;
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
	int t0[] = { 3, 1, 4, 1, 5, 9, 2, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 1;
	BunnyComputer * obj = new BunnyComputer();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 31;
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
	int t0[] = { 1, 2, 3, 4, 5, 6 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	BunnyComputer * obj = new BunnyComputer();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 14;
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
	int t0[] = { 487, 2010 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	BunnyComputer * obj = new BunnyComputer();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

