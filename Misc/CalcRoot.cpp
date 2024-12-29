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

class CalcRoot {
public:


long long gcd (long long a, long long b)
{
	return b == 0LL? a : gcd(b, a%b);
}

string approximate(int N, int D) 
{
	// closest to sqrt(N) where den <= D
	
	double s = sqrt((double) N);
	double best = 1e99;
	
	long long bestNum = 0LL, bestDen = 0LL;
	
	for (int d = 2; d <= D; d++)
	{
		// calc num, den
		// sqrt calculation - stop when den > d
		long long prevNum = N;
		long long prevDen = 1LL;
		long long num=N;
		long long den=2LL;
		while (den <= (long long) d && (den != prevDen || num != prevNum))
		{
			cout << num << " " << den << " " << prevNum << " " << prevDen << endl;
			// prevans = ans
			prevNum = num;
			prevDen = den;
			
			// ans = (prevans + (n/prevans) ) / 2;
			num = 4LL*2LL*prevNum*prevNum+2LL*N*4LL*prevDen*prevDen;
			den = 4LL*4LL*prevNum*prevDen;
			
			long long g = gcd(num, den);
			num /= g;
			den /= g;
		}
		// save best
		num = prevNum;
		den = prevDen;
		double diff = abs(s - ( (double)num / (double)den ));
		if ( diff < best)
		{
			best = diff;
			bestNum = num;
			bestDen = den;
			cout << bestNum << " " << bestDen << " " << diff << endl;
		}			
		//cout << d << " " << bestNum << " " << bestDen << " " << diff << endl;
	}
	char buf[1000];
	int bn = (int) bestNum, bd = (int) bestDen;
	sprintf(buf, "%d/%d", bn, bd);
	string ret = buf;
	return ret;		
}

};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 4;
	int p1 = 10;
	CalcRoot * obj = new CalcRoot();
	clock_t start = clock();
	string my_answer = obj->approximate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "2/1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int p1 = 3;
	CalcRoot * obj = new CalcRoot();
	clock_t start = clock();
	string my_answer = obj->approximate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "7/3";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 12;
	int p1 = 10;
	CalcRoot * obj = new CalcRoot();
	clock_t start = clock();
	string my_answer = obj->approximate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "31/9";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 23743;
	int p1 = 763;
	CalcRoot * obj = new CalcRoot();
	clock_t start = clock();
	string my_answer = obj->approximate(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "98462/639";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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

