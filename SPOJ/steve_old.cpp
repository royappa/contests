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

using namespace std;

int memo[101][101];

int maxEaten(int n, int m, int origN, int player)
{
	if (origN == 0)
	{
		return 0;
	}

	if (n <= m)
	{
		return maxEaten(origN-;
	}

	int &eaten = memo[n][player];

	if (eaten != -1)
		return eaten;

	int minOther = 1000;

	for (int i = 1; i <= m; i++)
	{
		minOther = min(minOther, maxEaten(n-i, m, 1-player));
	}

	eaten = n-minOther;
	return eaten;
}

int solve(int n, int m)
{
	memset(memo, -1, sizeof(memo));
	return maxEaten(n, m, n, 0);

}

int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n, m;
		cin >> n >> m;
		printf("%d\n", solve(n, m));
	}
	return 0;
}
