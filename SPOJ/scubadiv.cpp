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

int oxy[1001], nitro[1001], wt[1001];
#define INF (-2)

int memo[1001][22][80];

int best2(int n, int on, int nn)
{
	if (n == 0)
	{
		if (on == 0 && nn == 0)
		{
			return 0;
		}
		else
		{
			return INF;
		}
	}

	int & result = memo[n][on][nn];
	if (result != -1)
	{
		return result;
	}

	int a = best2(n-1, on, nn);
	int b = best2(n-1, max(0, on-oxy[n]), max(0, nn-nitro[n]));
	if (a == INF)
	{
		result = (b == INF ? INF : wt[n]+b);
	}
	else if (b == INF)
	{
		result = a;
	}
	else
	{
		result = min(a, wt[n]+b);
	}
	return result;
}

int best(int n, int on, int nn)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= on; j++)
		{
			for (int k = 0; k <= nn; k++)
			{
				if (i+j+k == 0)
				{
					memo[i][j][k] = 0;
				}
				else
				{
					memo[i][j][k] = INF;
				}
			}
		}
	}
	int m = 1;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= on; j++)
		{
			for (int k = 1; k <= nn; k++)
			{
				int a = memo[i-1][j][k];
				int b = memo[i-1][max(0,j-oxy[i])][max(0,k-nitro[i])];
				memo[i][j][k] = (a == INF ? (b == INF ? INF : wt[i]+b) : (b == INF ? a : min(a, wt[i]+b)));
			}
		}
	}

	if (debug)
	{
		for (int j = 0; j <= on; j++)
		{
			printf("%3d: ", j);
			for (int k = 0; k <= nn; k++)
			{
				printf("%3d ", memo[m][j][k]);
			}
			printf("\n");
		}
	}

	return memo[n][on][nn];
}

int main()
{
	int t;
	scanf("%d\n", &t);
	while (t-- > 0)
	{
		int n, on, nn;
		scanf("%d%d\n", &on, &nn);
		scanf("%d", &n);
		if (debug) printf("***\nn = %d on = %d nn = %d\n", n, on, nn);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d\n", &oxy[i], &nitro[i], &wt[i]);
			if (debug) printf("%d %d %d\n", oxy[i], nitro[i], wt[i]);
		}

		printf("%d\n", best(n, on, nn));
	}
	return 0;
}
