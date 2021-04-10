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

class TheLuckyGameDivTwo {
public:
bool lucky(int x)
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

int find(int a, int b, int jLen, int bLen)
{
	vector<int> v(5000);
	v[0] = 0;
	for (int i = 1; i < 5000; i++)
	{
		v[i] = v[i-1];
		if (lucky(i))
		{
			v[i]++;
		}
	}
	// number of luckies in [i,j] = v[i]-v[j-1]

	int mj = 0;
	for (int i = a; i+jLen-1 <= b; i++)
	{
		int ei = i+jLen-1;
		int mb = 1000000;
		for (int j = i; j+bLen-1 <= ei; j++)
		{
			int ej = j+bLen-1;
			int L = v[ej]-v[j-1];
			mb = min(L, mb);
		}
		mj = max(mb, mj);
	}
	return mj;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 1;
	int p1 = 10;
	int p2 = 2;
	int p3 = 1;
	TheLuckyGameDivTwo * obj = new TheLuckyGameDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int p0 = 1;
	int p1 = 100;
	int p2 = 100;
	int p3 = 100;
	TheLuckyGameDivTwo * obj = new TheLuckyGameDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int p0 = 4;
	int p1 = 8;
	int p2 = 3;
	int p3 = 2;
	TheLuckyGameDivTwo * obj = new TheLuckyGameDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int p0 = 1;
	int p1 = 100;
	int p2 = 75;
	int p3 = 50;
	TheLuckyGameDivTwo * obj = new TheLuckyGameDivTwo();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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

