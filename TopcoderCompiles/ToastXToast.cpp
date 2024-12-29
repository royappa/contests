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

class ToastXToast {
public:
vector<int> u, v;
int n, m;
int memo[52][52][52];

// return true if there are k types of bread in u[0,p] and v[0,q]
int f(int k, int p, int q)
{
	if (k == 1)
	{
		return u[p] < v[0];
	}
	if (p == 0 || q == 0)
	{
		return 0;
	}
	int& r = memo[k][p][q];
	if (r != -1)
		return r;
	r = 0;
	if (u[p] < v[q])
	{
		r = f(k-1, p-1, q-1) || f(k, p-1, q) || f(k, p, q-1);
	}
	return r;
}


int bake(vector <int> uu, vector <int> vv)
{
	u = uu;
	v = vv;
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	n = u.size();
	m = v.size();

	for (int i = 1; i <= min(n,m); i++)
	{
		memset(memo, -1, sizeof(memo));
		if (f(i, n-1, m-1))
		{
			return i;
		}
	}
	return -1;
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {2,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,6,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	int t0[] = {5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
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

double test2() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,6,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
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

double test3() {
	int t0[] = {1,3,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,4,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	ToastXToast * obj = new ToastXToast();
	clock_t start = clock();
	int my_answer = obj->bake(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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

