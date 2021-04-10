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

bool lessThan(string a, string b)
{
	if (a.size() != b.size())
		return a.size() < b.size();
	return a < b;
}

class OneRegister {
public:

// order is * + - /

bool perfect_square(int t, int &root)
{
	root = (int)sqrt((double)t);
	if (root*root == t)
		return true;
	return false;
}

string f(int s, int t)
{
	if (s == t)
		return "";
	vector<string> ret;
	// suppose last operation was *, then t = x*x, where x=sqrt(t).
	int x;
	if (perfect_square(t,x))
	{
		if (s*s == t)
		{
			ret.push_back("*"); goto bot;
		}
		else if (t == 1)
		{
			ret.push_back("/"); goto bot;
		}
		string tmp = f(s,x);
		if (tmp == "BAD") goto bot;
		ret.push_back(tmp+"*"); goto bot;
	}
bot:
	// suppose last operation was +, then t = x+x, where x=t/2
	if (t%2 == 0)
	{
		if (s+s == t)
		{
			ret.push_back("+"); goto bot2;
		}
		string tmp = f(s,t/2);
		if (tmp == "BAD") goto bot2;
		ret.push_back(tmp+"+"); goto bot2;
	}
bot2:
	// suppose last was -, then t=0
	if (t == 0)
	{
		ret.push_back("-");
	}
	// suppose last was /, then t = 1
	if (t == 1)
	{
		ret.push_back("/");
	}
	if (ret.size() == 0)
		return "BAD";
	sort(ret.begin(), ret.end(), lessThan);
	return ret[0];
}

	
string getProgram(int s, int t) 
{
	string r = f(s, t);	
	return r == "BAD" ? ":-(" : r;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 7;
	int p1 = 392;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "+*+";
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
	int p0 = 7;
	int p1 = 256;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "/+***";
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
	int p0 = 4;
	int p1 = 256;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "**";
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
	int p0 = 7;
	int p1 = 7;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
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

double test4() {
	int p0 = 7;
	int p1 = 9;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = ":-(";
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

double test5() {
	int p0 = 10;
	int p1 = 1;
	OneRegister * obj = new OneRegister();
	clock_t start = clock();
	string my_answer = obj->getProgram(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "/";
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

