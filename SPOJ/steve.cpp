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

int poss[101][101]; 	// poss[n][k] = true, iff somebody can win exactly k out of n.
int m;

bool possible(int n, int k, int w)
{
	if (n <= m && k == n) // game over
	{
		return 1;
	}
	if (k > n)
	{
		return 0;
	}

	for (int i = 1; i <= m; i++)
	{
		if (possible(n-i, k))
		{
			return 1;
		}
	}
}

int memo[101];

int maxEat(int n) // max you can win out of n, if you go first.
{
	if (n == 0)
	{
		return 0;
	}

	if (memo[n] != -1)
		return memo[n];

	int& best = memo[n];

	best = 0;
	// try all possible games where cur player wins k out of n
	for (int k = 1; k <= n; k++)
	{
		if (possible(n, k)) // somebody wins this round with exactly k
		{
			// 1. cur is winner (wins k)
			int x = maxEat(n-k); // find out how much other will win out of the rest of the game, playing his best, and going first (since he lost)
			best = max(best, n-x); // cur will keep n-x total
			// 2. other is winner (wins k)
			best = max(best, x); // max cur can get is x (he goes first, since he lost)
		}
	}
	return best;
}

int main()
{

	int t;

	cin >> t;

	while (t-- > 0)
	{
		int n;
		cin >> n >> m;

		// calculate poss array
		memset(poss, -1, sizeof(poss));
		memset(memo, -1, sizeof(memo));
		printf("%d\n", maxEat(n));
	}
	return 0;
}
