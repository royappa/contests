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
#include <ext/hash_map>

using namespace std;
typedef struct
{
	int r, c;
} Dim;

typedef vector<Dim> vd;

// map from
hash_map<Dim,vd> memo;
vector<int> N, M;


class OrderDoesMatter {
public:


void f(int a, int b)
{
	if (a == b)
	{
		Dim x;
		x.r = a;
		x.c = b;
		vd vx;
		vx.push_back(x);
		memo[x] = vx;
		return;
	}
	
	Dim x;
	x.r = a;
	x.c = b;
	if (memo.count(x) > 0)
	{
		return;
	}
	
	// best way to multiply a..b
	
	int m = 0;
	for (int i = a; i < b; i++)
	{
		int j = a+1;
		f(a, i);
		// a..i, j..b
		x.r = a;
		x.c = i;
		vd vx = memo[x];
		for (int s = 0; s < vx.size(); s++)
		{
			f(j, b);
			Dim y;
			y.r = j;
			y.c = b;
			vd vy = memo[y];
			for (int t = 0; t < vy.size(); t++)
			{
				if (vx[s].c == vy[t].r)
				{
					Dim z;
					z.r = a;
					z.c = b;
					Dim zz;
					zz.r = vx[s].r;
					zz.c = vy[t].c;
					if (memo.count(z) == 0)
					{
						vd dummy;
						memo[z] = dummy;
					}
					memo[z].push_back(zz);
					m = max(m, zz.r*zz.c);
				}
			}
		}
	}
}

int getOrder(vector <int> N_, vector <int> M_) 
{
	N = N_;
	M = M_;
	int n = N.size();
	
	f(0, n-1);
	Dim x;
	x.r = 0;
	x.c = n-1;
	if (memo.count(x) == 0)
		return -1;
	int m = 0;
	vd vx = memo[x];
	for (int i = 0; i < vx.size(); i++)
	{
		m = max(m, vx[i].r*vx[i].c);
	}
	return m;
	
}

};


//Powered by [KawigiEdit]
double test0() {
	int t0[] = {7,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,7,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OrderDoesMatter * obj = new OrderDoesMatter();
	clock_t start = clock();
	int my_answer = obj->getOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 49;
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
	int t0[] = {3,5,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,1,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OrderDoesMatter * obj = new OrderDoesMatter();
	clock_t start = clock();
	int my_answer = obj->getOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {3,5,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,2,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OrderDoesMatter * obj = new OrderDoesMatter();
	clock_t start = clock();
	int my_answer = obj->getOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {5,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OrderDoesMatter * obj = new OrderDoesMatter();
	clock_t start = clock();
	int my_answer = obj->getOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OrderDoesMatter * obj = new OrderDoesMatter();
	clock_t start = clock();
	int my_answer = obj->getOrder(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
