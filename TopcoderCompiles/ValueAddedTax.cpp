//return (find(food.begin(), food.end(), product) == food.end()) ? (double) price*1.18 : (double) price*1.10;	
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

class ValueAddedTax {
public:
double calculateFinalPrice(string product, int price, vector <string> food) 
{
	return find(food.begin(), food.end(), product) == food.end() ? price*1.18 : price*1.1;
}
};


//Powered by [KawigiEdit]
double test0() {
	string p0 = "milk";
	int p1 = 1;
	string t2[] = {"bread", "butter", "milk"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ValueAddedTax * obj = new ValueAddedTax();
	clock_t start = clock();
	double my_answer = obj->calculateFinalPrice(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 1.1;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test1() {
	string p0 = "car";
	int p1 = 100;
	string t2[] = {"bread", "butter", "milk"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ValueAddedTax * obj = new ValueAddedTax();
	clock_t start = clock();
	double my_answer = obj->calculateFinalPrice(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 118.0;
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
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test2() {
	string p0 = "abc";
	int p1 = 57;
	string t2[] = {"a", "b", "c"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ValueAddedTax * obj = new ValueAddedTax();
	clock_t start = clock();
	double my_answer = obj->calculateFinalPrice(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p3 = 67.25999999999999;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

