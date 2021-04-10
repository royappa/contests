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
int debug = 0;

#define maxParties 100
#define maxBudget 500

int fee[maxParties+1], fun[maxParties+1];

int mf[maxBudget+1][maxParties+1];
int poss[maxBudget+1][maxParties+1];

int main()
{
	int b, n;
	scanf("%d%d", &b, &n);
	while (b+n != 0)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &fee[i], &fun[i]);
		}

		memset(mf, 0, sizeof(mf));
		memset(poss, 0, sizeof(poss));
		for (int i = 0; i <= n; i++)
		{
			poss[0][i] = 1;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= b; j++)
			{
				int x, y;
				x = poss[j][i-1] ? mf[j][i-1] : 0;
				y = j-fee[i] >= 0 && poss[j-fee[i]][i-1] ? mf[j-fee[i]][i-1]+fun[i] : 0;
				if (x+y > 0)
				{
					poss[j][i] = 1;
					mf[j][i] = max(x, y);
				}
			}
		}

		//mf[b][n] = max(mf[b][n-1], mf[b-fee[n]][n-1]+fun[n]);

		int bestBudget = 0, bestFun = 0;
		for (int j = 1; j <= b; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				if (poss[j][i] && mf[j][i] > bestFun)
				{
					bestFun = mf[j][i];
					bestBudget = j;
				}
			}
		}
		printf("%d %d\n", bestBudget, bestFun);
		scanf("%d%d", &b, &n);
	}
	return 0;
}
