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

typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

typedef pair<int,int> pi;

char buf[4096];
char *welcome = "welcome to code jam";

int memo[501][20];
int n, len;

int f(int p, int k) // number of occurrences of welcome[k..18] subsequences in buf[p..n]
{
	int &r = memo[p][k];
	if (r != -1)
		return r;

	if (k == len)
		return 1;
	if (p == n)
		return 0;

	r = f(p+1, k) % 10000;
	if (buf[p] == welcome[k])
	{
		r = (r + f(p+1, k+1)) % 10000;
	}
	return r;
}

int main()
{
	int T;
	gets(buf);
	sscanf(buf, "%d", &T);
	len = strlen(welcome);
	for (int testCase = 0; testCase < T; testCase++)
	{
		gets(buf);
		n = strlen(buf);
		memset(memo, -1, sizeof(memo));
		printf("Case #%d: %04d\n", 1+testCase, f(0, 0));
	}
	return 0;
}
