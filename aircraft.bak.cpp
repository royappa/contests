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

class Aircraft {
public:


typedef long long LL;
#define S(x) ((x)*(x))

string nearMiss(vector <int> p1, vector <int> v1, vector <int> p2, vector <int> v2, int R)
{
	LL r = R;

	LL p[3], v[3];
	for (int i = 0; i < 3; i++)
	{
		p[i] = p1[i]-p2[i];
		v[i] = v1[i]-v2[i];
	}
	LL C[3][3];
	for (int i = 0; i < 3; i++)
	{
		//p[i]+v[i]*t
		C[i][0] = S(v[i]);
		C[i][1] = 2LL*p[i]*v[i];
		C[i][2] = S(p[i]);
	}
	LL a = C[0][0]+C[1][0]+C[2][0];
	LL b = C[0][1]+C[1][1]+C[2][1];
	LL c = C[0][2]+C[1][2]+C[2][2]-S(r);

	cout << a << " " << b << " " << c << endl;
	if (a == 0)
	{
		if (b == 0)
		{
			return "NO";
		}
		return b*(-c) < 0 ? "NO" : "YES";
	}

	if (b*b-4*a*c < 0)
		return "NO";

	double t1 = (-b+sqrt(b*b-4*a*c))/(2*a);
	double t2 = (-b-sqrt(b*b-4*a*c))/(2*a);
	return (t1 < 0 && t2 < 0) ? "NO" : "YES";
}

};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {15,50,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {25,1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {161,102,9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-10,-10,-1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 10;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	int t0[] = {0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,2,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {9,0,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-2,2,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 5;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	int t0[] = {0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-2,2,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {9,0,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,2,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 5;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	int t0[] = {-2838,-7940,-2936};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,1,-2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {532,3850,9590};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,0,-3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 3410;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	int t0[] = {-8509,9560,345};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-89,-33,62};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-5185,-1417,2846};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-58,24,26};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 8344;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test5() {
	int t0[] = {-7163,-371,-2459};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-59,-41,-14};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-2398,-426,-5487};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-43,27,67};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 5410;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test6() {
	int t0[] = {1774,-4491,7810};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-12,19,-24};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2322,3793,9897};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-12,19,-24};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 10000;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test7() {
	int t0[] = {3731,8537,5661};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {-70,71,32};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8701,-1886,-5115};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {28,-13,7};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 9766;
	Aircraft * obj = new Aircraft();
	clock_t start = clock();
	string my_answer = obj->nearMiss(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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

	if (argc < 2 || atoi(argv[1]) == 6) {
		time = test6();
		if (time < 0.0)
			errors = true;
	}

	if (argc < 2 || atoi(argv[1]) == 7) {
		time = test7();
		if (time < 0.0)
			errors = true;
	}

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

