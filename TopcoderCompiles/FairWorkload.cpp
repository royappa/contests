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

class FairWorkload {
public:
int getMostWork(vector <int> folders, int workers) 
{
	int n = folders.size();
	int best = (1<<30);
	if (workers == 1) return accumulate(folders.begin(), folders.end(), 0);
	for (int m = 0; m < (1<<n); m++)
	{
		if (m == 0 || m == (1<<n)-1) continue;
		int parts = 0;
		int last = m%2; // last bit
		int most = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			int bit = (m&(1<<i)) ? 1 : 0;
			if (bit == last)
			{
				sum += folders[i];
			}
			else
			{
				parts++;
				most = max(most, sum);
				sum = folders[i];
				last = 1-last;
			}
		}
		parts++;
		most = max(most, sum);
		if (parts == workers)
		{
			//cout << m << " " << most << endl;
			best = min(best, most);
		}
	}
	return best;
}
};


//Powered by [KawigiEdit]
double test0() {
	int t0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 170;
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
	int t0[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 110;
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
	int t0[] = { 568, 712, 412, 231, 241, 393, 865, 287, 128, 457, 238, 98, 980, 23, 782 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1785;
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
	int t0[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1000 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1000;
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
	int t0[] = { 50, 50, 50, 50, 50, 50, 50 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 2;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 200;
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

double test5() {
	int t0[] = {1,1,1,1,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 100;
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

double test6() {
	int t0[] = { 950, 650, 250, 250, 350, 100, 650, 150, 150, 700 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 6;
	FairWorkload * obj = new FairWorkload();
	clock_t start = clock();
	int my_answer = obj->getMostWork(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 950;
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
	
	if (argc < 2 || atoi(argv[1]) == 5) {
		time = test5();
		if (time < 0.0)
			errors = true;
	}
	
	if (argc < 2 || atoi(argv[1]) == 6) {
		time = test6();
		if (time < 0.0)
			errors = true;
	}
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

