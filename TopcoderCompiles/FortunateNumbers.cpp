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

class FortunateNumbers {
public:

bool fortunate(int x)
{
	while (x > 0)
	{
		int d = x%10;
		if (d != 5 && d != 8)
			return false;
		x /= 10;
	}
	return true;
}

int getFortunate(vector <int> a, vector <int> b, vector <int> c) 
{
	set<int> s;
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			for (int k = 0; k < c.size(); k++)
			{
				int z = a[i]+b[j]+c[k];
				if (fortunate(z))
					s.insert(z);
			}
		}
	}
	return s.size();	
}

};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = { 1, 10, 100 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 3, 53 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 4, 54 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FortunateNumbers * obj = new FortunateNumbers();
	clock_t start = clock();
	int my_answer = obj->getFortunate(p0, p1, p2);
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
	int t0[] = { 47 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 500 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 33 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FortunateNumbers * obj = new FortunateNumbers();
	clock_t start = clock();
	int my_answer = obj->getFortunate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
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
	int t0[] = { 100, 1, 10, 100, 1, 1 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 3, 53, 53, 53, 53, 53, 53 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 4, 54, 4, 54, 4, 54 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FortunateNumbers * obj = new FortunateNumbers();
	clock_t start = clock();
	int my_answer = obj->getFortunate(p0, p1, p2);
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

double test3() {
	int t0[] = { 500, 800 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 50, 80 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 5, 8 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FortunateNumbers * obj = new FortunateNumbers();
	clock_t start = clock();
	int my_answer = obj->getFortunate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 8;
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

double test4() {
	int t0[] = { 30000, 26264 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 30000, 29294 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 30000, 29594 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	FortunateNumbers * obj = new FortunateNumbers();
	clock_t start = clock();
	int my_answer = obj->getFortunate(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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

