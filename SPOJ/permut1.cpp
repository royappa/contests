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

int memo[20][100];

int solve(int n, int k)
{
	if (n == 1)
		return k == 0;

	// From 0 to n-1 inversions can be created
	int& total = memo[n][k];
	if (total != -1)
	{
		return total;
	}
	total = 0;
	for (int i = 0; i <= k; i++)
	{
		if (k-i <= n-1)
		{
			total += solve(n-1, i); // i inversions using first n-1 numbers; k inversions using the last number
		}
	}

	return total;
}

int main()
{
	int d;
	scanf("%d", &d);
	while (d-- > 0)
	{
		int n, k;
		scanf("%d%d", &n, &k);
		memset(memo, -1, sizeof(memo));
		printf("%d\n", solve(n, k));
	}
	return 0;
}
