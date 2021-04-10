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

class InterestingParty {
public:
int bestInvitation(vector <string> first, vector <string> second) 
{
	map<string,int> interest;
	for (int i = 0; i < first.size(); i++)
	{
		interest[first[i]]++;
		interest[second[i]]++;
	}
	int m = 0;
	
	for (auto it = interest.begin(); it != interest.end(); it++)
	{
		if (it->second > m)
		{
			m = it->second;
		}
	}
	return m;	
}
};


//Powered by [KawigiEdit]
double test0() {
	string t0[] = {"fishing", "gardening", "swimming", "fishing"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"hunting", "fishing", "fishing", "biting"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	InterestingParty * obj = new InterestingParty();
	clock_t start = clock();
	int my_answer = obj->bestInvitation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"variety", "diversity", "loquacity", "courtesy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"talking", "speaking", "discussion", "meeting"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	InterestingParty * obj = new InterestingParty();
	clock_t start = clock();
	int my_answer = obj->bestInvitation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	string t0[] = {"snakes", "programming", "cobra", "monty"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"python", "python", "anaconda", "python"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	InterestingParty * obj = new InterestingParty();
	clock_t start = clock();
	int my_answer = obj->bestInvitation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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

double test3() {
	string t0[] = {"t", "o", "p", "c", "o", "d", "e", "r", "s", "i", "n", "g", "l", "e", "r",
 "o", "u", "n", "d", "m", "a", "t", "c", "h", "f", "o", "u", "r", "n", "i"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"n", "e", "f", "o", "u", "r", "j", "a", "n", "u", "a", "r", "y", "t", "w", 
 "e", "n", "t", "y", "t", "w", "o", "s", "a", "t", "u", "r", "d", "a", "y"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	InterestingParty * obj = new InterestingParty();
	clock_t start = clock();
	int my_answer = obj->bestInvitation(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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

