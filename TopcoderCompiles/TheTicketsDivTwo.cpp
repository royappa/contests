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

class TheTicketsDivTwo {
public:
int m, n;
typedef long double LD;
int done[1100][11][11];
LD memo[1100][11][11];

// f(mask,rot,k) = probability that m'th friend is picked
// given that mask describes the remaining friends, and that they are rotated such that "rot" is the first in line
// the first friend in line may be eliminated

LD f(int mask, int rot, int k)
{
	if (done[mask][rot][k])
		return memo[mask][rot][k];

	// no friends left
	if (mask == 0)
		return 0.0;

	done[mask][rot][k] = 1;
	// find the first friend in line
	int q = rot;
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1<<q)) != 0)
		{
			break;
		}
		q = (q+1)%n;
	}
	if (__builtin_popcount(mask) == 1 || k == 0)
	{
		return memo[mask][rot][k] = q == m ? 1.0 : 0.0;
	}
	// 1,3,5  4   2,6
	LD p = 0.0;
	int newmask1 = mask;
	int t = (1<<q);
	int newmask2 = mask&(~t);

	if (q == m)
	{
		p = (1.0/6.0)+(3.0/6.0)*f(newmask1,(q+1)%n,k-1);
	}
	else
	{
		p = (3.0/6.0)*f(newmask1,(q+1)%n,k-1)+(2.0/6.0)*f(newmask2,(q+1)%n,k-1);
	}
	return memo[mask][rot][k] = p;
}

double find(int n_, int m_, int k)
{
	m = m_-1;
	n = n_;

	memset(done, 0, sizeof(done));
	return (double) f((1<<n)-1, 0, k);
}
};


//Powered by [KawigiEdit]
double test0() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 1;
	TheTicketsDivTwo * obj = new TheTicketsDivTwo();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.16666666666666666;
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
	int p0 = 2;
	int p1 = 1;
	int p2 = 2;
	TheTicketsDivTwo * obj = new TheTicketsDivTwo();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5833333333333334;
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
	int p0 = 7;
	int p1 = 7;
	int p2 = 4;
	TheTicketsDivTwo * obj = new TheTicketsDivTwo();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.0;
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
	int p0 = 4;
	int p1 = 2;
	int p2 = 10;
	TheTicketsDivTwo * obj = new TheTicketsDivTwo();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.25264033564814814;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

