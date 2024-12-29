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

class HexagonalBoard {
public:
int minColors(vector <string> v) 
{
	int n = v.size();
	vector< vector<int> > vc(n);
	int cr[6] = {-1, -1, 0, 1,  1,  0};
	int cc[6] = { 0,  1, 1, 0, -1, -1};
	
	for (int i = 0; i < n; i++)
	{
		vector<int> z(n,-1);
		vc[i] = z;
	}

	int maxcol = 0;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (v[r][c] != 'X') continue;
			
			vector<int> colors(100,0);
			for (int i = 0; i < 6; i++)
			{
				int dr = cr[i], dc = cc[i];
				if (r+dr < 0 || r+dr >= n || c+dc < 0 || c+dc >= n) continue;
				int tr = r+dr, tc = c+dc;
				if (vc[tr][tc] != -1)
				{
					int d = vc[tr][tc];
					colors[d] = 1;
				}
			}
			int use = -1;
			for (int i = 0; i < maxcol; i++)
			{
				if (colors[i] == 0)
				{
					use = i;
					break;
				}
			}
			if (use == -1)
			{
				use = maxcol;			
				maxcol++;
			}
			vc[r][c] = use;
		}
	}
	
				 
	return maxcol;
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {"---",
 "---",
 "---"}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string t0[] = {"-X--",
 "---X",
 "----",
 "-X--"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string t0[] = {"XXXX",
 "---X",
 "---X",
 "---X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	string t0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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

