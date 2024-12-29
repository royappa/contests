#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


//https://www.hackerrank.com/contests/hourrank-6/challenges/bear-and-workbook

typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> t(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	int num = 0;
	int page = 0;
	for (int i = 0; i < n; i++)
	{
		page++;
		for (int prob = 1; prob <= t[i]; prob++)
		{
			if (prob == page) num++;
			if (prob == k) page++;
		}
	}
	cout << num << endl;
    return 0;
}
