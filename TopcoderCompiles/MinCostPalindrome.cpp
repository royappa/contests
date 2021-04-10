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

class MinCostPalindrome {
public:

/*
bool isPal(string& s)
{
	int n = s.size();
	for (int i = 0; i < n/2; i++)
	{
		if (s[i] != s[n-i-1]) return false;
	}
	return true;
}
*/

int getMinimum(string s, int oCost, int xCost) 
{
	int n = s.size();
	// if a ? is matched with another ? in the opposite half then choose the lower cost letter, otherwise there is no choice
	
	int cost = 0;
	for (int i = 0; i < n/2; i++)
	{
		if (s[i] == '?' && s[n-i-1] == '?') cost += 2*min(oCost, xCost);
		else if (s[i] == '?' && s[n-i-1] != '?') cost += s[n-i-1] == 'o' ? oCost : xCost;
		else if (s[i] != '?' && s[n-i-1] == '?') cost += s[i] == 'o' ? oCost : xCost;
		else if (s[i] != s[n-i-1]) return -1;
	}
	return cost; 
	
	
	/* soln #1: dumb brute force way
	int mc = -1;
	string t = s;
	for (int m = 0; m < (1<<n); m++)
	{
		int c = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] != '?')
			{
				t[i] = s[i];
				continue;
			}
			else 
			{
				char ch = (m&(1<<i)) ? 'x' : 'o';
				t[i] = ch;
				c += ch == 'x' ? xCost : oCost;
			}	
		}
		if (isPal(t)  && (mc == -1 || c < mc))
		{
			mc = c;
		}		
	}
	return mc;
	*/
}
};


//Powered by [KawigiEdit]
double test0() {
	string p0 = "oxo?xox?";
	int p1 = 3;
	int p2 = 5;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 8;
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
	string p0 = "x??x";
	int p1 = 9;
	int p2 = 4;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 8;
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
	string p0 = "ooooxxxx";
	int p1 = 12;
	int p2 = 34;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	string p0 = "oxoxooxxxxooxoxo";
	int p1 = 7;
	int p2 = 4;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	string p0 = "?o";
	int p1 = 6;
	int p2 = 2;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 6;
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

double test5() {
	string p0 = "????????????????????";
	int p1 = 50;
	int p2 = 49;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 980;
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

double test6() {
	string p0 = "o??oxxo?xoox?ox??x??" ;
	int p1 = 3;
	int p2 = 10;
	MinCostPalindrome * obj = new MinCostPalindrome();
	clock_t start = clock();
	int my_answer = obj->getMinimum(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 38;
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
	
	if (argc < 2 || atoi(argv[1]) == 5) {
		time = test5();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 6) {
		time = test6();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

