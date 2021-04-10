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

class DivideAndShift {
public:
typedef pair<int,int> pii;

pii move1(int N, int M, int p)
{
	int n = N/p;
	int m = M%n;
	if (m == 0) m = n;
	return make_pair(n, m);
}

pii move2(int N, int M)
{
	return M == 1 ? make_pair(N,N) : make_pair(N,M-1);
}
pii move3(int N, int M)
{
	return M == N ? make_pair(N,1) : make_pair(N,M+1);
}

int cache[1000001];

bool isPrime(int n)
{
	if (n < 2) return false;
	if (n == 2) return true;
	if (cache[n] != -1) return cache[n] == 1;
	for (int d = 2; d*d <= n; d++)
	{
		if (n%d == 0) 
		{
			cache[n] = 0;
			return false;
		}
	}
	cache[n] = 1;
	return true;
}

int getLeast(int N, int M)
{

	memset(cache, -1, sizeof(cache));
	deque<pii> q;

	pii h = make_pair(N,M);
	q.push_back(h);
	map<pii,int> dist;


	dist[h] = 0;

	while (q.size() > 0)
	{
		h = q.front();
		q.pop_front();
		N = h.first;
		M = h.second;
		if (M == 1)
			return dist[h];

		for (int d = 2; d*d <= N; d++)
		{
			if (N % d != 0) continue;
			if (isPrime(d))
			{
				pii x = move1(N, M, d);
				if (dist.count(x) == 0)
				{
				//cout << x.first << " " << x.second << endl;
					dist[x] = dist[h]+1;
					q.push_back(x);
				}
			}
			if (isPrime(N/d))
			{
				pii x = move1(N, M, N/d);
				//cout << x.first << " " << x.second << endl;
				if (dist.count(x) == 0)
				{
					dist[x] = dist[h]+1;
					q.push_back(x);
				}
			}			
		}
		if (isPrime(N))
		{
			pii x = move1(N, M, N);
			//cout << x.first << " " << x.second << endl;
			if (dist.count(x) == 0)
			{
				dist[x] = dist[h]+1;
				q.push_back(x);
			}
		}		
		pii y = move2(N, M);
		if (dist.count(y) == 0)
		{
			dist[y] = dist[h]+1;
			q.push_back(y);
		}
		y = move3(N, M);
		if (dist.count(y) == 0)
		{
			dist[y] = dist[h]+1;
			q.push_back(y);
		}
	}
	return -1;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 56;
	int p1 = 14;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
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
	int p0 = 49;
	int p1 = 5;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
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

double test2() {
	int p0 = 256;
	int p1 = 7;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
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

double test3() {
	int p0 = 6;
	int p1 = 1;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
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

double test4() {
	int p0 = 77777;
	int p1 = 11111;
	DivideAndShift * obj = new DivideAndShift();
	clock_t start = clock();
	int my_answer = obj->getLeast(p0, p1);
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

