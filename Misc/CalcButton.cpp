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

int memo[1000];

class CalcButton {
public:

int minCost(int pos, string s, string sub)
{
	int n = s.size();
	if (n-pos < 3)
	{
		return n-pos;
	}
	
	int cost;
	if (cost = memo[pos])
		return cost; 
	cost = 1 + minCost(pos+1, s, sub);
	
	if (sub[0] == s[pos] && sub[1] == s[pos+1] && sub[2] == s[pos+2])
	{
		cost = min(cost, 1+minCost(pos+3, s, sub));
	}
	
	return memo[pos] = cost;
}

string getDigits(vector <string> sv) 
{
	string s = "";
	for (int i = 0; i < sv.size(); i++)
	{
		s += sv[i];
	}
	
	int best = 1<<30;
	string bestSub;
	for (char a = '0'; a <= '9'; a++)
	{
		for (char b = '0'; b <= '9'; b++)
		{
			for (char c = '0'; c <= '9'; c++)
			{
				memset(memo, 0, sizeof(memo));
				string sub = "";
				sub = sub + a + b + c;
				int cost = minCost(0, s, sub);
				if (cost < best)
				{
					best = cost;
					bestSub = sub;
				}
			}
		}
	}
	return bestSub;	
}

};


//Powered by [KawigiEdit]
double test0() {
	string t0[] = {"100002000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CalcButton * obj = new CalcButton();
	clock_t start = clock();
	string my_answer = obj->getDigits(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "000";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"777777777"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CalcButton * obj = new CalcButton();
	clock_t start = clock();
	string my_answer = obj->getDigits(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "777";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"6503","210"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CalcButton * obj = new CalcButton();
	clock_t start = clock();
	string my_answer = obj->getDigits(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "032";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"0993034","6","4137","45959935","25939","93993","0","9358333"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CalcButton * obj = new CalcButton();
	clock_t start = clock();
	string my_answer = obj->getDigits(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "993";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

