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

class NetworkXOneTimePad {
public:

int crack(vector <string> p, vector <string> c) 
{
	int np = p.size(), nc = c.size();
	set<string> s;
	for (int i = 0; i < nc; i++)
	{
		set<string> t;
		for (int j = 0; j < np; j++)
		{
			string q = "";
			for (int k = 0; k < p[0].size(); k++)
			{
				int a = c[i][k]-'0', b = p[j][k]-'0';
				int c = !(a^b);
				q += char('0'+c);
			}
			t.insert(q);
		}
		if (i == 0)
			s = t;
		else
		{
			set<string> v;
			set_intersection(s.begin(), s.end(), t.begin(), t.end(), insert_iterator<set <string> >(v, v.begin()));
			s = v;
		}
	}
	return s.size();
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {"110", "001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"101", "010"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
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

double test1() {
	string t0[] = {"00", "01", "10", "11"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00", "01", "10", "11"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	string t0[] = {"01", "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
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

double test3() {
	string t0[] = {"000", "111", "010", "101", "110", "001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"011", "100"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NetworkXOneTimePad * obj = new NetworkXOneTimePad();
	clock_t start = clock();
	int my_answer = obj->crack(p0, p1);
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

