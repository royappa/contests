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

class ColorfulCards {
public:
int isPrime[1001];

/*
int memo[51][1001];
int NA, NB;
string a, b;

int f(int pa, int pb)
{
	if (pa == NA)
		return 1;
	if (pb == NB)
		return 0;
	int& r = memo[pa][pb];
	if (r != -1)
		return r;
	r = 0;
	if (a[pa] == b[pb])
		r |= f(pa+1, pb+1);
	r |= f(pa, pb+1);
	return r;
}

*/

vector <int> theCards(int N, string colors) 
{


	int m;
	string s = colors;
	m = s.size();
	for (int i = 0; i <= N; i++)
	{
		isPrime[i] = 1;
	}
	isPrime[0] = isPrime[1] = 0;
	for (int k = 2; k*k <= N; k++)
	{
		if (isPrime[k])
		{
			for (int i = k+k; i <= N; i += k)
			{
				isPrime[i] = 0;
			}
		}
	}
	/* editorial algorithm */
	vector<int> minK(m), maxK(m);
	for (int i = 0; i < m; i++)
	{
		for (int k = 1; k <= N; k++)
		{
			if ((s[i] == 'R' && isPrime[k]) || (s[i] == 'B' && !isPrime[k]))
			{
				if (i == 0)
				{
					minK[i] = k;
					break;
				}
				else if (k > minK[i-1])
				{
					minK[i] = k;
					break;
				}
			}
		}
	}
	for (int i = m-1; i >= 0; i--)
	{
		for (int k = N; k >= 1; k--)
		{
			if ((s[i] == 'R' && isPrime[k]) || (s[i] == 'B' && !isPrime[k]))
			{
				if (i == m-1)
				{
					maxK[i] = k;
					break;
				}
				else if (k < maxK[i+1])
				{
					maxK[i] = k;
					break;
				}
			}
		}
	}
	vector<int> r(m, -1);
	for (int i = 0; i < m; i++)
	{
		if (minK[i] != maxK[i]) continue;
		r[i] = minK[i];
	}
	return r;
	
	
/* DP 
	string s2 = "";
	for (int k = 1; k <= N; k++)
	{
		s2 += isPrime[k] ? "R" : "B";
	}
	a = s;
	b = s2;
	vector<int> r(m, -1);
	memset(memo, -1, sizeof(memo));
	for (int i = 0; i < m; i++)
	{
		vector<int> v;
		for (int k = 1; k <= N; k++)
		{
			if ((s[i] == 'R' && isPrime[k]) || (s[i] == 'B' && !isPrime[k]))
			{
				
				//string left = s.substr(0, i);
				//string right = s.substr(i+1);
				//string left2 = s2.substr(0, k-1);
				//string right2 = s2.substr(k);
				
//cout << i << " " << k << ":(" << left << "," << right << ")/(" << left2 << "," << right2 << ")" <<endl;
				NA = i;
				NB = k-1;
				memset(memo, -1, sizeof(memo));
				int x = f(0, 0);
				NA = m;
				NB = N;
				memset(memo, -1, sizeof(memo));
				int y = f(i+1, k);
//cout << x << '-' << y << endl;				
				if (x && y)
				{
					v.push_back(k);
				}
			}
			if (v.size() > 1)
				break;
		}
//cout << v.size() << endl;
		if (v.size() == 1)
			r[i] = v[0];
	}
	return r;
*/

}
	
};
double test0() {
	int p0 = 5;
	string p1 = "RRR";
	ColorfulCards * obj = new ColorfulCards();
	clock_t start = clock();
	vector <int> my_answer = obj->theCards(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {2, 3, 5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int p0 = 7;
	string p1 = "BBB";
	ColorfulCards * obj = new ColorfulCards();
	clock_t start = clock();
	vector <int> my_answer = obj->theCards(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 4, 6 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int p0 = 6;
	string p1 = "RBR";
	ColorfulCards * obj = new ColorfulCards();
	clock_t start = clock();
	vector <int> my_answer = obj->theCards(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {-1, 4, 5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int p0 = 58;
	string p1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
	ColorfulCards * obj = new ColorfulCards();
	clock_t start = clock();
	vector <int> my_answer = obj->theCards(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {-1, -1, -1, -1, -1, -1, -1, -1, 17, 18, 19, 23, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 47, 53 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int p0 = 495;
	string p1 = "RBRRBRBBRBRRBBRRBBBRRBBBRR";
	ColorfulCards * obj = new ColorfulCards();
	clock_t start = clock();
	vector <int> my_answer = obj->theCards(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p2) {
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

