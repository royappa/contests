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

class ReportAccess {
public:
	vector <string> whoCanSee(vector <string>, vector <string>, vector <string>);
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

vector <string> ReportAccess::whoCanSee(vector <string> u, vector <string> a, vector <string> r) 
{
	vector<string> can;
	
	for (int i = 0; i < u.size(); i++)
	{
		vector<string> w = split_nonre(a[i], " ");
		bool all = true;
		for (int j = 0; j < r.size(); j++)
		{
			bool found = false;
			for (int k = 0; k < w.size(); k++)
			{
				if (w[k] == r[j])
				{
					found = true;
					break;
				}
			}
			if (!found)
			{
				all = false;
				break;
			}
		}
		if (all)
		{
			can.push_back(u[i]);
		}
	}
	sort(can.begin(), can.end());
	return can;
}

double test0() {
	string t0[] = {"joe", "nick", "ted"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"clients products", "products orders", "clients orders"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"clients", "products"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ReportAccess * obj = new ReportAccess();
	clock_t start = clock();
	vector <string> my_answer = obj->whoCanSee(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t3[] = {"joe" };
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<"\""<<p3[0]<<"\"";
		for (int i=1; i<p3.size(); i++)
			cout <<", \"" <<p3[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test1() {
	string t0[] = {"kathy", "john", "dan", "steve", "cheryl", "tony"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"users data", "data orders", "users permissions", "system users controls", "default", "admin users"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"users"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ReportAccess * obj = new ReportAccess();
	clock_t start = clock();
	vector <string> my_answer = obj->whoCanSee(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t3[] = {"dan", "kathy", "steve", "tony" };
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<"\""<<p3[0]<<"\"";
		for (int i=1; i<p3.size(); i++)
			cout <<", \"" <<p3[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;	//I want to eventually turn this into a time of some kind.
	}
}
double test2() {
	string t0[] = {"jim", "scott", "barbara"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"users order products", "products shipping", "tracking products orders"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"admin"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ReportAccess * obj = new ReportAccess();
	clock_t start = clock();
	vector <string> my_answer = obj->whoCanSee(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t3[] = { };
	vector <string> p3(t3, t3+sizeof(t3)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<"\""<<p3[0]<<"\"";
		for (int i=1; i<p3.size(); i++)
			cout <<", \"" <<p3[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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
