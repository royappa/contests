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

typedef vector<int> vi;

class BoxUnion {
public:
	int area(vector <string>);
	int s;
	
	vi strPoly(string ss)
	{
		int l,b,r,t;
		sscanf(ss.c_str(), "%d %d %d %d", &l, &b, &r, &t);
		vi p;
		p.push_back(l);
		p.push_back(b);
		p.push_back(r);
		p.push_back(t);
		return p;
	}
	
	int polyArea(vi p)
	{
		if (s >= p[1] && s <= p[3])
			return p[2]-p[1];
	}
	
	vi ins(vi pa, vi pb)
	{
		vi p;
		p.push_back(0); p.push_back(0); p.push_back(0); p.push_back(0);
		
		if (s >= pa[1] && s <= pa[3] && s <= pb[1] && s <= pb[3])
		{
			int al = pa[0], ar = pa[2], bl = pb[0], br = pb[2];		
			
			int il, ir;
			if (al >= bl && al <= br)
				il = al;
			else if (bl >= al && bl <= br)
				il = bl;
			else
				return p;
			if (ar >= bl && ar <= br)
				ir = ar;
			else
				ir = br;
			p.clear();
			p.push_back(il);
			p.push_back(0);
			p.push_back(ir);
			p.push_back(0);
			return p;
		}
		return p;
	}
		
};

int BoxUnion::area(vector<string> r) 
{
	int n = r.size();
	
	vi pa = strPoly(r[0]);
	vi pb = strPoly(r[1]);
	vi pc = strPoly(r[2]);
	
	int area = 0;
	for (s = 0; s < 20000; s++)
	{
		area += polyArea(pa)+polyArea(pb)+polyArea(pc) 
			- polyArea(ins(pa,pb))-polyArea(ins(pb,pc))-polyArea(ins(pa,pc))+
				polyArea(ins(ins(pa,pb),pc));	
	}
	return area;
}	
double test0() {
	string t0[] = { "200 300 203 304" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 12;
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
	string t0[] = { "0 0 10 10",
  "20 20 30 30" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 200;
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
	string t0[] = { "0 500 20000 501",
  "500 0 501 20000" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 39999;
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
	string t0[] = { "4 6 18 24",
  "7 2 12 19",
  "0 0 100 100" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 10000;
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
double test4() {
	string t0[] = { "1 3 5 6",
  "3 1 7 5",
  "4 4 9 7" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 35;
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
double test5() {
	string t0[] = { "0 0 20000 20000",
  "0 0 20000 20000",
  "0 0 20000 20000" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BoxUnion * obj = new BoxUnion();
	clock_t start = clock();
	int my_answer = obj->area(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 400000000;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
