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

class ATaleOfThreeCities {
public:
	double connect(vector <int>, vector <int>, vector <int>, vector <int>, vector <int>, vector <int>);
};


double dist(int p, int q)
{
	return (double) sqrt((double)p)+ (double) sqrt((double) q);
}

int getBest(vector<int> ax, vector<int> ay, vector<int> bx, vector<int> by)
{
	int n = ax.size(), m = bx.size();
	
	int d2 = 1000000000;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			d2 = min(d2, (bx[j]-ax[i])*(bx[j]-ax[i])+(by[j]-ay[i])*(by[j]-ay[i]));
		}
	}
	return d2;
}
	
double ATaleOfThreeCities::connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy) 
{
	int bestAB = 0, bestAC = 0, bestBC = 0;
	
	bestAB = getBest(ax, ay, bx, by);
	bestAC = getBest(ax, ay, cx, cy);
	bestBC = getBest(bx, by, cx, cy);
	//printf("%d %d %d\n", bestAB, bestAC, bestBC);
	
	int a = bestAB+bestAC, b = bestAB+bestBC, c = bestAC+bestBC;
	
	if (a <= b && a <= c)
	{
		return dist(bestAB, bestAC);
	}
	else if (b <= a && b <= c)
	{
		return dist(bestAB, bestBC);
	}
	return dist(bestAC, bestBC);
}

double test0() {
	int t0[] = {0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,5};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {3,28};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	ATaleOfThreeCities * obj = new ATaleOfThreeCities();
	clock_t start = clock();
	double my_answer = obj->connect(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p6 = 3.414213562373095;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	int t0[] = {-2,-1,0,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,0,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-2,-1,0,1,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1,1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {-2,-1,0,1,2};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {2,2,2,2,2};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	ATaleOfThreeCities * obj = new ATaleOfThreeCities();
	clock_t start = clock();
	double my_answer = obj->connect(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p6 = 2.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	int t0[] = {4,5,11,21,8,10,3,9,5,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {12,8,9,12,2,3,5,7,10,13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {34,35,36,41,32,39,41,37,39,50};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {51,33,41,45,48,22,33,51,41,40};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {86,75,78,81,89,77,83,88,99,77};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {10,20,30,40,50,60,70,80,90,100};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	ATaleOfThreeCities * obj = new ATaleOfThreeCities();
	clock_t start = clock();
	double my_answer = obj->connect(p0, p1, p2, p3, p4, p5);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p6 = 50.323397776611024;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p6 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p6 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
