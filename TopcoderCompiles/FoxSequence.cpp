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

class FoxSequence {
public:

bool check(vector<int> &seq, int a, int b, int c, int d)
{
	if (seq[1]-seq[0] <= 0) return false;
	if (seq[a+1]-seq[a] >= 0) return false;
	if (b < c && seq[b] != seq[c]) return false;
	if (seq[c+1]-seq[c] <= 0) return false;
	if (seq[d+1]-seq[d] >= 0) return false;
	
	// 3
	for (int i = b+1; i <= c; i++)
	{
		if (seq[i] != seq[b]) return false;
	}
	bool first;
	int diff;
	// 1
	first = true;
	diff = 0;
	for (int i = 1; i <= a; i++)
	{
		if (first)
		{
			first = false;
			diff = seq[i]-seq[i-1];
			if (diff <= 0) return false;
		}
		else if (seq[i]-seq[i-1] != diff)
		{
			return false;
		}
	}
	// 2
	first = true;
	diff = 0;
	for (int i = a+1; i <= b; i++)
	{
		if (first)
		{
			first = false;
			diff = seq[i]-seq[i-1];
			if (diff >= 0) return false;
		}
		else if (seq[i]-seq[i-1] != diff)
		{
			return false;
		}
	}
	// 4
	first = true;
	diff = 0;
	for (int i = c+1; i <= d; i++)
	{
		if (first)
		{
			first = false;
			diff = seq[i]-seq[i-1];
			if (diff <= 0) return false;
		}
		else if (seq[i]-seq[i-1] != diff)
		{
			return false;
		}
	}	
	// 5
	first = true;
	diff = 0;
	int n = seq.size();
	for (int i = d+1; i <= n-1; i++)
	{
		if (first)
		{
			first = false;
			diff = seq[i]-seq[i-1];
			if (diff >= 0) return false;
		}
		else if (seq[i]-seq[i-1] != diff)
		{
			return false;
		}
	}	
	return true;		
}

string isValid(vector <int> seq) 
{
	int n = seq.size();
	for (int a = 0; a < n-1; a++)
	{
		for (int b = a+1; b < n-1; b++)
		{
			for (int c = b; c < n-1; c++)
			{
				for (int d = c+1; d < n-1; d++)
				{
					if (check(seq, a, b, c, d)) return "YES";
				}
			}
		}
	}
	return "NO";
}	
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {3,6,9,1,9,5,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int t0[] = {6,1,6}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	FoxSequence * obj = new FoxSequence();
	clock_t start = clock();
	string my_answer = obj->isValid(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

