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

class DNAString {
public:
int minChanges(int P, vector <string> dna) 
{
	string s = accumulate(dna.begin(), dna.end(), string(""));
	int n = s.size();
	int r = 0;
	for (int i = 0; i < (n+P-1)/P; i++)
	{
		string t = "";
		for (int j = 0; j < P; j++)
		{
			if (i*P+j < n)
			{
				t += s[j];
			}
		}
		map<char,int> m;
		for (int j = 0; j < t.size(); j++)
		{
			m[t[j]]++;
		}
		int mx = 0;
		for (typeof(m.begin()) it = m.begin(); it != m.end(); it++)
		{
			mx = max(mx, it->second);
		}
		r += t.size()-mx;
	}
	return r;
}

};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 3;
	string t1[] = {"ATAGATA"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNAString * obj = new DNAString();
	clock_t start = clock();
	int my_answer = obj->minChanges(p0, p1);
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

double test1() {
	int p0 = 2;
	string t1[] = {"ACGTGCA"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNAString * obj = new DNAString();
	clock_t start = clock();
	int my_answer = obj->minChanges(p0, p1);
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

double test2() {
	int p0 = 13;
	string t1[] = {"ACGCTGACAGATA"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNAString * obj = new DNAString();
	clock_t start = clock();
	int my_answer = obj->minChanges(p0, p1);
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

double test3() {
	int p0 = 1;
	string t1[] = {"AAAATTTCCG"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNAString * obj = new DNAString();
	clock_t start = clock();
	int my_answer = obj->minChanges(p0, p1);
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

double test4() {
	int p0 = 12;
	string t1[] = {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	DNAString * obj = new DNAString();
	clock_t start = clock();
	int my_answer = obj->minChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 20;
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

