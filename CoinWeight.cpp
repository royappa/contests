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

class CoinWeight {
public:
	int possibleValues(int, vector <string>);
};

bool Value[2600][8][101];

int CoinWeight::possibleValues(int weight, vector <string> coins) 
{
	int n = coins.size();
	
	int coinVal[8], minWeight[8], maxWeight[8];
	int minW = 10000, maxVal = 0;
	for (int c = 1; c <= n; c++)
	{
		sscanf(coins[c-1].c_str(), "%d %d %d", &coinVal[c], &minWeight[c], &maxWeight[c]);
		maxVal = max(maxVal, coinVal[c]);
		minW = min(minW, minWeight[c]);
	}

	for (int v = 0; v <= (weight/minW)*maxVal; v++)
	{
		for (int c = 1; c <= n; c++)
		{
			for (int W = 0; W <= weight; W++)
			{
				Value[v][c][W] = (v == 0 && W == 0);					
			}
		}
	}	

	for (int c = 1; c <= n; c++)
	{
		for (int W = 0; W <= weight; W++)
		{
			for (int v = 0; v <= (weight/minW)*maxVal; v++)
			{
				Value[v][c][W] = Value[v][c][W] || Value[v][c-1][W];		
				//if (Value[v][c][W]) cout << v << " " << c << " " << W << " ooo" << endl;	
				for (int w = minWeight[c]; w <= maxWeight[c] && !Value[v][c][W]; w++)
				{
					if (v-coinVal[c] >= 0 && W-w >= 0)
					{
						Value[v][c][W] = Value[v][c][W] || Value[v-coinVal[c]][c][W-w];
						//if (Value[v][c][W]) cout << v << " " << c << " " << W << " iii" << endl;
					}
				}
			}
		}
	}
	int count = 0;
	for (int v = 0; v <= (weight/minW)*maxVal; v++)
	{
		if (Value[v][n][weight])
		{
			count++;
		}
	}
	return count;
	
}
double test0() {
	int p0 = 30;
	string t1[] = {"001 10 10"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int p0 = 11;
	string t1[] = {"25 20 22"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int p0 = 50;
	string t1[] = {"1 15 20", "3 30 30"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int p0 = 50;
	string t1[] = {"1 15 20", "2 30 30"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	int p0 = 100;
	string t1[] = {"1 2 31","2 16 46","4 31 61","8 46 76","16 61 91","32 76 100","50 2 31"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CoinWeight * obj = new CoinWeight();
	clock_t start = clock();
	int my_answer = obj->possibleValues(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1316;
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
