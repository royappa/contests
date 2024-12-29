/*
ID: royappa1
LANG: C++
PROG: crypt1
*/
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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


bool match(int n, vector<int> &v)
{
	while (n > 0)
	{
		if (!v[n%10])
			return false;
		n /= 10;
	}
	return true;
}

int main ()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int N;
	vector<int> v(10,0);

	fin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		fin >> x;
		v[x] = 1;
	}

	int r = 0;
	for (int top = 100; top <= 999; top++)
	{
		if (!match(top, v)) continue;
		for (int bot = 10; bot <= 99; bot++)
		{
			int prod = top*bot;
			if (prod < 1000 || prod > 9999) continue;
			int pprod1 = top*(bot%10);
			if (pprod1 < 100 || pprod1 > 999) continue;
			int pprod2 = top*(bot/10);
			if (pprod2 < 100 || pprod2 > 999) continue;
			if (match(bot, v) && match(pprod1, v) && match(pprod2, v) && match(prod, v))
			{
				//cout << top << " " << bot << " " << prod << endl;
				r++;
			}
		}
	}
	fout << r << endl;
	fout.close();
	exit (0);
}
