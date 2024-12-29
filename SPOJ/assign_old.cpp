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
LL memo[21][1100000];
int n;

unsigned char zpos[1100000][21];
unsigned char znum[1100000];

LL f(int row, int mask)
{
	if (row == n)
	{
		return 1LL;
	}
	LL& r = memo[row][mask];
	if (r != -1LL)
	{
		return r;
	}
	r = 0LL;
	for (int mi = 0; mi < znum[mask]; mi++)
	{
		int i = zpos[mask][mi];
		if (A[row][i])
		{
			r += f(row+1, mask | (1<<i));
		}
	}
	return r;
}

int main()
{
	int last_n = -1;
	int test;
	scanf("%d", &test);
	while (test-- > 0)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}

		if (n != last_n)
		{
			memset(zpos, 0, sizeof(zpos));
			memset(znum, 0, sizeof(znum));
			for (int m = 0; m < (1<<n); m++)
			{
				for (int i = 0; i < n; i++)
				{
					if (!(m & (1<<i)))
					{
						zpos[m][znum[m]++] = i;
					}
				}
			}
		}
		/* DP too slow because computes all items in memo (memoization bypasses lot of calcs even in all-1's case)
		memset(memo, 0LL, sizeof(memo));

		for (int m = 0; m < (1<<n); m++)
		{
			memo[n][m] = 1LL;
		}

		for (int row = n-1; row >= 0; row--)
		{
			for (int m = 0; m < (1<<n); m++)
			{
				LL r = 0LL;
				for (int i = 0; i < n; i++)
				{
					if (A[row][i]  && !(m & (1<<i)))
					{
						r += memo[row+1][m | (1<<i)];
					}
				}
				memo[row][m] = r;
			}
		}
		printf("%lld\n", memo[0][0]);
		*/

		memset(memo, -1LL, sizeof(memo));
		printf("%lld\n", f(0, 0));
		last_n = n;

	}
	return 0;
}
