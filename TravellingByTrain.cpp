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

class TravellingByTrain {
public:
	string earliestArrival(vector <string>);
};

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) s.c_str();
	char *sepC = (char *) sep.c_str();

	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}
	
int hhmm(int hh, int mm)
{
	return hh*60+mm;
}

string TravellingByTrain::earliestArrival(vector <string> tt) 
{
		int n = tt.size();
		int time = hhmm(9, 0);
		for (int i = 0; i < n; i++)
		{
			// time = arrival at station i
			int locday = time / (24*60);
			int local = time - locday * 24*60;
			int lochh = local / 60;
			int locmm = local % 60;
			printf("%d:%d\n", lochh, locmm);
			vector<string> trains = split_nonre(tt[i], " ");
			
			// goal: determine possible train with earliest arrival at station i+1
			int first = 1000000000;
			for (int j = 0; j < trains.size(); j++)
			{
				int dhh, dmm, ahh, amm;
				sscanf(trains[j].c_str(), "%d:%d-%d:%d", &dhh, &dmm, &ahh, &amm);
				bool nextDay = false;
				if (hhmm(dhh, dmm) < hhmm(lochh, locmm))
				{
					nextDay = true;
				}
					
				if ((hhmm(dhh, dmm) >= hhmm(lochh, locmm)) || nextDay)
				{
					int next = hhmm(ahh, amm);
					if (hhmm(dhh, dmm) >= hhmm(ahh, amm))
					{
						next += 24*60;
					}
					if (nextDay)
					{
						next += 24*60;
					}
					first = min(first, next);
				}
			}
			time = locday*24*60 + first;
		}
		char buf[100];
		int day = time/(24*60);
		time -= day*(24*60);
		day++;
		sprintf(buf, "%02d:%02d, day %d", time/60, time%60, day);
		return buf;
}	

double test0() {
	string t0[] = {"10:00-13:00 12:00-15:00","11:00-16:00 14:00-19:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TravellingByTrain * obj = new TravellingByTrain();
	clock_t start = clock();
	string my_answer = obj->earliestArrival(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "19:00, day 1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"09:00-13:57","13:56-17:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TravellingByTrain * obj = new TravellingByTrain();
	clock_t start = clock();
	string my_answer = obj->earliestArrival(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "17:00, day 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"10:00-08:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TravellingByTrain * obj = new TravellingByTrain();
	clock_t start = clock();
	string my_answer = obj->earliestArrival(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "08:00, day 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test3() {
	string t0[] = {"09:10-11:00 09:05-10:05","10:10-12:00 11:00-11:05","17:00-08:00","09:00-08:00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TravellingByTrain * obj = new TravellingByTrain();
	clock_t start = clock();
	string my_answer = obj->earliestArrival(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "08:00, day 3";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
