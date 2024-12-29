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

class GolfScore {
public:
int tally(vector <int> parValues, vector <string> scoreSheet) 
{
		char *s[] = {
		"triple bogey",
		"double bogey",
		"bogey"      ,
		"par"        ,
		"birdie"     ,
		"eagle"      ,
		"albatross"  ,
		"hole in one"};
		vector<string> vs(s, s+8);
		int score = 0;

		for (int i = 0; i < scoreSheet.size(); i++)
		{
			int p = find(vs.begin(), vs.end(), scoreSheet[i])-vs.begin();
			score += p==7 ? 1 : parValues[i]-(p-3);
		}
		return score;
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {1, 1, 1, 1, 1, 1,
 1, 1, 1, 5, 5, 5,
 5, 5, 5, 5, 5, 5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"bogey", "bogey", "bogey", "bogey", "bogey", "bogey",
 "bogey", "bogey", "bogey", "eagle", "eagle", "eagle",
 "eagle", "eagle", "eagle", "eagle", "eagle", "eagle"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GolfScore * obj = new GolfScore();
	clock_t start = clock();
	int my_answer = obj->tally(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 45;
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
	int t0[] = {3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"bogey", "double bogey", "par", "double bogey", "double bogey", "triple bogey",
 "triple bogey", "triple bogey", "bogey", "double bogey", "par", "par",
 "par", "double bogey", "bogey", "triple bogey", "bogey", "double bogey"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GolfScore * obj = new GolfScore();
	clock_t start = clock();
	int my_answer = obj->tally(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 72;
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
	int t0[] = {3, 2, 4, 2, 2, 1,
 1, 1, 3, 2, 4, 4,
 4, 2, 3, 1, 3, 2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"eagle", "birdie", "albatross", "birdie", "birdie", "par",
 "hole in one", "par", "eagle", "birdie", "albatross", "albatross",
 "albatross", "birdie", "eagle", "hole in one", "eagle", "birdie"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GolfScore * obj = new GolfScore();
	clock_t start = clock();
	int my_answer = obj->tally(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 18;
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
	int t0[] = {4, 1, 3, 3, 4, 4,
 1, 4, 2, 3, 3, 5,
 4, 1, 4, 4, 2, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"triple bogey", "triple bogey", "bogey", "par", "triple bogey", "double bogey",
 "triple bogey", "triple bogey", "par", "eagle", "bogey", "bogey",
 "birdie", "par", "triple bogey", "eagle", "triple bogey", "triple bogey"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GolfScore * obj = new GolfScore();
	clock_t start = clock();
	int my_answer = obj->tally(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 77;
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

