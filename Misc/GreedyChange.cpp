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

class GreedyChange {
public:
	int smallest(vector <int>);
};

int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a % b);
}

int minCoins[25000010];

int greedy(int val, vector<int> den)
{
	int coins = 0;
	int n = den.size();
	for (int i = n-1; i >= 0; i--)
	{
		int k = val / den[i];
		coins += k;
		val -= k*den[i];
	}
	return coins;
}

int GreedyChange::smallest(vector <int> den) 
{
	int sum = 0;	
	for (int i = 0; i < den.size(); i++)
	{
		sum += den[i];
	}

	sort(den.begin(), den.end());
	

	minCoins[0] = 0;
	for (int v = 1; v <= sum; v++)
	{
		int best = sum+1;
		for (int i = 0; i < den.size(); i++)
		{
			if (v >= den[i])
			{
				best = min(best, minCoins[v-den[i]]);
			}
		}
		/*
		if (best + 1 < greedy(v, den))
		{
			return v;
		}	*/
		minCoins[v] = best + 1;	
		if (v%10000 == 0) cout << v << minCoins[v] << endl;
	}
	return -1;
}

double test0() {
	int t0[] = {1,25,10,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {1,3,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {1,10,10,20,25};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 30;
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
	int t0[] = {1,15,25};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 30;
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
	int t0[] = {1,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,
52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,500000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test5() {
	int t0[] = {500000,499999,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	GreedyChange * obj = new GreedyChange();
	clock_t start = clock();
	int my_answer = obj->smallest(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 999998;
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
