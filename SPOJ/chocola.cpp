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
int debug=0;
int x[1024], y[1024];
int cumX[1024], cumY[1024];

int best(int a, int b, int c, int d)
{
	if (debug) printf("%d:%d:%d:%d\n", a, b, c, d);
	if (a == c || b == d)
	{
		return (cumX[d]-cumX[b]) + (cumY[c]-cumY[a]);
	}

	int biggest = 0;
	int ind;
	char which;
	for (int i = a+1; i <= c; i++)
	{
		if (debug) printf("%d %d\n", i, y[i]);
		if (y[i] > biggest)
		{
			biggest = y[i];
			ind = i;
			which = 'y';
		}
	}
	for (int i = b+1; i <= d; i++)
	{
		if (debug) printf("%d %d\n", i, x[i]);
		if (x[i] > biggest)
		{
			biggest = x[i];
			ind = i;
			which = 'x';
		}
	}
	if (debug) { if (biggest == 0) printf("zero\n"); }
	if (which == 'y') // row
	{
		return y[ind] + best(a, b, ind-1, d) + best(ind, b, c, d);
	}
	else
	{
		return x[ind] + best(a, b, c, ind-1) + best(a, ind, c, d);
	}
}


int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		int m, n;
		scanf("%d%d", &m, &n);
		cumX[0] = x[0] = 0;
		for (int i = 1; i <= m-1; i++)
		{
			scanf("%d", &x[i]);
			cumX[i] = cumX[i-1] + x[i];
		}
		cumY[0] = y[0] = 0;
		for (int i = 1; i <= n-1; i++)
		{
			scanf("%d", &y[i]);
			cumY[i] = cumY[i-1] + y[i];
		}

		printf("%d\n", best(0, 0, n-1, m-1));
	}
	return 0;
}
