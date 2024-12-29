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

class ColorfulBoxesAndBalls {
public:
int getMaximum(int numRed, int numBlue, int onlyRed, int onlyBlue, int bothColors) 
{
	int m = -(1<<30);
	for (int i = 0; i <= numRed; i++)
	{
		for (int j = 0; j <= numBlue; j++)
		{
			
			int score = i*onlyRed+j*onlyBlue;
			int redLeft = numRed-i;
			int blueLeft = numBlue-j;
			if (redLeft < blueLeft)
			{
				score += redLeft*bothColors*2;
				score += (blueLeft-redLeft)*onlyBlue;
			}
			else
			{
				score += blueLeft*bothColors*2;
				score += (redLeft-blueLeft)*onlyRed;
			}
			m >?= score;
		}
	}
	return m;
}
};


//Powered by [KawigiEdit]

double test0() {
	int p0 = 2;
	int p1 = 3;
	int p2 = 100;
	int p3 = 400;
	int p4 = 200;
	ColorfulBoxesAndBalls * obj = new ColorfulBoxesAndBalls();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 1400;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 2;
	int p1 = 3;
	int p2 = 100;
	int p3 = 400;
	int p4 = 300;
	ColorfulBoxesAndBalls * obj = new ColorfulBoxesAndBalls();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 1600;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 5;
	int p1 = 5;
	int p2 = 464;
	int p3 = 464;
	int p4 = 464;
	ColorfulBoxesAndBalls * obj = new ColorfulBoxesAndBalls();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 4640;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 1;
	int p1 = 4;
	int p2 = 20;
	int p3 = -30;
	int p4 = -10;
	ColorfulBoxesAndBalls * obj = new ColorfulBoxesAndBalls();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -100;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 9;
	int p1 = 1;
	int p2 = -1;
	int p3 = -10;
	int p4 = 4;
	ColorfulBoxesAndBalls * obj = new ColorfulBoxesAndBalls();
	clock_t start = clock();
	int my_answer = obj->getMaximum(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

