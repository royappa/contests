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

int compar(const void *a, const void *b)
{
	return *((int *)a)-*((int *)b);
}

LL best[MAX_N];

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
		for (int i = n-1; i >= 0; i--)
		{
			// best[i] = max(price of i + best[the first order j that can be done after i], best[i+1])
			if (i == n-1)
			{
				best[i] = order[i][2];
			}
			else
			{
				// find next order using binary search
				int t = order[i][0]+order[i][1];
				int low = 0, high = n-1;
				int which;
				//printf("t = %d\n", t);
				while (true) // find index of first item with start >= t
				{
					//printf("%d %d\n", low, high);
					if (low >= high)
					{
						which = high;
						break;
					}
					int mid = (low+high)/2;
					if (mid == low || mid == high)
					{
						if (order[low][0] >= t)
							which = low;
						else
							which = high;
						break;
					}
					if (order[mid][0] == t)
					{
						while (mid >= 0 && order[mid-1][0] == t)
							mid--;
						which = mid;
						break;
					}
					else if (order[mid][0] < t)
					{
						low = mid;
					}
					else
					{
						high = mid;
					}
				}
				LL next_score = 0;
				if (order[which][0] >= t)
				{
					next_score = best[which];
				}
				//printf("t = %d which = %d\n", t, which);
				best[i] = max(best[i+1], next_score+order[i][2]);
			}
		}
		printf("%lld\n", best[0]);
	}
	return 0;
}
