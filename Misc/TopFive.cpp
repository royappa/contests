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

class TopFive {
public:
	double findProbability(vector <string>, vector <string>, int);
};

double calcProb(string r, string a, int p)
{
	int ra, rb, rc;
	int aa, ab, ac;
	sscanf(r.c_str(), "%d %d %d", &ra, &rb, &rc);
	sscanf(a.c_str(), "%d %d %d", &aa, &ab, &ac);
	
	// a
	// b
	// c
	// a,b
	// a,c
	// b,c
	// a,b,c
	
	double pa = (ra >= p) ? aa : 0; pa /= 100.0;
	double pb = (rb >= p) ? ab : 0; pb /= 100.0;
	double pc = (rc >= p) ? ac : 0; pc /= 100.0;
	double pab = (ra+rb >= p) ? aa*ab : 0; pab /= 10000.0;
	double pac = (ra+rc >= p) ? aa*ac : 0; pac /= 10000.0;
	double pbc = (rb+rc >= p) ? ab*ac : 0; pbc /= 10000.0;
	double pabc = (ra+rb+rc >= p) ? aa*ab*ac : 0; pabc /= 1000000.0;
	return (pa+pb+pc+pab+pac+pbc+pabc)/6.0;
}
	
double TopFive::findProbability(vector <string> results, vector <string> accuracies, int points) 
{
	vector<double> prob;
	
	for (int i = 0; i < results.size(); i++)
	{
		prob.push_back(calcProb(results[i], accuracies[i], points));
	}
	for (int i = 0; i < results.size(); i++) cout << prob[i] << endl;
	sort(prob.begin(), prob.end());
		
	reverse(prob.begin(), prob.end());
	int n = prob.size();
	if (n < 5)
	{
		return 1.0;
	}
	else if (abs(prob[4]-100.0) <= 1e-9)
	{
		return 0.0;
	}
	double prod = 1.0;
	
	for (int k = 4; k >= 0; k++)
	{
		if (abs(prob[k]) < 1e-9)
		{
			break;
		}
		prod *= prob[k];
	}
	
	return 1.0-prod;
	
}
double test0() {
	string t0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"0 0 50"
};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 100;
	TopFive * obj = new TopFive();
	clock_t start = clock();
	double my_answer = obj->findProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.5;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 100;
	TopFive * obj = new TopFive();
	clock_t start = clock();
	double my_answer = obj->findProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.0;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"928 209 594", "547 408 596", "190 865 494", "353 392 962", "6 252 267",
 "817 671 562", "631 78 290", "593 292 312", "59 51 286", "553 541 487",
 "466 318 271", "605 892 562", "596 261 63", "865 895 625", "893 479 586",
 "759 596 476", "157 407 819", "509 695 861", "696 730 430", "271 221 0",
 "922 296 640", "999 456 654", "320 550 805", "835 808 711", "9 161 670",
 "82 737 480", "939 12 363"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"84 87 72", "39 60 84", "56 78 48", "0 80 59", "11 69 94",
 "100 53 77", "87 77 55", "0 67 7", "89 63 3", "4 69 99", 
"58 9 49", "81 8 84", "81 85 55", "84 68 28", "7 1 46", 
"30 50 51", "16 82 8", "60 17 88", "44 30 67", "20 65 65", 
"40 75 73", "38 97 20", "82 38 88", "90 78 58", "58 30 66",
 "3 95 50", "76 60 57"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 1623;
	TopFive * obj = new TopFive();
	clock_t start = clock();
	double my_answer = obj->findProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.8657569451352308;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"600 600 600"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"100 100 100",
"100 100 100",
"100 100 100",
"100 100 100",
"75 75 75"
};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 500;
	TopFive * obj = new TopFive();
	clock_t start = clock();
	double my_answer = obj->findProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.015625;
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	string t0[] = {"200 200 200",
"200 200 200",
"200 200 200",
"200 200 200",
"33 33 33",
"33 200 200"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"100 0 0",
"0 0 100",
"0 100 0",
"100 100 100",
"100 100 100",
"33 80 50"
};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int p2 = 200;
	TopFive * obj = new TopFive();
	clock_t start = clock();
	double my_answer = obj->findProbability(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 0.10000000000000009;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
