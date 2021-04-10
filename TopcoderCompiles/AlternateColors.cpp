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

class AlternateColors {
public:
typedef long long LL;
string getColor(long long r, long long g, long long b, long long k) 
{
	vector<LL> cnt(3), ind(3);
	ind[0] = 0;
	ind[1] = 1;
	ind[2] = 2;
	cnt[0] = r;
	cnt[1] = g;
	cnt[2] = b;
	
	char *colors[] = {"RED", "GREEN", "BLUE"};
	
	int minpos = min_element(cnt.begin(), cnt.end())-cnt.begin();
	LL m = cnt[minpos];
	if (k <= 3*(m-1))
	{
		int p = (k-1)%3;
		return colors[ind[p]];
	}
cout <<"Here1 " << k << " " << m <<endl;
	k -= 3*(m-1);
	for (int i = 0; i < 3; i++)
	{
		cnt[i] -= (m-1);
	}
	int j = 0;
	while (k > 1 && j != minpos)
	{
		k--;
		j++;
		rotate(cnt.begin(), cnt.begin()+1, cnt.end());
		rotate(ind.begin(), ind.begin()+1, ind.end());
	}
	if (k == 1)
	{
		return colors[ind[k-1]];
	}
cout <<"Here2 " << k << " " << m <<endl;
	// position 0 has minpos
for (int j = 0; j < cnt.size(); j++) { cout << cnt[j] << " "; } cout << endl;
	cnt.erase(cnt.begin());
	ind.erase(ind.begin());
	k--;
	cnt[0]--;
	// now there are 2
	minpos = min_element(cnt.begin(), cnt.end())-cnt.begin();	
	m = cnt[minpos];
	if (k <= 2*(m-1))
	{
		int p = (k-1)%2;
		return colors[ind[p]];
	}
cout <<"Here3 " << k << " " << m <<endl;
	k -= 2*(m-1);
	for (int i = 0; i < 2; i++)
	{
		cnt[i] -= (m-1);
	}		
	j = 0;
	while (k > 1 && j != minpos)
	{
		k--;
		j++;
		rotate(cnt.begin(), cnt.begin()+1, cnt.end());
		rotate(ind.begin(), ind.begin()+1, ind.end());
	}
	cnt[0]--;
	if (k == 1)
	{
		return colors[ind[k-1]];
	}	
cout <<"Here4 " << k << " " << m <<endl;
	cnt.erase(cnt.begin());
	ind.erase(ind.begin());
	k--;
	return colors[ind[0]];	
}

};
//{1000000000000, 1000000000000, 1000000000000, 2999999999999}- GREEN is expected

//Powered by [KawigiEdit]
double test0() {
	long long p0 = 1LL;
	long long p1 = 1LL;
	long long p2 = 1LL;
	long long p3 = 3LL;
	AlternateColors * obj = new AlternateColors();
	clock_t start = clock();
	string my_answer = obj->getColor(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "BLUE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	long long p0 = 3LL;
	long long p1 = 4LL;
	long long p2 = 5LL;
	long long p3 = 4LL;
	AlternateColors * obj = new AlternateColors();
	clock_t start = clock();
	string my_answer = obj->getColor(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "RED";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	long long p0 = 7LL;
	long long p1 = 7LL;
	long long p2 = 1LL;
	long long p3 = 7LL;
	AlternateColors * obj = new AlternateColors();
	clock_t start = clock();
	string my_answer = obj->getColor(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "GREEN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test3() {
	long long p0 = 1000000000000LL;
	long long p1 = 1LL;
	long long p2 = 1LL;
	long long p3 = 1000000000002LL;
	AlternateColors * obj = new AlternateColors();
	clock_t start = clock();
	string my_answer = obj->getColor(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "RED";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test4() {
	long long p0 = 653LL;
	long long p1 = 32LL;
	long long p2 = 1230LL;
	long long p3 = 556LL;
	AlternateColors * obj = new AlternateColors();
	clock_t start = clock();
	string my_answer = obj->getColor(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "BLUE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

