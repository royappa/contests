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

typedef long long LL;

class PastingPaintingDivTwo {
public:
long long countColors(vector <string> p, int T) 
{
	LL x = 0;
	int n = p.size();
	for (int i = 0; i < n; i++)
		x += p[i][0] == 'B';
	for (int i = 0; i < p[0].size(); i++)
		x += p[0][i] == 'B';
	if (p[0][0] == 'B')
		x--;
	
	LL z = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < p[0].size(); j++)
		{
			z += p[i][j] == 'B';
		}
	}
	return (T-1)*x+z;
		
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {
"..B",
"B..",
"BB."
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 10LL;
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
	string t0[] = {
"B...",
"....",
"....",
"...B"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
	string t0[] = {"BBB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 30000LL;
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
	string t0[] = {"."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000000000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
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
	string t0[] = {
"BB.",
".B."
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 201LL;
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
	string t0[] = {
"..........B..........",
".........B.B.........",
"........B...B........",
".......B.....B.......",
"......B..B.B..B......",
".....B...B.B...B.....",
"....B...........B....",
"...B...B.....B...B...",
"..B.....BBBBBB....B..",
".B..........BB.....B.",
"BBBBBBBBBBBBBBBBBBBBB"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000000000;
	PastingPaintingDivTwo * obj = new PastingPaintingDivTwo();
	clock_t start = clock();
	long long my_answer = obj->countColors(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 21000000071LL;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

