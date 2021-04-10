#include <stdio.h>

int debug = 1;
typedef long long LL;

int A[20][20];
int Ac[20];

int n;
LL memo[1100000];
int bc[1100000];

char buf[100];

int p[20];

int main()
{
	int test;
	gets(buf);
	char *s = buf;
	test = 0;
	while (*s >= '0')
	{
//printf("%c %d\n", *s, test);
		test = 10*test+(*s++-'0');
	}
//printf("%d\n", test);
	//sscanf(buf, "%d", &test);
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
		//sscanf(buf, "%d", &n);
		n = 0;
		s = buf;
		while (*s >= '0')
		{
			n = 10*n+(*s++-'0');
		}
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
		for (mask = (1<<n)-1; !(mask & HIGH); mask--)
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
				while (m)
				{
					int mc = m & (m-1);
					int bit = m ^ mc;

					r += memo[mask | bit];
					m = mc;

				}
			}
			memo[mask] = r;
		}
		printf("%lld\n", memo[0]);
	}
	return 0;
}
