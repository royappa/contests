//
// Version using Memoization about O( (n*m)^2 ) or a bit slower. Works on sample data but too slow for systest.
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
char buf[1024];

map<string,int> memo;

int best(int a, int b, int c, int d)
{
	if (debug) printf("%d:%d:%d:%d\n", a, b, c, d);
	if (a == c || b == d)
	{
		if (debug) printf("* %d:%d:%d:%d = %d\n", a, b, c, d, (cumX[d]-cumX[b]) + (cumY[c]-cumY[a]));
		return (cumX[d]-cumX[b]) + (cumY[c]-cumY[a]);
	}

	sprintf(buf, "%d:%d:%d:%d", a, b, c, d);
	string key = buf;
	if (memo.count(key) > 0)
	{
		return memo[key];
	}

	int result = 1<<30;

	// try all y cuts (along rows)

	for (int i = a; i <= c-1; i++)
	{
		int cost = y[i+1] + best(a, b, i, d) + best(i+1, b, c, d);
		result = min(result, cost);
	}

	// now all x cuts (along cols)
	for (int i = b; i <= d-1; i++)
	{
		int cost = x[i+1] + best(a, b, c, i) + best(a, i+1, c, d);
		result = min(result, cost);
	}
	if (debug) printf("%d:%d:%d:%d = %d\n", a, b, c, d, result);
	memo[key] = result;
	return result;
}


int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memo.clear();
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
