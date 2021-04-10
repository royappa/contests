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
#include <cstring>

using namespace std;

class PackingBallsDiv2 {
public:

int memo[101][101][101];

int f(int R, int G, int B)
{
	if (R+G+B == 0)
		return 0;
	else if (R+G+B == 1)
		return 1;
	else if (R+G+B == 2)
		return 1;
	int &r = memo[R][G][B];
	if (r != -1)
		return r;
	r = 1<<30;
	for (int t = 1; t <= 3; t++)
	{
		if (R >= t) 
			r = min(r, 1+f(R-t,G,B));
		if (G >= t)
			r = min(r, 1+f(R,G-t,B));
		if (B >= t)
			r = min(r, 1+f(R,G,B-t));
	}
	if (R >= 1 && G >= 1 && B >= 1)
		r = min(r, 1+f(R-1,G-1,B-1));
	if (R >= 1 && G >= 1)
		r = min(r, 1+f(R-1,G-1,B));
	if (R >= 1 && B >= 1)
		r = min(r, 1+f(R-1,G,B-1));
	if (G >= 1 && B >= 1)
		r = min(r, 1+f(R,G-1,B-1));

	return r;
}

	
	
int minPacks(int R, int G, int B) 
{
	memset(memo, -1, sizeof(memo));
	return f(R, G, B);	
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 4;
	int p1 = 2;
	int p2 = 4;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 1;
	int p1 = 7;
	int p2 = 1;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 2;
	int p1 = 3;
	int p2 = 5;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	int p0 = 78;
	int p1 = 53;
	int p2 = 64;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 66;
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

double test4() {
	int p0 = 100;
	int p1 = 100;
	int p2 = 100;
	PackingBallsDiv2 * obj = new PackingBallsDiv2();
	clock_t start = clock();
	int my_answer = obj->minPacks(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 100;
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

