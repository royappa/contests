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

class Dating {
public:

bool done(string s)
{
	int n = s.size();
	int uc = 0, lc = 0;
	for (int i = 0; i < n; i++)
	{
		if (isupper(s[i])) uc++;
		if (islower(s[i])) lc++;
	}
	return (uc == 0 || lc == 0);
}

int getBest(string s, int p)
{
	int n = s.size();
	bool first = true;
	int q = -1;
	for (int i = 0; i < n; i++)
	{
		if (isupper(s[p]) == isupper(s[i])) continue;
		if (first || s[i] < s[q])
		{
			first = false;
			q = i;
		}
	}
	return q;
}

string dates(string s, int k) 
{
	string ret = "";
	int p = 0;
	while (!done(s))
	{
		// find the chooser
		int n = s.size();
		for (int i = 1; i <= k-1; i++)
		{
			p = (p+1)%n;
		}
		int q = getBest(s, p);	
		ret += " ";
		ret += s[p];
		ret += s[q];
		string t = "";
		for (int i = 0; i < n; i++)
		{
			if (i == p || i == q) continue;
			t += s[i];
		}
		if (q < p)
			p = p == n-1 ? 0 : p-1;
		else if (q == p+1)
			p = p == n-2 ? 0 : p;
		s = t;
	}
	return ret.substr(1);
}
				
};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "abXCd";
	int p1 = 2;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "bC dX";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "abXCd";
	int p1 = 8;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Xa dC";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "HGFhgfz";
	int p1 = 1;
	Dating * obj = new Dating();
	clock_t start = clock();
	string my_answer = obj->dates(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Hf Gg Fh";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

