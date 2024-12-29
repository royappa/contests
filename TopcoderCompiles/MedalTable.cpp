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
	int g1, s1, b1, g2, s2, b2;
	sscanf(a.substr(4).c_str(), "%d %d %d", &g1, &s1, &b1);
	sscanf(b.substr(4).c_str(), "%d %d %d", &g2, &s2, &b2);

	if (g1 != g2)
		return g1 > g2;
	if (s1 != s2)
		return s1 > s2;
	if (b1 != b2)
		return b1 > b2;
	return a.substr(0,3) < b.substr(0,3);
}

class MedalTable {
public:
vector <string> generate(vector <string> v) 
{
	vector<string> r;
	map<string,int> g, s, b;
	set<string> teams;
	for (int i = 0; i < v.size(); i++)
	{
		char t1[12], t2[12], t3[12];
		sscanf(v[i].c_str(), "%[^ ] %[^ ] %[^ ]", t1, t2, t3);
		string s1 = t1, s2 = t2, s3 = t3;
		teams.insert(s1); teams.insert(s2); teams.insert(s3);
		g[s1]++;
		s[s2]++;
		b[s3]++;
	}
	for (typeof(teams.begin()) it = teams.begin(); it != teams.end(); it++)
	{
		string t = *it;
		char buf[100];
		sprintf(buf, "%s %d %d %d", t.c_str(), g[t], s[t], b[t]);
		r.push_back(buf);
	}
	sort(r.begin(), r.end(), lessThan);
	return r;	
}
};


//Powered by [KawigiEdit]
double test0() {
	string t0[] = {"ITA JPN AUS", "KOR TPE UKR", "KOR KOR GBR", "KOR CHN TPE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MedalTable * obj = new MedalTable();
	clock_t start = clock();
	vector <string> my_answer = obj->generate(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "KOR 3 1 0",  "ITA 1 0 0",  "TPE 0 1 1",  "CHN 0 1 0",  "JPN 0 1 0",  "AUS 0 0 1",  "GBR 0 0 1",  "UKR 0 0 1" };
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
	string t0[] = {"USA AUT ROM"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MedalTable * obj = new MedalTable();
	clock_t start = clock();
	vector <string> my_answer = obj->generate(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "USA 1 0 0",  "AUT 0 1 0",  "ROM 0 0 1" };
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
	string t0[] = {"GER AUT SUI", "AUT SUI GER", "SUI GER AUT"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MedalTable * obj = new MedalTable();
	clock_t start = clock();
	vector <string> my_answer = obj->generate(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = { "AUT 1 1 1",  "GER 1 1 1",  "SUI 1 1 1" };
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

