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

int p10[23];
int np[20][1000];


bool isPal(int n)
{
	char buf[100];
	sprintf(buf, "%d", n);

	int k = strlen(buf);

	for (int i = 0; i < k/2; i++)
	{
		if (buf[i] != buf[k-i-1])
			return false;
	}
	return true;
}

int numPal(int m, int s)
{
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

	return np[s][0];
}

int main()
{
	int q10[9];
	q10[0] = 1;
	for (int i = 1; i <= 8; i++)
	{
		q10[i] = q10[i-1]*10;
	}

	int num = 0;

	for (int m = 2; m <= 100; m++)
	{
		for (int s = 1; s <= 8; s++)
		{
			num++;
			if (num%1000 == 0)
			{
				printf("testing m=%d,s=%d (count=%d)\n", m, s, num);
			}
			int c = 0;
			for (int i = q10[s-1]; i < q10[s]; i++)
			{
				if (isPal(i) && i%m == 0)
				{
					c++;
					//printf("%d\n", i);
				}
			}
			if (c != numPal(m, s))
			{
				printf("(m,s)=(%d,%d) differ: actual=%d, calc=%d\n", m, s, c, numPal(m, s));
			}
		}
	}
	return 0;
}
