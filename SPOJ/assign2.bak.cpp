#include <stdio.h>

int debug = 1;
typedef long long LL;

int A[20][20];
int Ac[20];

int n;
LL memo[1100000];
int bc[1100000];

char buf[100];

int bitmemo[1100000][20];
int bmc[1100000];

int p[20];

int main()
{
	int test;
	gets(buf);
	sscanf(buf, "%d", &test);
	int m = 1<<20;

	int i, j;
	for (i = 0; i < m; i++)
	{
		int c = 0;
		int j = i;
		while (j)
		{
			j &= j-1;
			c++;
		}
		bc[i] = c;
	}


	while (test-- > 0)
	{
		gets(buf);
		sscanf(buf, "%d", &n);
		for (	i = 0; i < n; i++)
		{
			gets(buf);
			int rowMask = 0;
			char *s = buf;
			while (*s)
			{
				if (*s == '1')
				{
					rowMask |= (1<<((s-buf)>>1));
				}
				s++;
			}
			Ac[i] = rowMask;
		}

		memo[(1<<n)-1] = 1;
		int mask;
#define HIGH 0x10000000
		for (mask = (1<<n)-1; mask >= 0; mask--)
		{
			int row = bc[mask];
			LL r = 0LL;
			if (row == n)
			{
				r = 1;
			}
			else
			{
				r = 0LL;
				int m = Ac[row] & ~mask; // want to iterate through all possible, unused positions (1 in Ac[row] & 0 in mask)
				int k = bmc[m];
				if (k == 0)
				{
					int *p = &bitmemo[m][0];
					while (m)
					{
						int mc = m & (m-1);
						int bit = m ^ mc;
						int mm = mask | bit;
						r += memo[mm];
						m = mc;
						*p++ = mm;
						k++;
					}
					bmc[m] = k;
				}
				else
				{
					int *p = &bitmemo[m][0];
					while (k)
					{
						r += memo[*p++];
						k--;
					}
				}
			}
			memo[mask] = r;
		}
		printf("%lld\n", memo[0]);
	}
	return 0;
}
