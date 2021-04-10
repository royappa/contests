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

int v[2000];

int best[2000][2000];

/*
int f(int beg, int end, int age)
{
	if (beg == end)
	{
		return v[beg]*age;
	}
	int &r = memo[beg][end];
	if (r != -1)
		return r;

	return r = max(v[beg]*age+f(beg+1, end, age+1), v[end]*age+f(beg, end-1, age+1));
}
*/

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}
	/*
	memset(memo, -1, sizeof(memo));
	printf("%d\n", f(0, n-1, 1));
	*/

	// try DP. Note that any *subrange* [beg,end] is always sold at the same age (even though any ONE item may be sold at various ages)

	for (int age = n; age >= 1; age--)
	{
		// fill in all the best[beg][end] which can be sold at this age
		for (int beg = 0; beg <= age-1; beg++)
		{
			// age-1 things have been sold, and in a range beg..end, there are (end-beg+1) things.
			// thus, n-(end-beg+1) = age-1
			// n-end+beg-1=age-1
			// end=n-age+1+beg-1 = n+beg-age = n-(age-beg);
			int end = n-(age-beg);
			if (beg == end)
			{
				best[beg][end] = v[beg]*n;
			}
			else
			{
				best[beg][end] = max(v[beg]*age+best[beg+1][end], v[end]*age+best[beg][end-1]);
			}
		}
	}
	printf("%d\n", best[0][n-1]);

	return 0;
}
