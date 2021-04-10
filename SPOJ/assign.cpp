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
typedef long long LL;

int A[20][20];
int Ac[20];

int n;
LL memo[1100000];
int bc[1100000];

char buf[100];

int p[20];

int main()
{
	int test;
	gets(buf);
	sscanf(buf, "%d", &test);
	int m = 1<<20;

	for (int i = 0; i < m; i++)
	{
		int c = 0;
		for (int j = 0; j < 20; j++)
		{
			if (i & (1<<j))
			{
				c++;
			}
		}
		bc[i] = c;
	}


	while (test-- > 0)
	{
		gets(buf);
		sscanf(buf, "%d", &n);
		for (int i = 0; i < n; i++)
		{
			gets(buf);
			int rowMask = 0;
			char *s = buf;
			while (*s)
			{
				if (*s == '1')
				{
					rowMask |= (1<<((s-buf)>>1));
				}
				s++;
			}
			Ac[i] = rowMask;
		}

		memo[(1<<n)-1] = 1;
		for (int mask = (1<<n)-1; mask >= 0; mask--)
		{
			int row = bc[mask];
			LL r = 0LL;
			if (row == n)
			{
				r = 1;
			}
			else
			{
				r = 0LL;
				int m = Ac[row] & ~mask; // want to iterate through all possible, unused positions (1 in Ac[row] & 0 in mask)
				while (m != 0)
				{
					int mc = m & (m-1);
					int bit = m ^ mc;

					r += memo[mask | bit];
					m = mc;

				}
			}
			memo[mask] = r;
		}
		printf("%lld\n", memo[0]);
	}
	return 0;
}
