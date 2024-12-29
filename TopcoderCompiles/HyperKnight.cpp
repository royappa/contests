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

class HyperKnight {
public:

typedef long long LL;

void intersect(LL &x, LL &y, LL &z, LL &w, LL xx, LL yy, LL zz, LL ww)
{

}

void valid2(LL H, LL W, LL a, LL b, LL &x, LL &y, LL &z, LL &w)
{
	x = max(0, 0-a);
	y = max(0, 0-b);
	z = min(H, H-a);
	w = min(W, W-b);
}

void valid(LL H, LL W, LL a, LL b, LL &x, LL &y, LL &w, LL &z)
{
	LL xx, yy, zz, ww;
	valid2(H, W, a, b, xx, yy, zz, ww);
	if (x == -1)
	{
		x = xx; y = yy; z = zz; w = ww;
		return;
	}
	intersect(x, y, z, w, xx, yy, zz, ww);	
}

LL f(LL a, LL b, LL H, LL W, int m)
{
	LL d[] = {a,b, a,-b, -a,b, -a,-b, b,a, b,-a, -b,a, -b,-a};
	LL x, y, z, w;
	x = -1;
	
	for (int i = 0; i < 8; i++)
	{
		if ((m&(1<<8)) == 0) continue;
		valid(H, W, d[i*2], d[i*2+1], x, y, z, w);	
	}
	
	return (z-x)*(w-y);
}


long long countCells(int a, int b, int H, int W, int k) 
{
	LL num = 0;
	for (int m = 0; m < (1<<8); m++)
	{
		if (__builtin_popcount(m) == k)
		{
			num += f(a, b, H, W, m);
		}
	}
	return num;		
}

};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 8;
	int p3 = 8;
	int p4 = 4;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 20LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int p0 = 3;
	int p1 = 2;
	int p2 = 8;
	int p3 = 8;
	int p4 = 2;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 16LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int p0 = 1;
	int p1 = 3;
	int p2 = 7;
	int p3 = 11;
	int p4 = 0;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int p0 = 3;
	int p1 = 2;
	int p2 = 10;
	int p3 = 20;
	int p4 = 8;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 56LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int p0 = 1;
	int p1 = 4;
	int p2 = 100;
	int p3 = 10;
	int p4 = 6;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 564LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	int p0 = 2;
	int p1 = 3;
	int p2 = 1000000000;
	int p3 = 1000000000;
	int p4 = 8;
	HyperKnight * obj = new HyperKnight();
	clock_t start = clock();
	long long my_answer = obj->countCells(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p5 = 999999988000000036LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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

