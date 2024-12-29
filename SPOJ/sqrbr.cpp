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

bool b[100];
typedef long long LL;
LL calls;
map<pair<int,int>,LL> memo;

LL solve(int n, int pos)
{
	calls++;

	if (n == 0)
	{
		return 1LL;
	}
	pair<int,int> key = make_pair(n, pos);
	if (memo.count(key) > 0)
	{
		return memo[key];
	}
	LL &total = memo[key];
	total = 0LL;
	for (int i = 0; i <= n-1; i++)
	{
		if (!b[pos+2*i+1])
		{
			total += solve(i, pos+1) * solve(n-1-i, pos+2*i+1+1);
		}
	}
	return total;
}


int main()
{
	int d;

	scanf("%d", &d);

	for (int i = 0; i < d; i++)
	{
		int n, k;
		memo.clear();
		memset(b, false, sizeof(b));
		scanf("%d%d", &n, &k);
		for (int j = 0; j < k; j++)
		{
			int x;
			scanf("%d", &x);
			b[x] = true;
		}
		LL ni = solve(n, 1);
		printf("%lld\n", ni);
	}
	return 0;
}
