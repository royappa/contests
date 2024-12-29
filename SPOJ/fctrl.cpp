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

int main()
{
	int tests;
	scanf("%d", &tests);
	int d5[15], d2[31];

	d5[0] = d2[0] = 1;
	for (int i = 1; i < 15; i++)
	{
		d5[i] = d5[i-1]*5;
		d2[i] = d2[i-1]<<1;
	}
	for (int i = 15; i < 31; i++)
	{
		d2[i] = d2[i-1]<<1;
	}

	while (tests-- > 0)
	{
		int n;
		scanf("%d", &n);
		int p5 = 0;
		int i = 1;
		int p2 = 0;
		while (d5[i] <= n)
		{
			p5 += n / d5[i];
			i++;
		}
		i = 1;
		while (d2[i] <= n && p2 <= p5)
		{
			p2 += n / d2[i];
			i++;
		}

		printf("%d\n", min(p2, p5));
	}

	return 0;
}
