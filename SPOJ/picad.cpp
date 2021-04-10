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

int debug = 0;

using namespace std;

typedef long long LL;

int main()
{
	int test;
	map<int,int> arrive, leave, event;
	test = 10;
	while (test-- > 0)
	{
		int p, k;
		scanf("%d%d", &p, &k);
		int n;
		scanf("%d", &n);
		arrive.clear();
		leave.clear();
		for (int i = 0; i < n; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			arrive[a]++;
			leave[b]++;
			event[a] = 1;
			event[b] = 1;
		}
		int least = n+1, most = 0;
		int cur = 0;
		event[p] = 1;
		event[k] = 1;
		for (map<int,int>::iterator it = event.begin(); it != event.end(); it++)
		{
			int t = it->first;
			if (debug) printf("time %d cur %d least %d most %d\n", t, cur, least, most);
			if (arrive.count(t) > 0)
			{
				cur += arrive[t]; // some arrive at the start of this moment
			}
			if (t >= p && t <= k)
			{
				most = max(most, cur);
				least = min(least, cur);
			}
			if (debug) printf("time %d cur %d least %d most %d\n", t, cur, least, most);
			if (leave.count(t) > 0)
			{
				cur -= leave[t]; // some leave at the end of this moment
			}
			if (t >= p && t < k)
			{
				most = max(most, cur);
				least = min(least, cur);
			}
			if (debug) printf("time %d cur %d least %d most %d\n", t, cur, least, most);
		}
		printf("%d %d\n", least, most);
	}

	return 0;
}

