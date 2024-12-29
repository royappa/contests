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

#define MOD  1000000007

using namespace std;

class VocaloidsAndSongs {
public:

int memo[51][51][51][51];

int f(int S, int a, int b, int c)
{
	if (S == 0)
	{
		return a+b+c==0?1:0;
	}
	else if (a+b+c == 0)
		return 0;
		
	int &r = memo[S][a][b][c];
	if (r != -1)
		return r;
	r = 0;
	if (a >= 1)
		r = (r+f(S-1, a-1, b, c))%MOD;
	if (b >= 1)
		r = (r+f(S-1, a, b-1, c))%MOD;
	if (c >= 1)
		r = (r+f(S-1, a, b, c-1))%MOD;
	if (a >=1 && b >= 1)
		r = (r+f(S-1, a-1, b-1, c))%MOD;
	if (a >= 1 && c >= 1)
		r = (r+f(S-1, a-1, b, c-1))%MOD;
	if (b >= 1 && c >= 1)
		r = (r+f(S-1, a, b-1, c-1))%MOD;
	if (a >= 1 && b >= 1 && c >= 1)
		r = (r+f(S-1, a-1, b-1, c-1))%MOD;
	return r;

}

int count(int S, int a, int b, int c) 
{
	memset(memo, -1, sizeof(memo));
	return f(S, a, b, c);	
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 1;
	int p3 = 1;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
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

double test1() {
	int p0 = 3;
	int p1 = 3;
	int p2 = 1;
	int p3 = 1;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 9;
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
	int p0 = 50;
	int p1 = 10;
	int p2 = 10;
	int p3 = 10;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
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

double test3() {
	int p0 = 18;
	int p1 = 12;
	int p2 = 8;
	int p3 = 9;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 81451692;
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

double test4() {
	int p0 = 50;
	int p1 = 25;
	int p2 = 25;
	int p3 = 25;
	VocaloidsAndSongs * obj = new VocaloidsAndSongs();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 198591037;
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

