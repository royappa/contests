#include <stdio.h>

int debug = 1;
typedef long long LL;
char buf[10000];

string s;
int n;

int memo[6001][6001];

int f(int p, int len)
{
	if (len <= 1)
		return 0;
	int& r = memo[p][len];
	if (r != -1)
		return r;

	if (s[p] == s[p+len-1])
		r = f(p+1, len-2);
	else
		r = 1+min(f(p, len-1), f(p+1, len-1));
	return r;
}

int main()
{
	int test;
	gets(buf);
	sscanf(buf, "%d", &test);
	for (int i = 0; i < test; i++)
	{
		gets(buf);
		s = buf;
		n = s.size();
		memset(memo, -1, sizeof(memo));
		printf("%d\n", f(0, n));
	}

	return 0;
}
