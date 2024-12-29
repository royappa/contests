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

class PrintScheduler {
public:
	string getOutput(vector <string>, vector <string>);
};

string PrintScheduler::getOutput(vector <string> threads, vector <string> slices) 
{
	string ans = "";
	int nt = threads.size();
	vector<int> pos(nt, 0);
	for (int i = 0; i < slices.size(); i++)
	{
		string s = slices[i];
		int t, num;
		sscanf(s.c_str(), "%d %d", &t, &num);
		int p = pos[t];
		for (int j = 0; j < num; j++)
		{
			ans += threads[t][p];
			p = (p + 1) % threads[t].size();
		}
		pos[t] = p;
	}
	return ans;	
}

double test0() {
	string t0[] = {"AB","CD"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1","1 1","0 1","1 2"} ;
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PrintScheduler * obj = new PrintScheduler();
	clock_t start = clock();
	string my_answer = obj->getOutput(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "ACBDC";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"ABCDE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 20","0 21"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PrintScheduler * obj = new PrintScheduler();
	clock_t start = clock();
	string my_answer = obj->getOutput(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "ABCDEABCDEABCDEABCDEABCDEABCDEABCDEABCDEA";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"A","B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1 10","0 1","1 10","0 2"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PrintScheduler * obj = new PrintScheduler();
	clock_t start = clock();
	string my_answer = obj->getOutput(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "BBBBBBBBBBABBBBBBBBBBAA";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0 1"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	PrintScheduler * obj = new PrintScheduler();
	clock_t start = clock();
	string my_answer = obj->getOutput(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "A";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}

//Powered by [KawigiEdit]

int main() {
int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
