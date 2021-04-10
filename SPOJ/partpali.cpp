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

typedef unsigned int LL;

LL np[20][1000];

LL p10[22];

int main()
{

	int n;
	scanf("%d", &n);
	while (n-- != 0)
	{

		int m, s;
		scanf("%d%d", &m, &s);

		p10[0] = 1;
		for (int i = 1; i <= 20; i++)
		{
			p10[i] = (p10[i-1]*10)%m;
		}

		memset(np, 0, sizeof(np));

		for (int d = 1; d <= 9; d++)
		{
			np[1][d%m]++;
		}

		for (int d = 1; d <= 9; d++)
		{
			np[2][(d*10+d)%m]++;
		}
		for (int len = 3; len <= s; len++)
		{
			for (int i = 0; i < m; i++)
			{
				for (int sub = 0; sub <= len-2; sub++)
				{
					if (len%2 != sub%2)
						continue;
					int nz = ((len-2)-sub)/2;
					for (int d = 1; d <= 9; d++)
					{
						int x = np[sub][i];
						int y = (d*p10[nz+sub+nz+1]+i*p10[nz+1]+d)%m;
						np[len][y] += x;
					}
				}
			}
			int ez = len-2;
			for (int d = 1; d <= 9; d++)
			{
				int y = (d*p10[ez+1]+d)%m;
				np[len][y]++;
				if (debug) printf("len=%d,y=%d,d=%d,ez=%d\n", len, y, d, ez);
			}
		}

		printf("%u\n", np[s][0]);
	}
	return 0;
}
