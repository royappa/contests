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
cout << n << " " << k  << endl;
	if (n == 1)
		return k == 1;
	if (k == 1)
		return 1;
	if (n == k)
		return 1;

	int &total = memo[n][k];
	if (total != -1)
		return total;
	total = k*solve(n-1,k)+solve(n-1,k-1);
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
