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

class ComputerExpert {
public:

	// this is NOT like a Java "split". only works on a set of fixed separators, not on an RE.
	// if s="", then returns a zero-size vector
	// THIS PART IS CORRECT
	vector<string> split_nonre(string s, string sep)
	{
		char *sC = (char *) s.c_str();
		char *sepC = (char *) sep.c_str();
		
		char *word;
		vector<string> results;
		while ((word = strtok(sC, sepC)) != NULL)
		{
			int n = strlen(word);
			char *buf = (char *) malloc(n+1); // surely there's a better way in C++..
			strcpy(buf, word);
			results.push_back(buf);
			sC = NULL;
		}
		return results;
	}
	

	vector <string> operate(vector <string> facts, vector <string> rules) 
	{
		vector<string> outcomes;
		
		map<string,int> known;
		map<string,int> orig;
		for (int i = 0; i < facts.size(); i++)
		{
			known[facts[i]] = 1;
			orig[facts[i]] = 1;
		}
		
		int lastKnown = 0, nowKnown = known.size();
		while (lastKnown != nowKnown)
		{
			// generate all outcome facts & add to outcomes
			for (int i = 0; i < rules.size(); i++)
			{
				int len = rules[i].size();
				string::size_type spPos = rules[i].rfind(' '); 
				string outcome = rules[i].substr(spPos+1);
				string cond = rules[i].substr(0, spPos-3);
				
				vector<string> ands = split_nonre(cond, ","); 
				bool all = true;
				for (int j = 0; j < ands.size(); j++)
				{
					vector<string> ors = split_nonre(ands[j], "/");
					bool some = false;
					for (int k = 0; k < ors.size(); k++)
					{
						if (known[ors[k]])
						{
							some = true;
							break;
						}
					}
					if (!some)
					{
						all = false;
						break;
					}
				}
				if (all)
				{
					known[outcome] = 1;
					if (!orig[outcome])
					{
						outcomes.push_back(outcome);
					}
				}
			}
			lastKnown = nowKnown;
			nowKnown = known.size();
		}
		sort(outcomes.begin(), outcomes.end());	
		vector<string>::iterator ui = unique(outcomes.begin(), outcomes.end());
		outcomes.erase(ui, outcomes.end());
		return outcomes;		
	}
};

double test0() {
	string t0[] = {"SKY_IS_CLOUDY","HAVE_MONEY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"HAVE_MONEY,BAD_WEATHER -> WATCH_MOVIE","SKY_IS_CLOUDY -> BAD_WEATHER",
"GOOD_WEATHER -> PLAY_SOCCER"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = {"BAD_WEATHER", "WATCH_MOVIE" };
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
	string t0[] = {"NEEDLE_LEAF","KEEPS_LEAVES"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"KEEPS_LEAVES -> EVERGREEN","NEEDLE_LEAF -> GYMNOSPERM",
"EVERGREEN,GYMNOSPERM -> PINE_TREE"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = {"EVERGREEN", "GYMNOSPERM", "PINE_TREE" };
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
	string t0[] = {"I"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"I -> I","P -> CONSONANT", "Z -> CONSONANT", "A/E/I/O/U -> VOWEL"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = {"VOWEL" };
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
	string t0[] = {"Y","W","L","T","H","J","G","T","F","P","T","P","P","N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"C/V,J,F/T,N,W,L -> M","N/L,F,B/N/E,Y -> C",
"M,G,G,S/F/Q,G,S/G,H/Z,W,F,C,Q/F,M -> E"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = {"C", "E", "M" };
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
	string t0[] = {"G","H"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A/B/C/D/E/F,G/Z -> Y", "H,H,H,H,H,H,H,H -> Z"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = {"Z" };
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
double test5() {
	string t0[] = {"A","B","_X", "X_"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"A/B,C -> D","A,B,C -> D","X -> Y","_X_ -> Y"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ComputerExpert * obj = new ComputerExpert();
	clock_t start = clock();
	vector <string> my_answer = obj->operate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t2[] = { };
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
