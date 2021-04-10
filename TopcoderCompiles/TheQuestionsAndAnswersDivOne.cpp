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
#include <string.h>

using namespace std;

class TheQuestionsAndAnswersDivOne {
public:

vector<int> v;
int n, q;
int memo[9][512][512];

// return number of ways to answer questions [p..q) give that "answers" is a mask stating the answers for questions 0..p-1
int f(int p, int questions, int answers)
{
	if (p == n && questions==((1<<q)-1))
	{
		return 1;
	}
	else if (p == n)
	{
		return 0;
	}
	int &r = memo[p][questions][answers];
	if (r != -1)
		return r;
	r = 0;
	for (int i = 0; i < q; i++)
	{
		// choose answer v[p] for question i, if it is compatible with question i's previously selected answer
		if (!(questions&(1<<i)) || (answers&(1<<i))==(v[p]<<i))
		{
			r += f(p+1, questions|(1<<i), answers|(v[p]<<i));
		}
	}
	return r;		
}

int find(int q_, vector <string> answers) 
{
	q = q_;
	n = answers.size();
	for (int i = 0; i < n; i++)
	{
		v.push_back(answers[i]=="Yes");
	}
	memset(memo, -1, sizeof(memo));
	return f(0, 0, 0);	
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 2;
	string t1[] = {"No", "Yes"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	TheQuestionsAndAnswersDivOne * obj = new TheQuestionsAndAnswersDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
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

double test1() {
	int p0 = 2;
	string t1[] = {"No", "No", "No"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	TheQuestionsAndAnswersDivOne * obj = new TheQuestionsAndAnswersDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
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

double test2() {
	int p0 = 3;
	string t1[] = {"Yes", "No", "No", "Yes"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	TheQuestionsAndAnswersDivOne * obj = new TheQuestionsAndAnswersDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
	int p0 = 3;
	string t1[] = {"Yes", "Yes", "Yes", "No"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	TheQuestionsAndAnswersDivOne * obj = new TheQuestionsAndAnswersDivOne();
	clock_t start = clock();
	int my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 18;
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

