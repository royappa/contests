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

class ColoredStrokes {
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


int getLeast(vector <string> picture) 
{
	int r = 0;
	for (int i = 0; i < picture.size(); i++)
	{
		string s = picture[i];
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'B') s[j] = '.';
			if (s[j] == 'G') s[j] = 'R';
		}
		vector<string> v = split_nonre(s, ".");
		r += v.size();
	}
	for (int i = 0; i < picture[0].size(); i++)
	{
		string s = "";
		for (int j = 0; j < picture.size(); j++)
		{
			s += picture[j][i];
		}
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'R') s[j] = '.';
			if (s[j] == 'G') s[j] = 'B';
		}
		vector<string> v = split_nonre(s, ".");
		r += v.size();
	}
	return r;					
}

};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {"...",
 "..."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"..B.",
 "..B."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {".BB."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	string t0[] = {"...B..",
 ".BRGRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	string t0[] = {"...B..",
 ".BRBRR",
 ".B.B.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	string t0[] = {"GR",
 "BG"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ColoredStrokes * obj = new ColoredStrokes();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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

