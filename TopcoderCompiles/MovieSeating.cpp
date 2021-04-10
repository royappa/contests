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

class MovieSeating {
public:
typedef long long LL;

LL memo[100][100];
LL nCk(int n, int k)
{
	if (k == 0 || k == n) return 1;
	LL &res = memo[n][k];
	if (res != -1)
		return res;
	return res = nCk(n-1, k-1) + nCk(n-1, k);
}	

LL fact(int n)
{
	return n == 0 ? 1 : n*fact(n-1);
}
	
long long getSeatings(int numFriends, vector <string> v) 
{
	int n = v.size();
	int m = v[0].size();
	memset(memo, -1, sizeof(memo));
	LL res = 0;
	for (int i = 0; i < n; i++)
	{
		string s = v[i];
		int z = count(s.begin(), s.end(), '.');
		if (z < numFriends) continue;
		res += nCk(z, numFriends)*fact(numFriends);
	}
	for (int j = 0; j < m; j++)
	{
		string s = "";
		for (int i = 0; i < n; i++)
		{
			s += v[i][j];
		}
		int z = count(s.begin(), s.end(), '.');
		if (z < numFriends) continue;
		res += nCk(z, numFriends)*fact(numFriends);
	}
	if (numFriends == 1) res /= 2;
	return res;		
}

};


//Powered by [KawigiEdit]
double test0() {
	int p0 = 2;
	string t1[] = { ".#..",
  ".##.",
  "...." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 34LL;
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
	string t1[] = { "..#",
  ".##",
  "..." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 16LL;
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
	int p0 = 5;
	string t1[] = { "..####..", 
  ".###.##.",
  ".######.",
  "#.#.#.#." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	int p0 = 8;
	string t1[] = { "........" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	MovieSeating * obj = new MovieSeating();
	clock_t start = clock();
	long long my_answer = obj->getSeatings(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 40320LL;
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

