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

class Pareto {
public:
int optima(vector <string> policy) ;
};

// glob

	vector<string> vf;

// TESTED
vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	
	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

bool better(string a, string b)
{
	vector<string> va = split_nonre(a, " ");
	vector<string> vb = split_nonre(b, " ");
	
	bool better = false;
	for (int i = 0; i < va.size(); i++)
	{
		vector<string>::iterator pa = find(vf.begin(), vf.end(), va[i]);
		vector<string>::iterator pb = find(vf.begin(), vf.end(), vb[i]);
		if (pa < pb)
			return false;
		if (pa > pb)
			better = true;
	}
	return better;
}

 int Pareto::optima(vector <string> p) 
{
	char *f[] = { "awful", "bad", "fair", "fairly-happy", "happy", "ecstatic" };

	for (int i = 0; i < 6; i++)
	{
		vf.push_back(f[i]);
	}
	
	int count = 0;
	for (int i = 0; i < p.size(); i++)
	{	
		bool sub = false;
		for (int j = 0; j < p.size(); j++)
		{
			if (i == j) continue;
			if (better(p[j], p[i]))
			{
				sub = true;
				break;
			}
		}
		if (!sub)
			count++;
	}
	return count;
}



//Powered by [KawigiEdit]
double test0() {
	string t0[] = {"bad bad fairly-happy awful",
"bad bad bad awful",
"ecstatic awful ecstatic ecstatic"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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

double test1() {
	string t0[] = {"bad ecstatic","bad bad", "awful ecstatic",
 "fair happy", "fairly-happy fair",
"fairly-happy fairly-happy", "fair happy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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

double test2() {
	string t0[] = {"happy","bad","fairly-happy","bad","happy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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
	string t0[] = {"bad bad bad bad bad happy fairly-happy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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

double test4() {
	string t0[] = {"fair fair fair fair fair fair fair fair",
"bad fair fair fair fair fair fair fair",
"fairly-happy fair fair fair fair fair fair fair",
"happy bad bad bad bad bad bad bad",
"bad happy happy happy happy happy happy happy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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

double test5() {
	string t0[] = { "happy bad awful ecstatic fair bad fair awful",
 "fair awful bad awful ecstatic awful bad awful",
 "awful awful happy awful ecstatic awful bad fair",
 "bad bad bad happy happy ecstatic awful ecstatic",
 "bad bad awful awful fairly-happy fair fair happy",
 "fair bad bad fair happy bad ecstatic fair"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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

double test6() {
	string t0[] = { "fair happy fair fairly-happy happy happy happy",
 "happy fair fairly-happy fair fair fair happy",
 "happy happy fair fair fairly-happy fair happy",
 "happy fair fair fairly-happy happy happy happy",
 "happy fair happy fairly-happy happy happy happy",
 "fair fair happy fair fair fair fairly-happy"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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

double test7() {
	string t0[] = { "ecstatic bad fair fair fair ecstatic ecstatic",
 "ecstatic happy ecstatic awful awful fair awful",
 "happy fairly-happy bad happy fair fair ecstatic",
 "awful happy fair fairly-happy fair fair bad",
 "awful fairly-happy fair bad happy happy happy",
 "happy happy bad fair happy ecstatic fairly-happy",
 "fair happy ecstatic bad fairly-happy fair fair",
 "fairly-happy bad awful bad awful bad ecstatic",
 "fairly-happy awful bad fair ecstatic bad awful",
 "fairly-happy bad bad bad awful awful fair",
 "awful bad bad ecstatic ecstatic fair bad",
 "fair bad bad fair ecstatic fair ecstatic",
 "bad awful happy happy fairly-happy happy happy",
 "ecstatic fair fair awful happy fair happy",
 "fairly-happy fair awful awful happy awful fair",
 "bad fair fair fairly-happy bad happy happy",
 "bad bad fair ecstatic fairly-happy ecstatic bad",
 "bad fair happy fair awful fair ecstatic",
 "awful bad bad awful bad awful fairly-happy",
 "fair fair ecstatic bad bad happy awful",
 "awful bad ecstatic awful fair fairly-happy happy",
 "happy bad fair awful awful ecstatic bad",
 "happy bad bad ecstatic fair fair bad",
 "bad fairly-happy bad awful fair happy ecstatic",
 "awful awful happy bad happy ecstatic bad",
 "awful fair awful awful ecstatic fair fair",
 "bad fairly-happy awful happy awful bad ecstatic",
 "ecstatic happy happy fair fairly-happy fair bad",
 "happy awful happy bad bad fairly-happy fair",
 "ecstatic fair awful awful awful bad fairly-happy",
 "fair fair bad fairly-happy awful fair fair",
 "fair fairly-happy bad happy happy awful fair",
 "happy ecstatic awful fair fair awful ecstatic",
 "ecstatic awful fair ecstatic ecstatic happy bad",
 "awful bad fair ecstatic happy awful fair",
 "ecstatic happy fair happy happy bad ecstatic",
 "bad awful awful awful happy ecstatic bad",
 "ecstatic fair fair bad awful ecstatic bad",
 "bad happy bad ecstatic bad awful happy",
 "fairly-happy bad ecstatic awful fair fair awful",
 "fairly-happy fair awful awful ecstatic bad fair",
 "fairly-happy bad happy bad fair happy happy",
 "happy ecstatic fair fairly-happy fair bad bad",
 "bad bad fairly-happy happy bad bad bad",
 "happy happy fair fair bad fair awful",
 "awful fair bad bad happy fair fair",
 "fair ecstatic happy happy awful fair bad",
 "awful fairly-happy happy fair happy awful bad",
 "awful fair bad happy happy ecstatic ecstatic",
 "bad bad fair ecstatic happy ecstatic ecstatic"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 35;
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

double test8() {
	string t0[] = {"fair happy fairly-happy",
 "fair happy fair",
 "awful ecstatic fair",
 "awful ecstatic fair",
 "fair happy fair",
 "fair happy fair"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Pareto * obj = new Pareto();
	clock_t start = clock();
	int my_answer = obj->optima(p0);
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
	
	if (argc < 2 || atoi(argv[1]) == 6) {
		time = test6();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 7) {
		time = test7();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 8) {
		time = test8();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

