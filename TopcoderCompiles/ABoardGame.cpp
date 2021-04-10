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

class ABoardGame {
public:

int pieces(vector<string> &v, int reg, char which)
{
	int N = v.size()/2;
	int c = 0;
	for (int x = N-reg; x <= N+reg-1; x++)
	{
		for (int y = N-reg; y <= N+reg-1; y++)
		{
			if (x == N-reg || x == N+reg-1 || y == N-reg || y == N+reg-1)
			{
				c += v[x][y] == which;
			}
		}
	}
	return c;
}

string whoWins(vector <string> v) 
{
	int N = v.size()/2;
	for (int i = 1; i <= N; i++)
	{
		int a = pieces(v, i, 'A');
		int b = pieces(v, i, 'B');
		if (a != b)
			return a > b ? "Alice" : "Bob";
	}
	return "Draw";
}

};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {".....A",
 "......",
 "..A...",
 "...B..",
 "......",
 "......"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string t0[] = {"AAAA",
 "A.BA",
 "A..A",
 "AAAA"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string t0[] = {"..",
 ".."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	string t0[] = {"BBB..BAB...B.B",
 ".AAAAAAAAAAAA.",
 "AA.AA.AB..A.AB",
 "..........B.AB",
 ".A..BBAB.A.BAB",
 ".AB.B.......A.",
 ".A..A.AB.A..AB",
 ".ABAA.BA...BA.",
 "BAAAB.....ABA.",
 ".A....B..A..B.",
 "B...B....B..A.",
 "BA.B..A.ABA.A.",
 "BAAAA.AAAAA.A.",
 "B.B.B.BB.B...."}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Alice";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	string t0[] = {"..A..AAA..AA",
 "ABABB..AAAAA",
 "ABBBBBBBBBA.",
 "AABBBABABBAA",
 "...BABABABBA",
 "B.BA..A.BBA.",
 "AA.A..B.AB.B",
 "..BA.B.AABAA",
 "..ABABBBABA.",
 ".ABB.BBBBBAA",
 "ABAAA.AA.A.A",
 "A..AAA.AAA.A"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Bob";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	string t0[] = {"B..ABAABBB",
 "B.........",
 "A..A.AA..B",
 "A.BBBAA..A",
 "B.AAAAB...",
 "A..BBBBB.A",
 "B..ABAABBA",
 "A......B.B",
 "B......A.A",
 "BA.AABBB.A"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	ABoardGame * obj = new ABoardGame();
	clock_t start = clock();
	string my_answer = obj->whoWins(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "Draw";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
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

