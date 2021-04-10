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
#include <queue>

using namespace std;

int debug = 1;

char buf[1024*1024];

bool hasPeriod(char *s, int L, int k)
{
	if (L % k != 0)
	{
		if (debug) printf("** has(%d,%d) = false (1)\n", L, k);
		return false;
	}
	int r = L / k;
	for (int i = 1; i < k; i++)
	{
		char *p = s+i*r;
		for (int j = 0; j < r; j++)
		{
			if (p[j] != s[j])
			{
				if (debug) printf("** has(%d,%d) = false (2)\n", L, k);
				return false;
			}
		}
	}
	if (debug) printf("** has(%d,%d) = true\n", L, k);
	return true;
}

int period(char *s, int L)
{
	vector<int> poss;
	for (int d = 1; d*d <= L; d++)
	{
		poss.push_back(d);
		poss.push_back(L/d);
	}
	sort(poss.begin(), poss.end());
	poss.erase(unique(poss.begin(), poss.end()), poss.end());
	int n = poss.size();
	if (debug)
	{
		printf("*L = %d\n", L);
		for (int i = 0; i < n; i++)
		{
			printf("divisor %d\n", poss[i]);
		}
	}
	// max period of first L characters of s = min period
	int low = 0, high = n-1;
	int mid = 0;
	do
	{
		if (high > low+1)
		{
			mid = (low+high)/2;
			if (hasPeriod(s, L, poss[mid]))
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		else //high == low+1
		{
			if (hasPeriod(s, L, poss[high]))
			{
				mid = high;
				break;
			}
			mid = low;
			break;
		}
	} while (true);
	return L/poss[mid];
}

int main()
{
	int tt;

	gets(buf);
	sscanf(buf, "%d", &tt);
	for (int t = 1; t <= tt; t++)
	{
		gets(buf);
		int n;
		sscanf(buf, "%d", &n);
		gets(buf);

		printf("Test case #%d\n", t);
		for (int i = 2; i <= n; i++)
		{
			int k = period(buf, i);
			if (k > 1)
			{
				printf("%d %d\n", i, k);
			}
		}
		printf("\n");
	}

	return 0;
}
