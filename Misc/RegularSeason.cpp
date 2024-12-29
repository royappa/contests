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
	typedef pair<string,int> typeScore;

	
	int rounds, n;
	
	bool fnCompar(const typeScore a, const typeScore b) 
	{
		int winA = a.second;
		int winB = b.second;
		int winAR = (int) floor( 0.5 + (double) winA * rounds / 100.0 );
		int winBR = (int) floor( 0.5 + (double) winB * rounds / 100.0 );
		if (winAR != winBR)
			return winAR > winBR;
		if (winA != winB)
			return winA > winB;
		
		return a.first < b.first;
	}
	
class RegularSeason {
public:



	
	vector <string> finalStandings(vector <string> teams, int _rounds) 
	{
		n = teams.size();
		vector<typeScore> scores(n);

		rounds = _rounds;
		
		for (int i = 0; i < n; i++)
		{
			istringstream istr(teams[i]);
			istr >> scores[i].first;
			int score = 0;
			for (int j = 0; j < n; j++)
			{
				int s;
				istr >> s;
				if (j == i)
					continue;				
				score += s;
				scores[j].second += (100-s);
			}
			scores[i].second += score;
		}
		stable_sort(scores.begin(), scores.end(), fnCompar);
		vector<string> result;
		for (int i = 0; i < n; i++)
		{
			int s = (int) floor(0.5 + (double) scores[i].second *  rounds / 100.0);
			char buf[100];
			sprintf(buf, "%s %d", scores[i].first.c_str(), s);
			result.push_back(buf);
		}
		return result;
	}

};

double test0() {
	string t0[] = {"A 0 10 50",
"B 100 0 100",
"C 50 10 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 5;
	RegularSeason * obj = new RegularSeason();
	clock_t start = clock();
	vector <string> my_answer = obj->finalStandings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "B 19",  "A 6",  "C 6" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"SPURS 0 33 67 100",
"LAKERS 67 0 33 100",
"WOLVES 33 67 0 100",
"KINGS 0 75 75 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	RegularSeason * obj = new RegularSeason();
	clock_t start = clock();
	vector <string> my_answer = obj->finalStandings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "SPURS 8",  "LAKERS 7",  "WOLVES 7",  "KINGS 3" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"A 0 10 20 30 40 50 60 70 80 90",
"AA 90 0 10 20 30 40 50 60 70 80",
"AAA 80 90 0 10 20 30 40 50 60 70",
"AAAA 70 80 90 0 10 20 30 40 50 60",
"AAAAA 60 70 80 90 0 10 20 30 40 50",
"AAAAAA 50 60 70 80 90 0 10 20 30 40",
"AAAAAAA 40 50 60 70 80 90 0 10 20 30",
"AAAAAAAA 30 40 50 60 70 80 90 0 10 20",
"AAAAAAAAA 20 30 40 50 60 70 80 90 0 10",
"AAAAAAAAAA 10 20 30 40 50 60 70 80 90 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	RegularSeason * obj = new RegularSeason();
	clock_t start = clock();
	vector <string> my_answer = obj->finalStandings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "A 90",  "AA 90",  "AAA 90",  "AAAA 90",  "AAAAA 90",  "AAAAAA 90",  "AAAAAAA 90",  "AAAAAAAA 90",  "AAAAAAAAA 90",  "AAAAAAAAAA 90" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"WF 0 0 71 10 62 87 49 75 50","OZ 38 0 79 55 36 96 63 17 37",
"C 13 75 0 96 61 2 33 5 64","LCG 13 85 87 0 60 72 86 1 12",
"GDDYC 71 62 21 6 0 17 63 34 32","B 37 66 81 81 53 0 61 80 90",
"XK 14 63 40 25 13 86 0 6 43","YVN 57 30 55 22 31 11 81 0 13",
"SKGAN 28 79 90 79 75 62 36 86 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	RegularSeason * obj = new RegularSeason();
	clock_t start = clock();
	vector <string> my_answer = obj->finalStandings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "SKGAN 99",  "WF 93",  "B 92",  "LCG 84",  "YVN 80",  "OZ 76",  "GDDYC 72",  "C 63",  "XK 62" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	string t0[] = {
"ZSN 0 61 70 44 69 40 84 59 20",
"SJKB 95 0 88 39 99 18 90 58 44",
"EBIUF 63 71 0 5 28 26 41 90 71",
"MA 73 90 39 0 40 91 31 39 57",
"NPT 35 74 75 74 0 74 14 20 27",
"JVY 68 92 37 52 11 0 91 20 52",
"ZBOW 66 44 69 9 8 7 0 2 35",
"HH 31 70 14 39 6 68 73 0 20",
"P 70 62 66 54 9 55 5 98 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	RegularSeason * obj = new RegularSeason();
	clock_t start = clock();
	vector <string> my_answer = obj->finalStandings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { "MA 94",  "NPT 92",  "P 89",  "JVY 84",  "SJKB 77",  "ZSN 75",  "EBIUF 74",  "HH 74",  "ZBOW 61" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<"\""<<p2[0]<<"\"";
		for (int i=1; i<p2.size(); i++)
			cout <<", \"" <<p2[i]<<"\"";
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
	if (my_answer != p2) {
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
