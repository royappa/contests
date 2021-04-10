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

class TheBoringStoreDivTwo {
public:
string find(string J, string B) 
{
	int n = J.size(), m = B.size();
	set< pair<string,string> > J1, B1;
	for (int i = 0; i < n; i++)
	{
		for (int il = 1; i+il <= n; il++)
		{
			for (int j = i+il; j < n; j++)
			{
				for (int jl = 1; j+jl <= n; jl++)
				{
					J1.insert(make_pair(J.substr(i, il), J.substr(j, jl)));
				}
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int il = 1; i+il <= m; il++)
		{
			
			for (int j = i+il; j < m; j++)
			{
				for (int jl = 1; j+jl <= m; jl++)
				{
					B1.insert(make_pair(B.substr(i, il), B.substr(j, jl)));
				}
			}
		}
	}	
	
	string s = "";
	set<string> m;
	
	for (auto p1 : J1)
	{
		for (auto p2 : B1)
		{
			string A, B, C, D;
			A = p1.first;
			B = p1.second;
			C = p2.first;
			D = p2.second;
			if (A.size()+C.size() == B.size()+D.size() && A+C == B+D)
			{
				string t = A+C;
				if (t.size() > s.size() || (t.size() == s.size() && t < s))
				{
					m.clear();
					s = t;
					m.insert(s);
				}
			}
			swap(A, B);
			swap(C, D);
			if (A.size()+C.size() == B.size()+D.size() && A+C == B+D)
			{
				string t = A+C;
				if (t.size() > s.size() || (t.size() == s.size() && t < s))
				{
					m.clear();
					s = t;
					m.insert(s);
				}
			}			
		}
	}
	return s;
}

};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "StoreOfJohn";
	string p1 = "StoreOfBrus";
	TheBoringStoreDivTwo * obj = new TheBoringStoreDivTwo();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "or";
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
	string p0 = "JohnAndJohn";
	string p1 = "John";
	TheBoringStoreDivTwo * obj = new TheBoringStoreDivTwo();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "";
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
	string p0 = "JohnPlaysGames";
	string p1 = "BrusAlsoPlays";
	TheBoringStoreDivTwo * obj = new TheBoringStoreDivTwo();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "ays";
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

double test3() {
	string p0 = "abacaba";
	string p1 = "abacabadabacaba";
	TheBoringStoreDivTwo * obj = new TheBoringStoreDivTwo();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "abaabacaba";
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

