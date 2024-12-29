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

class OnLineRank {
public:
int calcRanks(int k, vector <int> scores) 
{
	int sum = 0;
	for (int i = 0; i < scores.size(); i++)
	{
		int rank = 0;
		if (i >= k)
		{
			for (int j = 0; j < k; j++)
			{
				if (scores[i-j-1] > scores[i])
				{
					rank++;
				}
			}
		}
		else
		{
			for (int j = i-1; j >= 0; j--)
			{
				if (scores[j] > scores[i])
				{
					rank++;
				}
			}
		}
		rank++;
		sum += rank;
	}
	return sum;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 3;
	int t1[] = {6,9,8,15,7,12};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OnLineRank * obj = new OnLineRank();
	clock_t start = clock();
	int my_answer = obj->calcRanks(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 11;
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
	int p0 = 80;
	int t1[] = {3,3,3,3,3,3,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	OnLineRank * obj = new OnLineRank();
	clock_t start = clock();
	int my_answer = obj->calcRanks(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

