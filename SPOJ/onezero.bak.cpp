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

int debug = 1;

using namespace std;

int n;
int p10[100];


typedef long long LL;

LL f[3][20000];

char buf[256];

void dec(LL x)
{
	if (x == 0)
	{
		printf("0\n");
		return;
	}

	int i = 0;
	while (x > 0)
	{
		buf[i] = '0'+(x%2LL);
		x /= 2LL;
		i++;
	}
	buf[i] = '\0';
	for (int j = 0; j < i/2; j++)
	{
		char t = buf[j];
		buf[j] = buf[i-j-1];
		buf[i-j-1] = t;
	}
	printf("%s\n", buf);
	return;
}

void onezero()
{
	if (n == 1)
	{
		printf("1\n");
		return;
	}
	//memo.clear();

	for (int r = 0; r < n; r++)
	{
		f[1][r] = -1LL;
	}

	f[1][0] = 0LL;
	f[1][1] = 1LL;

	for (int k = 2; ; k++)
	{
		int p = p10[k-1];
		int pp = (1LL<<(k-1));
		for (int q = 0; q < n; q++)
		{
			f[2][q] = -1LL;
			// compute f[k][q] = smallest 10-number starting with 1, that equals q mod n, and has <= k digits
			int r = (q-p)%n;
			while (r < 0)
				r += n;
			if (f[1][r] != -1LL)
			{
				f[2][q] = pp+f[1][r];
				if (q == 0 && f[2][0] != -1LL)
				{
					dec(f[2][0]);
					return;
				}
			}
		}
		for (int q = 0; q < n; q++)
		{
			if (f[1][q] == -1LL)
			{
				f[1][q] = f[2][q];
			}
		}
	}
}


int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		scanf("%d", &n);

		p10[0] = 1;
		for (int i = 1; i < 100; i++)
		{
			p10[i] = (p10[i-1] * 10) % n;
		}

		onezero();
	}

	return 0;
}
