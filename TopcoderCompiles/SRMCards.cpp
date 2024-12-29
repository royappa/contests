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

class SRMCards {
public:
int maxTurns(vector <int> v) 
{
	sort(v.begin(), v.end());
	int n = v.size();
	int turns = 0;
	while (n > 0)
	{
		turns++;
		int minn = 1000000, minp = -1;
		for (int p = 0; p < n; p++)
		{
			int nbrs = 0;
			if (p > 0 && v[p-1] == v[p]-1)
				nbrs++;
			if (p < n-1 && v[p+1] == v[p]+1)
				nbrs++;
			if (nbrs < minn)
			{
				minn = nbrs;
				minp = p;
			}
		}
		if (minp > 0 && v[minp-1] == v[minp]-1)
		{
			v.erase(v.begin()+minp-1);
			minp--;
		}
		if (minp < n-1 && v[minp+1] == v[minp]+1)
		{
			v.erase(v.begin()+minp+1);
		}
		v.erase(v.begin()+minp);
		n = v.size();	
	}
			
	return turns;	
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {498, 499};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	int t0[] = {491, 492, 495, 497, 498, 499};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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

double test2() {
	int t0[] = {100, 200, 300, 400};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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

double test3() {
	int t0[] = {11, 12, 102, 13, 100, 101, 99, 9, 8, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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

double test4() {
	int t0[] = {118, 321, 322, 119, 120, 320};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
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

double test5() {
	int t0[] = {10, 11, 12, 13, 14, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	SRMCards * obj = new SRMCards();
	clock_t start = clock();
	int my_answer = obj->maxTurns(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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

