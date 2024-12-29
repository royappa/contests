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

class PaternityTest {
public:

bool possFather(string father, string child, string mother)
{
	int n = father.size();
	int momask = 0;
	for (int i = 0; i < n; i++)
	{
		if (mother[i] == child[i])
			momask |= (1<<i);
	}
	for (int m = 0; m < (1<<n); m++)
	{
		int bc = __builtin_popcount(m);
		if (bc != n/2)
			continue;
		bool ok = true;
		for (int i = 0; i < n; i++)
		{
			if ((m & (1<<i)) == 0) continue;
			if ((m & (1<<i)) != 0 && father[i] == child[i]) continue;
			ok = false;
			break;
		}
		if (ok) // father matches these n/2 bits
		{
			// check if mother matches the other n/2
			if (__builtin_popcount(momask & ~m) == n/2)
				return true;
		} 
	}
	return false;
}

vector <int> possibleFathers(string child, string mother, vector <string> men) 
{
	vector<int> r;
	for (int i = 0; i < men.size(); i++)
	{
		if (possFather(men[i], child, mother))
		{
			r.push_back(i);
		}
	}
	return r;	
}
};


//Powered by [KawigiEdit]
double test0() {
	string p0 = "ABCD";
	string p1 = "AXCY";
	string t2[] = { "SBTD", "QRCD" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string p0 = "ABCD";
	string p1 = "ABCX";
	string t2[] = { "ABCY", "ASTD", "QBCD" } ;
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  2 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string p0 = "ABABAB";
	string p1 = "ABABAB";
	string t2[] = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 0,  1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	string p0 = "YZGLSYQT";
	string p1 = "YUQRWYQT";
	string t2[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	string p0 = "WXETPYCHUWSQEMKKYNVP";
	string p1 = "AXQTUQVAUOSQEEKCYNVP";
	string t2[] = { "WNELPYCHXWXPCMNKDDXD",
  "WFEEPYCHFWDNPMKKALIW",
  "WSEFPYCHEWEFGMPKIQCK",
  "WAEXPYCHAWEQXMSKYARN",
  "WKEXPYCHYWLLFMGKKFBB" };
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	PaternityTest * obj = new PaternityTest();
	clock_t start = clock();
	vector <int> my_answer = obj->possibleFathers(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = { 1,  3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
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
	if (my_answer != p3) {
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

