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

class FoxAverageSequence {
public:

int n;
vector<int> seq;
#define MOD 1000000007

int memo[41][1601][41][2];

int f(int p, int sum, int last, int incr)
{
	if (p == n)
		return 1;

	int& r = memo[p][sum][last][incr];
	if (r != -1)
		return r;
	
	r = 0;
	for (int i = 0; i <= 40; i++)
	{
		if (seq[p] != -1 && seq[p] != i) continue;
		if (p == 0 || i <= sum/p)
		{
			if (p < 2)
			{
				r = (r+f(p+1, sum+i, i, i >= last))%MOD;
			}
			else
			{
				if (incr)
				{
					r = (r+f(p+1, sum+i, i, i >= last))%MOD;
				}
				else if (i >= last)
				{
					r = (r+f(p+1, sum+i, i, 1))%MOD;
				}
			}
		}
	}
	return r;
}

int theCount(vector <int> seq_)
{
	seq = seq_;
	n = seq.size();
	memset(memo, -1, sizeof(memo));
	return f(0, 0, 0, 0);
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {3, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
	int t0[] = {5, 3, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	int t0[] = {-1, 0, 40};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	int t0[] = {-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 579347890;
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
	int t0[] = {-1, 12, 25, 0, 18, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxAverageSequence * obj = new FoxAverageSequence();
	clock_t start = clock();
	int my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 58;
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

