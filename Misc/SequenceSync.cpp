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

class SequenceSync {
public:
	int getLength(vector <string>);
};

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) s.c_str();
	char *sepC = (char *) sep.c_str();

	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}
	
int count(int n) 
{ 
	int c = 0; 
	while (n > 0) 
	{ 
		c += n%2;
		n /= 2;
	}
	return c;
}

int dist[1<<20];
int q[1<<20];

int SequenceSync::getLength(vector <string> transitions) 
{
	int N = transitions.size();
	int mat[25][25];
	
	for (int i = 0; i < N; i++)
	{
		vector<string> st = split_nonre(transitions[i], " ");
		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = atoi(st[j].c_str());
		}
	}
	for (int i = 0; i < (1<<20); i++)
	{
		dist[i] = -1;
	}
	
	int head = 0, tail = 0, num = 0;
	
	q[head] = (1<<N)-1;
	num = 1;
	dist[(1<<N)-1] = 0;
	while (num > 0)
	{
		int cur = q[head++];
		num--;
		if (count(cur) == 1)
		{
			return dist[cur];
		}
		for (int inp = 0; inp <= 3; inp++)
		{
			int next = 0;
			for (int k = 0; k < N; k++)
			{
				if (cur & (1<<k))
				{
					next |= 1<<mat[k][inp];
				}
			}
			if (dist[next] == -1)
			{
				q[++tail] = next;
				num++;
				dist[next] = dist[cur]+1;
			}
		}
	}
	return -1;	
}

double test0() {
	string t0[] = {"1 1 1 1",
 "1 1 1 2",
 "0 2 2 2"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SequenceSync * obj = new SequenceSync();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"1 1 1 1",
 "2 2 2 2",
 "3 3 3 3",
 "0 0 0 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SequenceSync * obj = new SequenceSync();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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
	string t0[] = {"0 0 0 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SequenceSync * obj = new SequenceSync();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
double test3() {
	string t0[] = {"1 1 1 0",
 "2 2 2 1",
 "3 3 3 2",
 "4 4 4 3",
 "5 5 5 5",
 "6 6 6 6",
 "7 7 7 0",
 "0 0 0 8",
 "8 8 8 8",
 "9 9 9 8"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	SequenceSync * obj = new SequenceSync();
	clock_t start = clock();
	int my_answer = obj->getLength(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 15;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
