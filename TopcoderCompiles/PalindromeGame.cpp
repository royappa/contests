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

class PalindromeGame {
public:
vector<string> front;
vector<int> back;
int n;
typedef pair<int, pair<string,string> > keyType;
map<keyType,int> memo;

// return highest scoring word concatenation 
// such that the entire string left+subset(front p..n)+right is a palindrome
// return -2 if no palindrome is possible

bool isPal(string s)
{
	int len = s.size();
	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-i-1])
			return false;
	}
	return true;
}

int f(int p, string left, string right)
{
	if (p == n)
	{
		return isPal(left+right) ? 0 : -2;
	}
	keyType key = make_pair(p, make_pair(left,right));
	if (memo.count(key) > 0)
		return memo[key];
		
	// we have two options for front[p], we can attach it to left, or to right, and then recurse
		
	int res = -2;	

	if (isPal(left+front[p]+right))
	{
		res = back[p];
	}
		
	string L = left, R = right;
	L = L+front[p];
	while (L.size() > 0 && R.size() > 0 && L[0] == R[R.size()-1])
	{
		L = L.substr(1);
		R = R.substr(0,R.size()-1);
	}

	int resLeft = f(p+1, L, R);
	if (resLeft != -2)
		res = back[p]+resLeft;
	
	L = left;
	R = right;
	R = front[p]+R;
	while (L.size() > 0 && R.size() > 0 && L[0] == R[R.size()-1])
	{
		L = L.substr(1);
		R = R.substr(0,R.size()-1);
	}
	int resRight = -2;
	resRight = f(p+1, L, R);
	if (resRight != -2)
		res >?= back[p]+resRight;
	
	int resNone = f(p+1, left, right);
	if (resNone != -2)
		res >?= resNone;
		
	return memo[key] = res;	
}


int getMaximum(vector <string> front_, vector <int> back_) 
{
	front = front_;
	back = back_;
	n = front.size();
	
	int r = f(0, "", "");	
	return r == -2 ? 0 : r;
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = { "topcoder", "redcoder", "redocpot" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 7, 5, 3 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	string t0[] = { "rabbit" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 1000000 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = { "abc", "abc", "def", "cba", "fed" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int t1[] = { 24, 7, 63, 222, 190 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PalindromeGame * obj = new PalindromeGame();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 499;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

