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

class CollectingStamps {
public:
int maximumCount(vector <int> count, vector <int> sell, vector <int> buy) 
{
	int money = 0;
	sort(buy.begin(), buy.end());
	int keep = 0;
	for (int i = 0; i < count.size(); i++)
	{
		if (sell[i] > buy[0])
			money += sell[i]*count[i];
		else
			keep += count[i];
	}
	return money/buy[0]+keep;	
}
};


//Powered by [KawigiEdit]

double test0() {
	int t0[] = {100,100};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,99};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CollectingStamps * obj = new CollectingStamps();
	clock_t start = clock();
	int my_answer = obj->maximumCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5050;
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
	int t0[] = {1,2,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,4,3,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CollectingStamps * obj = new CollectingStamps();
	clock_t start = clock();
	int my_answer = obj->maximumCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 15;
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
	int t0[] = {6,6,2,4,10,4,4,8,1,6}
;
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,5,2,12,10,6,4,4,5,4}
;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {7,16,13,18,11,15,8,9,18,10}
;
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CollectingStamps * obj = new CollectingStamps();
	clock_t start = clock();
	int my_answer = obj->maximumCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 58;
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

double test3() {
	int t0[] = {3,4,2,1,4,1,1,3,1,4,3,2,5,1,2,3,4,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {12,5,12,4,6,2,2,2,2,3,2,5,3,19,15,8,4,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {19,16,17,20,19,17,15,5,10,18,8,17,10,22,20,17,6,20};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CollectingStamps * obj = new CollectingStamps();
	clock_t start = clock();
	int my_answer = obj->maximumCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 63;
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

double test4() {
	int t0[] = {28,29,32,32,33,26,6,6,31,14,12,19,20,29,15,20,25,30,13,24,30,14,24,22,
 1,4,21,17,4,14,25,23,9,25,25,4,19,8,29,16,18,22,20,9,9,18,18,9,8,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {17,83,12,21,53,21,12,7,23,82,77,16,9,28,49,25,17,42,45,82,50,9,15,64,79,
 34,4,40,69,21,40,2,24,53,9,63,8,21,55,26,5,43,55,25,42,3,23,17,10,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {85,90,20,36,88,46,18,88,100,99,86,34,50,93,61,41,98,75,53,96,84,91,59,99,99,
 39,15,91,99,72,83,12,37,75,14,66,38,69,99,98,12,92,78,79,89,63,42,48,40,42};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	CollectingStamps * obj = new CollectingStamps();
	clock_t start = clock();
	int my_answer = obj->maximumCount(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2565;
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

