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
#include <stdio.h>
#include <ext/hash_map>	// NEED THIS


int debug = 1;
typedef long long LL;
char buf[10000];
using namespace std;

int best[6101][6101];

int f(string s)
{
	int len = s.size();

	if (len <= 1)
		return 0;

	int r;
	if (s[p] == s[p+len-1])
		r = f(p+1, len-2);
	else
		r = 1+min(f(p, len-1), f(p+1, len-1));

	for (int i = 0; i < 2; i++)
	{
		for (int p = 0; p < len; p++)
		{
			best[p][i] = 0;
		}
	}
	for (int i = 2; i <= len; i++)
	{
		for (int p = len-i; p >= 0; p--)
		{
			if (s[p] == s[p+i-1])
			{
				best[p][i] = best[p+1][i-2];
			}
			else
			{
				best[p][i] = 1+min(best[p][i-1], best[p+1][i-1]);
			}
		}
	}

	return best[0][len];
}

int main()
{
	int test;
	gets(buf);
	sscanf(buf, "%d", &test);
	for (int i = 0; i < test; i++)
	{
		gets(buf);
		printf("%d\n", f(string(buf)));
	}

	return 0;
}
