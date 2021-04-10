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

class SRMCodingPhase {
public:
int countScore(vector <int> points, vector <int> skills, int luck) 
{
	int m = 0;
	for (int l1 = 0; l1 <= luck; l1++)
	{
		for (int l2 = 0; l2 <= luck-l1; l2++)
		{
			for (int l3 = 0; l3 <= luck-l1-l2; l3++)
			{
				int t1 = max(skills[0]-l1, 1);
				int t2 = max(skills[1]-l2, 1);
				int t3 = max(skills[2]-l3, 1);
				int s1 = points[0]-2*t1;
				int s2 = points[1]-4*t2;
				int s3 = points[2]-8*t3;
				vector<int> v;
				if (t1 <= 75) v.push_back(s1);
				if (t2 <= 75) v.push_back(s2);
				if (t3 <= 75) v.push_back(s3);
				if (t1+t2 <= 75) v.push_back(s1+s2);
				if (t1+t3 <= 75) v.push_back(s1+s3);
				if (t2+t3 <= 75) v.push_back(s2+s3);
				if (t1+t2+t3 <= 75) v.push_back(s1+s2+s3);
				sort(v.rbegin(), v.rend());
				if (v.size() > 0) m = max(m, v[0]);
			}
		}
	}
	return m;
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {250, 500, 1000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1310;
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
	int t0[] = {300, 600, 900};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {30, 65, 90};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 25;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 680;
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
	int t0[] = {250, 550, 950};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10, 25, 40};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 75;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1736;
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
	int t0[] = {256, 512, 1024};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {35, 30, 25};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 0;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1216;
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
	int t0[] = {300, 600, 1100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {80, 90, 100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 4;
	SRMCodingPhase * obj = new SRMCodingPhase();
	clock_t start = clock();
	int my_answer = obj->countScore(p0, p1, p2);
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

