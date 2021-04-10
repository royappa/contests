#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


//https://www.hackerrank.com/contests/juniper-codesprint/challenges/leonardo-and-substring

typedef long long LL;

int main()
{
	int testCases;
	cin >> testCases;
	while (testCases-- > 0)
	{
		string s;
		cin >> s;
		int n = s.size();
		vector<int> b;
		b.push_back(0); // a boundary starts at 0
		for (int i = 1; i < n; i++)
		{
			if (s[i] != s[i-1])
			{
				// i is a boundary if
				if (i+1 < n && s[i+1] == s[i]) // transitioning to a new "run" of a different type, or from non-run to run
				{
					b.push_back(i);
				}
				else if (i >= 2 && s[i-1] == s[i-2]) // transition from run to non-run
				{
					b.push_back(i);
				}
			}
		}
		b.push_back(n);
		int m = b.size();
		LL num = 0;
		for (int i = 1; i < m; i++)
		{
			LL len = b[i]-b[i-1];
			if (len == 1)
				num++;
			else if (s[b[i-1]] != s[b[i-1]+1])
				num += len*(len+1)/2;
			else
				num += len;
		}
		cout << num << endl;
	}
    return 0;
}
