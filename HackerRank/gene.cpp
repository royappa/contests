#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


//https://www.hackerrank.com/contests/hourrank-6/challenges/bear-and-steady-gene

// partial credit solution :-/

typedef long long LL;

int main()
{
	int n;
	string s;
	cin >> n;
	cin >> s;

	int na = 0, nc = 0, nt = 0, ng = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'A') na++;
		else if (s[i] == 'C') nc++;
		else if (s[i] == 'T') nt++;
		else ng++;
	}

	int best = n+1;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			int len = j-i+1;
			int diff = abs(na-n/4)+abs(nc-n/4)+abs(nt-n/4)+abs(ng-n/4);
			if (len == diff/2)
				best = min(best, len);
		}
	}
	cout << best << endl;
}
