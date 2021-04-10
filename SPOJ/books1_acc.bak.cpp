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

typedef long long LL;

LL best[510][510];
int p[510][510];
LL pages[510];

LL mx(LL a, LL b)
{
	return a >? b;
}

int main()
{
	int d;
	scanf("%d", &d);

	while (d-- > 0)
	{
		int M, K;
		scanf("%d%d", &M, &K);
		for (int i = 1; i <= M; i++)
		{
			scanf("%lld", &pages[i]);
		}
		if (debug)
		{
			printf("\n**\n");
			for (int i = 1; i <= M; i++)
			{
				printf("%5d", pages[i]);
			}
			printf("\n");
		}
		LL sums[501];
		sums[0] = 0;
		for (int j = 1; j <= M; j++)
		{
			sums[j] = sums[j-1]+pages[j];
		}
		memset(best, 0, sizeof(best));
		for (int m = 1; m <= M; m++)
		{
			best[1][m] = best[1][m-1]+pages[m];
			p[1][m] = 1;
		}
		for (int k = 2; k <= K; k++)
		{
			for (int j = k; j <= M; j++)
			{
				LL x = 1LL<<60;
				for (int i = k; i <= j; i++)
				{
					LL c = mx(best[k-1][i-1], sums[j]-sums[i-1]);
					if (c <= x)
					{
						x = c;
					}
				}
				best[k][j] = x;
			}
		}

		if (debug)
		{
			printf("best[%d][%d] = %lld\n", K, M, best[K][M]);
			for (int k = 1; k <= K; k++)
			{
				for (int j = 1; j <= M; j++)
				{
					printf("%5lld", best[k][j]);
				}
				printf("\n");
			}
			for (int k = 1; k <= K; k++)
			{
				for (int j = 1; j <= M; j++)
				{
					printf("%3d", p[k][j]);
				}
				printf("\n");
			}
		}

		LL b = best[K][M];
		for (int k = 2; k <= K; k++)
		{
			for (int j = k; j <= M; j++)
			{
				int pos;
				for (int i = j; i >= k; i--)
				{
					if (sums[j]-sums[i-1] <= b)
					{
						pos = i;
					}
				}
				p[k][j] = pos;
			}
		}

		vector<int> r;
		int pos = M;
		for (int k = K; k >= 1; k--)
		{
			r.push_back(p[k][pos]);
			pos = p[k][pos]-1;
		}
		r.push_back(0);
		reverse(r.begin(), r.end());
		if (debug)
		{
			for (int k = 1; k <= K; k++)
			{
				printf("%d\n", r[k]);
			}
		}
		r[K+1] = M+1;
		for (int i = 1; i <= K; i++)
		{
			for (int j = r[i]; j < r[i+1]; j++)
			{
				printf("%d", pages[j]);
				if (j < r[i+1]-1)
					printf(" ");
			}
			if (i < K)
				printf(" / ");
		}
		printf("\n");
	}
	return 0;
}
