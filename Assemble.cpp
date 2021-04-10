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

class Assemble {
public:
	int minCost(vector <int>);
};

int cost[100][100];

int Assemble::minCost(vector <int> conn) 
{
	int n = conn.size()-1;
	for (int i = 1; i <= n; i++)
	{
		cost[i][i] = 0;
	}
	
	for (int d = 2; d <= n; d++)
	{
		// compute costs of all sequences of length d, from [s..s+d-1]
		for (int s = 1; s+d-1 <= n; s++)
		{
			int e = s+d-1;
			int minC = -1;
			for (int k = s; k <= e-1; k++)
			{
				int a = cost[s][k]; // k-s+1 <= d, so previously calculated
				int sizeA = k-s+1;
				int b = cost[k+1][e]; // likewise
				int sizeB = e-(k+1)+1;
				int inpA = conn[s-1];
				int outA = conn[k];
				int inpB = conn[(k+1)-1];
				int outB = conn[e];
				int c = a + b + (inpA+sizeA)*outA*(outB+sizeB);
				if (minC == -1 || c < minC)
				{
					minC = c;
				}
			}
			cost[s][e] = minC;
		}
	}
	return cost[1][n];
}


double test0() {
	int t0[] = {19,50,10,39};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Assemble * obj = new Assemble();
	clock_t start = clock();
	int my_answer = obj->minCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 19400;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {13,18,24,11,25,100,93,92,79};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Assemble * obj = new Assemble();
	clock_t start = clock();
	int my_answer = obj->minCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 407518;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {1,1,1,1,1,1,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	Assemble * obj = new Assemble();
	clock_t start = clock();
	int my_answer = obj->minCost(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 59;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
