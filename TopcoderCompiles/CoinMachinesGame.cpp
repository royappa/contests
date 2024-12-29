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

class CoinMachinesGame {
public:
typedef pair<int,int> pii;

int maxGames(int coins, vector <int> need, vector <int> give)
{
	int n = need.size();
	vector<pii> v;
	for (int i = 0; i < n; i++)
	{
		v.push_back(make_pair(need[i]-give[i],need[i]));
	}
	sort(v.begin(), v.end());
	int games = 0;
	while (coins > 0)
	{
		int p = -1;
		for (int i = 0; i < n; i++)
		{
			if (coins >= v[i].second)
			{
				p = i;
				break;
			}
		}
		if (p != -1)
		{
			int t = 1;//coins/v[p].second;
			coins -= t*v[p].first;
			games += t;
		}
		else
		{
			break;
		}
	}
	return games;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 10;
	int t1[] = {5,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {4,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CoinMachinesGame * obj = new CoinMachinesGame();
	clock_t start = clock();
	int my_answer = obj->maxGames(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 7;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int p0 = 1000;
	int t1[] = {16,14,11,7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {15,12,8,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CoinMachinesGame * obj = new CoinMachinesGame();
	clock_t start = clock();
	int my_answer = obj->maxGames(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 988;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int p0 = 1000000000;
	int t1[] = {1000,900,800,700,600,500,400,300,200,100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {701,802,503,604,405,306,107,208,1,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CoinMachinesGame * obj = new CoinMachinesGame();
	clock_t start = clock();
	int my_answer = obj->maxGames(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10869564;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int p0 = 12345678;
	int t1[] = {342,234,65,76,85,734,67,345,70,234};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {45,78,3,10,45,12,45,57,1,230};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CoinMachinesGame * obj = new CoinMachinesGame();
	clock_t start = clock();
	int my_answer = obj->maxGames(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3086370;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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

