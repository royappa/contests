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

class PunctuationCleaner {
public:
string clearExcess(string s) 
{
	int n = s.size();
	string t = "";
	bool punc = false;
	int ne = 0, nq = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '?' || s[i] == '!')
		{
			punc = true;
			if (s[i] == '?')
				nq++;
			else
				ne++;
		}
		else
		{
			if (punc)
			{
				punc = false;
				if (nq > 0)
					t += "?";
				else
					t += "!";
				punc = false;
				ne = 0;
				nq = 0;
			}
			t += s[i];
		}
	}
	if (punc)
		t += (nq > 0) ? "?" : "!";
	return t; 	
}
};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "This cheese is really great!!!!!";
	PunctuationCleaner * obj = new PunctuationCleaner();
	clock_t start = clock();
	string my_answer = obj->clearExcess(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "This cheese is really great!";
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
	string p0 = "You really like THIS cheese!?!?!?!!!?";
	PunctuationCleaner * obj = new PunctuationCleaner();
	clock_t start = clock();
	string my_answer = obj->clearExcess(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "You really like THIS cheese?";
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
	string p0 = " !!?X! ?? This is delicious!!! ??!a!?!";
	PunctuationCleaner * obj = new PunctuationCleaner();
	clock_t start = clock();
	string my_answer = obj->clearExcess(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = " ?X! ? This is delicious! ?a?";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

