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

class Doorknobs {
public:
	int shortest(vector <string>, int);
};

int Doorknobs::shortest(vector <string> house, int doorknobs) 
{
	vector<int> cards(13);
	for (int i = 0; i < 13; i++)
		cards[i] = i;
	int count = 0, total = 0;
	while (next_permutation(cards.begin(), cards.end()))
	{
		count++;
	
		total++;
	}
	printf("total is %d\n", total);
	return 0;
}

double test0() {
	string t0[] = {"....."
,"o...."
,"o...."
,"o...."
,"...o."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"....."
,"o...."
,"o...."
,"o...."
,"...o."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {".#..."
,"#...."
,"...oo"
,"...oo"
,"...oo"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"...o."
,"o..o."
,"....."
,"..oo."
,"....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	string t0[] = {"....#"
,".##o#"
,".##oo"
,"o##.#"
,"....#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 12;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test5() {
	string t0[] = {"....#"
,"o##o#"
,".##oo"
,".##.#"
,"....#"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test6() {
	string t0[] = {".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"...................o.............................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"........................................o........."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,"..........o......................................."
,".................................................."
,".................................................."
,".................................................."
,".....................................o............"
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."
,".................................................."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	Doorknobs * obj = new Doorknobs();
	clock_t start = clock();
	int my_answer = obj->shortest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 106;
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
