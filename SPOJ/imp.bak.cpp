
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

int debug = 1;
typedef long long LL;
typedef pair<LL,LL> pLL;

pLL eea2(LL a, LL b)
{
	if (a == 0)
	{
		return make_pair(1LL, 0LL);
	}
	else if (b == 0)
	{
		return make_pair(0LL, 1LL);
	}
	if (a % b == 0)
	{
		return make_pair(0LL, 1LL);
	}
	else
	{
		pLL t = eea2(b, a % b);
		LL m = t.first, n = t.second;

		return make_pair(n, m-n*(a / b));
	}
}

// extended euclidean algorithm: bezout's identity
// given a,b > 0, return m,n s.t. m*a+n*b = gcd(a,b);
// considers gcd(a,0) = 0 = gcd(0, b)
// handles negative numbers, with gcd(a,b) = gcd(+-a, +-b) >= 0
pLL eea(LL a, LL b)
{
	pLL t;
	if (a < 0 && b < 0)
	{
		t = eea2(-a, -b);
		t.first *= -1LL;
		t.second *= -1LL;
	}
	else if (a < 0)
	{
		t = eea2(-a, b);
		t.first *= -1LL;
	}
	else if (b < 0)
	{
		t = eea2(a, -b);
		t.second *= -1LL;
	}
	else
	{
		t = eea2(a, b);
	}
	return t;
}

LL labs(LL x)
{
	return x < 0 ? -x : x;
}

LL lmin(LL x, LL y)
{
	return x < y ? x : y;
}

LL best(LL x, LL y)
{
	if (x == 0)
		return y;
	else if (y == 0)
		return x;
	else
		return lmin(labs(x), labs(y));
}

LL f(LL a, LL b, LL c, LL d)
{
if (debug) printf("start %d,%d  %d,%d\n", a,b, c,d);
	pLL t = eea(a, c);
	LL m, n;
	m = t.first;
	n = t.second;
	LL v1 = labs(m*a+n*c)+labs(m*b+n*d);
if (debug) printf("|%d*%d+%d*%d| +  |%d*%d+%d*%d| = %d\n", m, a, n, c, m, b, n, d, v1);
	t = eea(b, d);
	m = t.first;
	n = t.second;
	LL v2 = labs(m*a+n*c)+labs(m*b+n*d);
if (debug) printf("|%d*%d+%d*%d| +  |%d*%d+%d*%d| = %d\n", m, a, n, c, m, b, n, d, v2);
	v1 =  best(v1, v2);
	if (c != 0 && a % c == 0)
	{
		m = 1;
		n = -(a / c);
		v2 = labs(m*a+n*c)+labs(m*b+n*d);
		v1 =  best(v1, v2);
	}
	else if (a != 0 && c % a == 0)
	{
		n = 1;
		m = -(c / a);
		v2 = labs(m*a+n*c)+labs(m*b+n*d);
		v1 = best(v1, v2);
	}
	if (d != 0 && b % d == 0)
	{
		m = 1;
		n = -(b / d);
		v2 = labs(m*a+n*c)+labs(m*b+n*d);
		v1 = best(v1, v2);
	}
	else if (b != 0 && d % b == 0)
	{
		n = 1;
		m = -(d / b);
		v2 = labs(m*a+n*c)+labs(m*b+n*d);
		v1 = best(v1, v2);
	}
	return v1;
}

int main()
{
	int t = 10;

	while (t-- > 0)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		printf("%lld\n", f(a, b, c, d)); // Note the "n-1" because the solver starts the index of a[i] at 0
	}
	return 0;
}
