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
#include <queue>

using namespace std;

class KindAndCruel {
public:
typedef vector<int> vi;

bool ok(string &s, int pos, int tk, int tc)
{
	int n = s.size();
	if (pos < 0 || pos >= n) return false;
	if (s[pos] == 'K') return tk != 0;
	else if (s[pos] == 'C') return tc == 0;
	else return true;
}

int crossTheField(string field, int K, int C)
{
	queue<vi> q;
	map<vi,int> dist;
	vi x(3);
	x[0] = x[1] = x[2] = 0;
	q.push(x);
	dist[x] = 0;
	int n = field.size();
	while (q.size() > 0)
	{
		vi head = q.front();
		q.pop();
		if (head[0] == n-1)
		{
			return dist[head];
		}
		// possible cells from here
		int p = head[0], tk = head[1], tc = head[2];
		for (int pos = p-1; pos <= p+1; pos++)
		{
			if (ok(field, pos, (tk+1)%K, (tc+1)%C))
			{
				vi next(3);
				next[0] = pos;
				next[1] = (tk+1)%K;
				next[2] = (tc+1)%C;
				if (dist.count(next) == 0)
				{
					q.push(next);
					dist[next] = dist[head]+1;
				}
			}
		}
	}
	return -1;
}
};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "...";
	int p1 = 2;
	int p2 = 5;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
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
	string p0 = ".K.C.";
	int p1 = 3;
	int p2 = 4;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	string p0 = ".CCCC.";
	int p1 = 3;
	int p2 = 5;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -1;
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
	string p0 = ".CKKKKCKKKKC.KKKKCKKKKC.CKKKKCKKKKCKKKKCKKKKCKKKK.";
	int p1 = 5;
	int p2 = 5;
	KindAndCruel * obj = new KindAndCruel();
	clock_t start = clock();
	int my_answer = obj->crossTheField(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 60;
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

