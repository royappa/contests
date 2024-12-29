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

class CubeColoring {
public:
long long theCount(vector <string> v)
{
	int n = v[0].size();

	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[0][i] == 'N') continue;
		for (int j = 0; j < n; j++)
		{
			if (j == i || v[1][j] == 'N') continue;
			for (int k = 0; k < n; k++)
			{
				if (k == i || v[3][k] == 'N') continue;
				for (int w = 0; w < n; w++)
				{
					if (w == i || v[4][w] == 'N') continue;
					string s2 = v[2], s5 = v[5], s7 = v[7];
					s2[j] = s2[k] = 'N';
					s5[j] = s5[w] = 'N';
					s7[k] = s7[w] = 'N';
					LL num2, num5, num7;
					num2 = num5 = num7 = 0;
					for (int t = 0; t < n; t++)
					{
						num2 += s2[t] == 'Y';
						num5 += s5[t] == 'Y';
						num7 += s7[t] == 'Y';
					}
					for (int x = 0; x < n; x++)
					{
						if (v[6][x] == 'N') continue;
						tot += (num2-(s2[x]=='Y'))*(num5-(s5[x]=='Y'))*(num7-(s7[x]=='Y'));
					}
				}
			}
		}
	}
	return tot;
}
};


//Powered by [KawigiEdit]

double test0() {
	string t0[] = {"Y", "Y", "Y", "Y", "Y", "Y", "Y", "Y"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeColoring * obj = new CubeColoring();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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
	string t0[] = {"YNNNNNNN", "NYNNNNNN", "NNYNNNNN", "NNNYNNNN", "NNNNYNNN", "NNNNNYNN", "NNNNNNYN", "NNNNNNNY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeColoring * obj = new CubeColoring();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 1LL;
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
	string t0[] = {"YNNYN", "YYYYY", "NYYNY", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeColoring * obj = new CubeColoring();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 250LL;
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
	string t0[] = {"YNNYN", "YYYYY", "NNNNN", "YNYYN", "YNNYY", "YNNYY", "NNNYY", "NYYYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeColoring * obj = new CubeColoring();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 0LL;
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

double test4() {
	string t0[] = {"YNNYNYYYYYNN", "NNNYNYYNYNNY", "YYNNYYNNNYYN", "YYYYYNNYYYNN", "NNNYYYNNYNYN", "YYYNYYYYNYNN", "NNNNNNYYNYYN", "NNYNYYNNYNYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	CubeColoring * obj = new CubeColoring();
	clock_t start = clock();
	long long my_answer = obj->theCount(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p1 = 611480LL;
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

