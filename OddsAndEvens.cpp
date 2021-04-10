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

class OddsAndEvens {
public:
	string find(vector <string>, vector <string>);
};

int getOdd(int x)
{
	int c = 0;
	while (x > 0)
	{
		if (x&1) c++;
		x >>= 1;
	}
	return c;
}

vector<int> calcPar(int x, int N)
{
	int d[N];
	for (int i = 0; i < N; i++)
	{
		d[i] = x&(1<<i) ? 1 : 0; // d[i]==0 iff digit i is even
	}
	vector<int> par(4, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			// sums
			par[0] += (d[i]+d[j])%2 == 0 ? 1 : 0;
			par[1] += (d[i]+d[j])%2 == 1 ? 1 : 0;
			par[2] += (d[i]*d[j])%2 == 0 ? 1 : 0;
			par[3] += (d[i]*d[j])%2 == 1 ? 1 : 0;
		}
	}
	return par;
}
	
string OddsAndEvens::find(vector <string> sums, vector <string> products) 
{
	int P = sums.size();
	int N = (1+(int)sqrt((double)(1+4*1*2*P)))/2;
	//cout << "P " << P << " N " << N << endl;
	
	vector<int> par(4, 0);
	for (int i = 0; i < P; i++)
	{
		if (sums[i] == "EVEN") par[0]++; else par[1]++;
		if (products[i] == "EVEN") par[2]++; else par[3]++;
	}
	
	for (int i = 0; i < (1<<N); i++)
	{
		vector<int> v = calcPar(i, N);
		if (v == par)
		{
			char buf[100];
			sprintf(buf, "EVEN %d ODD %d", N-getOdd(i), getOdd(i));
			return string(buf);
		}
	}
	return "IMPOSSIBLE";	
}


double test0() {
	string t0[] = {"EVEN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ODD"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	OddsAndEvens * obj = new OddsAndEvens();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "EVEN 0 ODD 2";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"ODD"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ODD"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	OddsAndEvens * obj = new OddsAndEvens();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "IMPOSSIBLE";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"EVEN","EVEN","EVEN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"EVEN","EVEN","EVEN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	OddsAndEvens * obj = new OddsAndEvens();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "EVEN 3 ODD 0";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"EVEN","ODD","ODD"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ODD","EVEN","EVEN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	OddsAndEvens * obj = new OddsAndEvens();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "EVEN 1 ODD 2";
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
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test4() {
	string t0[] = {"ODD","EVEN","ODD","EVEN","ODD","EVEN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"ODD","EVEN","EVEN","EVEN","ODD","ODD"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	OddsAndEvens * obj = new OddsAndEvens();
	clock_t start = clock();
	string my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "EVEN 1 ODD 3";
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
