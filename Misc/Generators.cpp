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

class Generators {
public:
	vector <int> find(int);
};


int powmod(int b, int pow, int p)
{
	if (pow == 0)
	{
		return 1;
	}
	if (pow == 1)
	{
		return b % p;
	}

	int powL = pow / 2;
	int bpL = powmod(b, powL, p);
	long long prod = bpL * bpL;	
	if (pow % 2 == 1)
	{
		prod *= b;
	}
	return (int) (prod % p);
}
	
vector <int> Generators::find(int p) 
{
	vector<int> gen;
	for (int a = 1; a <= p-1; a++)
	{
		vector<int> counts(p, 0); 
		
		for (int pow = 0; pow <= p-2; pow++)
		{
			int ap = powmod(a, pow, p);
			counts[ap]++;
		}
		bool eq = true;
		for (int k = 1; k <= p-1; k++)
		{
			if (counts[k] != 1)
			{
				eq = false;
				break;
			}
		}
		if (eq)
		{
			gen.push_back(a);
		}
	}
	return gen;	
}
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
