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

class MagicSquare {
public:
	int missing(vector <int> s) 
	{
		int a[3][3];
		int mr, mc, i = 0;
		for (int r = 0; r < 3; r++)
		{
			for (int c = 0; c < 3; c++)
			{
				a[r][c] = s[i];
				if (s[i] == -1)
				{
					mr = r;
					mc = c;
				}
				i++;
			}
		}
		int x = (mr+1)%3;
		int sum = a[x][0]+a[x][1]+a[x][2];
		int sum2 = a[mr][0]+a[mr][1]+a[mr][2]+1;
		return sum-sum2;
	}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = { 8, 1, 6, 3, 5, -1, 4, 9, 2 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MagicSquare * obj = new MagicSquare();
	clock_t start = clock();
	int my_answer = obj->missing(p0);
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

double test1() {
	int t0[] = { -1, 1, 6, 3, 5, 7, 4, 9, 2 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MagicSquare * obj = new MagicSquare();
	clock_t start = clock();
	int my_answer = obj->missing(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	int t0[] = { 5, 15, 13, 19, 11, 3, 9, 7, -1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	MagicSquare * obj = new MagicSquare();
	clock_t start = clock();
	int my_answer = obj->missing(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 17;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

