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

class WeirdRooks {
public:
	string describe(vector <int>);
};
vector<int> cols;
int nR;
vector< pair<int,int> > results;
vector< pair<int,int> > poss;	

void backtrack(vector<int> rookCols, vector<int> rookColUsed, int n)
{

	// place nth rook in row n
	
			int count = 0;
			for (int i = 0; i < nR; i++)
			{
				for (int j = 0; j < cols[i]; j++)
				{
					if (rookCols[i] != j) // (i, j) empty
					{
						bool special = true;
						for (int k = i; k < nR; k++)
						{
							if (rookCols[k] == j)
							{
								special = false;
								break;
							}
						}
						for (int k = j; special && k < cols[i]; k++)
						{
							if (rookCols[i] == k)
							{
								special = false;
								break;
							}
						}
						if (special)
						{
							count++;
						}
					}
				}
			}
			results.push_back(make_pair(n, count));		
				if (n == nR)
	{
		return;
	}
			
	for (int c = 0; c < cols[n]; c++)
	{
			// count number of special spots on board now	
		if (rookColUsed[c] == 0)
		{			
			// place rook on row n, column c
			rookColUsed[c] = 1;
			rookCols[n] = c;			
			backtrack(rookCols, rookColUsed, n+1);
			rookColUsed[c] = 0;			
			rookCols[n] = 0;
		}
	}
	
}			

string WeirdRooks::describe(vector <int> _cols) 
{
	cols = _cols;
	
	nR = cols.size();
	
	vector<int> rookCols(nR);
	vector<int> rookColUsed(10);
	
	backtrack(rookCols, rookColUsed, 0);
	
	sort(results.begin(), results.end());
	
	string result = "";
	for (int i = 0; i < results.size(); i++)
	{
		char buf[100];
		sprintf(buf, "%d,%d", results[i].first+1, results[i].second+1);
		result += buf;
		if (i < results.size()-1)
			result += " ";
	}
	return result;	
}
double test0() {
	int t0[] = {3,3,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	WeirdRooks * obj = new WeirdRooks();
	clock_t start = clock();
	string my_answer = obj->describe(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0,9 1,4 1,5 1,6 1,7 1,8 2,1 2,2 2,3 2,4 2,5 2,6 3,0 3,1 3,2 3,3";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	WeirdRooks * obj = new WeirdRooks();
	clock_t start = clock();
	string my_answer = obj->describe(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0,6 1,3 1,4 1,5 2,1 2,2 2,3 3,0";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	WeirdRooks * obj = new WeirdRooks();
	clock_t start = clock();
	string my_answer = obj->describe(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0,1 1,0";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	int t0[] = {2,9};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	WeirdRooks * obj = new WeirdRooks();
	clock_t start = clock();
	string my_answer = obj->describe(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "0,11 1,2 1,3 1,4 1,5 1,6 1,7 1,8 1,9 1,10 2,0 2,1 2,2 2,3 2,4 2,5 2,6 2,7 2,8";
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
