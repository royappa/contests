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

#include <string.h>  /* for new C++ version */

using namespace std;

class SpamDetector {
public:

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	char *status = NULL;
	
	char *word;
	vector<string> results;
	while ((word = strtok_r(sC, sepC, &status)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

typedef pair<char,int> p;

vector<p> sig(string s)
{
	vector<p> r;
	s += ".";
	int n = s.size();	
	int num = 0;
	char last = s[0];		
	for (int i = 0; i < n; i++)
	{
		if (s[i] == last)
		{
			num++;
		}
		else
		{
			r.push_back(make_pair(last, num));
			last = s[i];
			num = 1;
		}
	}
	return r;
}

string strtolower(string s) { for (int i = 0; i < s.size(); i++) { if (isupper(s[i])) s[i] = tolower(s[i]); } return s;}


int countKeywords(string s, vector <string> v) 
{
	vector<string> w = split_nonre(s, " ");
	
	for (int i = 0; i < w.size(); i++)
	{
		w[i] = strtolower(w[i]);
	}
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = strtolower(v[i]);
	}
	
	int r = 0;
	for (int i = 0; i < w.size(); i++)
	{
		bool spam = false;
		vector<p> wv = sig(w[i]);
		for (int j = 0; j < v.size(); j++)
		{
			vector<p> vv = sig(v[j]);
			if (vv.size() != wv.size()) continue;
			bool match = true;
			for (int k = 0; k < vv.size(); k++)
			{
				if (vv[k].first == wv[k].first && vv[k].second <= wv[k].second)
				{
					continue;
				}
				match = false;
				break;
			}
			if (match)
			{
				//cout << w[i] << " " << v[j] << endl;
				spam = true;
				break;
			}
		}
		if (spam)
			r++;
	}
	return r;	
}

};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "LoooW INTEREST RATES available dont BE slow";
	string t1[] = {"interest","rates","loan","available","LOW"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SpamDetector * obj = new SpamDetector();
	clock_t start = clock();
	int my_answer = obj->countKeywords(p0, p1);
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
	string p0 = "Dear Richard Get Rich Quick            no risk";
	string t1[] = {"rich","risk","Quicken","wealth","SAVE"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SpamDetector * obj = new SpamDetector();
	clock_t start = clock();
	int my_answer = obj->countKeywords(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string p0 = "in debbtt againn and aAgain and AGAaiIN";
	string t1[] = {"AGAIN","again","Again","again"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SpamDetector * obj = new SpamDetector();
	clock_t start = clock();
	int my_answer = obj->countKeywords(p0, p1);
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
	string p0 = "PlAyy ThEE Lottto     get Loottoo feever";
	string t1[] = {"play","lotto","lottery","looser"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SpamDetector * obj = new SpamDetector();
	clock_t start = clock();
	int my_answer = obj->countKeywords(p0, p1);
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

double test4() {
	string p0 = "                                   ";
	string t1[] = {"empty","space","does","not","match"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	SpamDetector * obj = new SpamDetector();
	clock_t start = clock();
	int my_answer = obj->countKeywords(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	
	if (argc < 2 || atoi(argv[1]) == 4) {
		time = test4();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

