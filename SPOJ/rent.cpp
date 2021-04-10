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

#define MAX_N 10000
typedef long long LL;

int order[MAX_N][3]; // start,duration,price
multimap<int,int> tree; // just means, each key can have multiple values
int compar(const void *a, const void *b)
{
	return *((int *)a)-*((int *)b);
}

LL best[MAX_N];
int next[MAX_N];

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d", &order[i][0], &order[i][1], &order[i][2]);
		}
		qsort((void *) order, n, sizeof(order[0]), compar);
		memset(best, 0, sizeof(best));
		tree.clear();
		for (int i = 0; i < n; i++)
		{
			tree.insert(make_pair(order[i][0], i)); // instead of usual map notation
		}
		for (int i = n-1; i >= 0; i--)
		{
			// best[i] = max(price of i + best[the first order j that can be done after i], best[i+1])
			if (i == n-1)
			{
				best[i] = order[i][2];
			}
			else
			{
				multimap<int,int>::iterator next = tree.lower_bound(order[i][0]+order[i][1]);
				LL next_score = 0;
				if (next != tree.end())
				{
					next_score = best[next->second];
				}
				best[i] = max(best[i+1], next_score+order[i][2]);
			}
		}
		printf("%lld\n", best[0]);
	}
	return 0;
}
