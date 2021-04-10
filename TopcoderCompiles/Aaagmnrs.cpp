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

class Aaagmnrs {
public:

string fix(string s)
{
	string r = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (isupper(s[i]))
			s[i] = tolower(s[i]);
	}
	
	for (int i = 0; i < s.size(); i++)
	{
		if (!isalpha(s[i]) && !isdigit(s[i])) continue;
		r += s[i];
	}
	return r;
}

bool isAnagram(string s, string t)
{
	s = fix(s);
	t = fix(t);
	sort(s.begin(), s.end());
	sort(t.begin(), t.end());
	return s == t;
}

vector <string> anagrams(vector <string> v) 
{
	vector<string> r;
	r.push_back(v[0]);
	for (int i = 1; i < v.size(); i++)
	{
		bool flag = false;
		for (int j = 0; j < i; j++)
		{
			if (isAnagram(v[i], v[j]))
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			r.push_back(v[i]);
		}
	}
	return r;
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = { "Aaagmnrs", "TopCoder", "anagrams", "Drop Cote" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Aaagmnrs * obj = new Aaagmnrs();
	clock_t start = clock();
	vector <string> my_answer = obj->anagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "Aaagmnrs",  "TopCoder" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string t0[] = { "SnapDragon vs tomek", "savants groped monk", "Adam vents prongs ok" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Aaagmnrs * obj = new Aaagmnrs();
	clock_t start = clock();
	vector <string> my_answer = obj->anagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "SnapDragon vs tomek" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string t0[] = { "Radar ghost jilts Kim", "patched hers first",
  "DEPTH FIRST SEARCH", "DIJKSTRAS ALGORITHM" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Aaagmnrs * obj = new Aaagmnrs();
	clock_t start = clock();
	vector <string> my_answer = obj->anagrams(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "Radar ghost jilts Kim",  "patched hers first" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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

