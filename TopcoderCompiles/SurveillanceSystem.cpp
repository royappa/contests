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

#define typeof(x) auto

using namespace std;

class SurveillanceSystem {
public:
string getContainerInfo(string s, vector <int> v, int L) 
{
	int n = v.size();
	int m = s.size();
	map<int,int> counts;
	for (int i = 0; i < n; i++)
	{
		counts[v[i]]++;
	}
	string res(m, '-');
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j+L <= m; j++)
		{
			if (count(s.begin()+j, s.begin()+j+L, 'X') == v[i])
			{
				res.replace(j, L, string(L, '?'));
			}
		}
	}
	for (typeof(counts.begin()) it = counts.begin(); it != counts.end(); it++)
	{
		int numCameras = it->second;
		for (int i = 0; i < m; i++)
		{
			// check if s[i] MUST be under surveillance
			int k = 0;
			for (int j = 0; j+L <= m; j++)
			{
				if (count(s.begin()+j, s.begin()+j+L, 'X') == it->first)
				{
					if (i < j || i >= j+L)
					{
						k++;
					}
				}
			}
			if (k < numCameras)
			{
				res[i] = '+';
			}
		}
	}	
	return res;
}

};


//Powered by [KawigiEdit]

double test0() {
	string p0 = "-X--XX";
	int t1[] = {1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "??++++";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "-XXXXX-";
	int t1[] = {2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-???";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "------X-XX-";
	int t1[] = {3, 0, 2, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 5;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "++++++++++?";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "-XXXXX---X--";
	int t1[] = {2, 1, 0, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 3;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???-??++++??";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string p0 = "-XX--X-XX-X-X--X---XX-X---XXXX-----X";
	int t1[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 7;
	SurveillanceSystem * obj = new SurveillanceSystem();
	clock_t start = clock();
	string my_answer = obj->getContainerInfo(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "???++++?++++++++++++++++++++??????--";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

