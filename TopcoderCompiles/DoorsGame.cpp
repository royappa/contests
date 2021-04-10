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

class DoorsGame {
public:
int trophy;
string s;
int N, numColors;

int memo[2][(1<<16)];

string depth(int s)
{
	return string(s+1, ' ');
}

bool wins(int p, int openColors)
{
	if (p == 0)
	{
		for (int i = 0; i < trophy; i++)
		{
			int doorColor = s[i]-'A';
			if (!(openColors&(1<<doorColor))) return false;
		}
		return true;
	}
	else
	{
		for (int i = N-1; i >= trophy; i--)
		{
			int doorColor = s[i]-'A';
			if (!(openColors&(1<<doorColor))) return false;
		}
		return true;
	}	
}

string dump(int open)
{
	string t = s;
	for (int i = 0; i < s.size(); i++)
	{
		if (open&(1<<(s[i]-'A')))
			t[i] = tolower(t[i]);
	}
	return t;
}
			
// return best score player p can get if it is his turn and the specified number of doors are already open
// if player p wins, the score will be positive, if they draw it will be 0, otherwise it will be negative
// in each case it will be the best score player p can get in terms of the number of open doors, according to the rules
int f(int p, int openColors, int dd)
{
	if (wins(p, openColors) && wins(1-p, openColors))
		return 0;
	else if (wins(p, openColors))
		return __builtin_popcount(openColors);
	else if (wins(1-p, openColors))
		return -__builtin_popcount(openColors);
	int &r = memo[p][openColors];
	if (r != -1)
		return r;
	
	int myBestIfOppLoses = (1<<30), myBestIfOppWins = 0;
	bool oppCanWin = false, oppCanLose = false, canDraw = false;
	for (int doorColor = 0; doorColor < numColors; doorColor++)
	{
		if (openColors&(1<<doorColor)) continue; // door is already open
		int res = f(1-p, openColors|(1<<doorColor), dd+1);
		if (res > 0)
		{
			oppCanWin = true;
			myBestIfOppWins = max(res, myBestIfOppWins);
		}
		else if (res < 0)
		{
			oppCanLose = true;
			myBestIfOppLoses = min(-res, myBestIfOppLoses);
		}
		else
		{
			canDraw = true;
		}
	}
	if (oppCanLose)
		return r = myBestIfOppLoses;
	else if (canDraw)
		return r = 0;
	else if (oppCanWin)
		return r = -myBestIfOppWins;
	else
	{
		cout << "ERROR! " << endl;
		return 0;
	}
}

int determineOutcome(string doors, int trophy_) 
{
	trophy = trophy_;
	s = doors;
	set<char> cs(s.begin(), s.end());
	string colors = accumulate(cs.begin(), cs.end(), string(""));
	numColors = colors.size();
	for (int i = 0; i < colors.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == colors[i])
			{
				s[j] = char('A'+i);
			}
		}
	}
	N = s.size(); // for N+1 rooms numbered 0..N
	memset(memo, -1, sizeof(memo));
	int t = f(0, 0, 0);
	return t;

}
};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "ABCD";
	int p1 = 2;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
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

double test1() {
	string p0 = "ABCC";
	int p1 = 2;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -2;
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
	string p0 = "ABABAB";
	int p1 = 3;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
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
	string p0 = "ABAPDCAA";
	int p1 = 5;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -4;
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
	string p0 = "MOCFDCE";
	int p1 = 3;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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

double test5() {
	string p0 = "ABCCDE";
	int p1 = 3;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
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

double test6() {
	string p0 = "ABCCD";
	int p1 = 3;
	DoorsGame * obj = new DoorsGame();
	clock_t start = clock();
	int my_answer = obj->determineOutcome(p0, p1);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

