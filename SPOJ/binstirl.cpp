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

using namespace std;

int debug = 1;

int S2(int n, int m)
{
	if (n == 0 && m == 0)
		return 1;
	else if (n == 0 || m == 0)
		return 0;
	else
		return ((m%2)*S2(n-1, m)+S2(n-1, m-1))%2;
}


int S(int n, int m)
{
	if (debug) printf("%d %d\n", n, m);
	if (n == m)
	{
		return 1;
	}
	else if (n < m)
	{
		return 0;
	}
	else if (m == 0)
	{
		return 0;
	}
	else if (m == 1)
	{
		return 1;
	}
	else if (m % 2 == 0)
	{
		return S(n-1, m-1);
	}
	else if (n < 5)
	{
		return S2(n, m);
	}

	int d = min(n-m, m);
	int k = d/2;
	if (k == 0)
		k++;
	if (debug) printf("k = %d: n = %d, m = %d\n", k, n, m);
	return (S(n-2*k,m)+S(n-3-2*k,m-2*k)+S(n-2*k,m-2*k))%2;

}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		if (debug) printf("i = %d\n", i);
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", S(n, m));
	}
	return 0;
}


/*
For n > m >= 2

S(n,m)	= m*S(n-1,m)+S(n-1,m-1) = S(n-1, m-1) if m is even
S(n,m) 	= m*S(n-1,m)+S(n-1,m-1) = S(n-1,m)+S(n-1,m-1) if m is odd
		= S(n-1,m)+S(n-2,m-2), because m-1 is even
		= S(n-2,m)+S(n-3,m-2)+S(n-2,m-2)
			= S(n-2k,m)+S(n-3-2k,m-2k)+S(n-2k,m-2k) for any k>=0, OR
			= S(n-2-3k,m)+S(n-3k,m-2-3k)+S(n-2-3k,m-2-3k)

*/
