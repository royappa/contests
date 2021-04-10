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
typedef long long LL;

LL sieve[1000000+1];
LL primes[1000000+1];

int numSpecialPrimes; // number of primes of the form 4*m+3

bool solve(LL n)
{
//printf("testing: %lld\n", n);
	if (n == 0LL) return true;
	for (int i = 0; i < numSpecialPrimes; i++)
	{
		if (n%primes[i] == 0)
		{
			//printf("factor: %lld\n", primes[i]);
			int p = 0;
			while (n%primes[i] == 0)
			{
				n /= primes[i];
				p++;
			}
			//printf("power: %d\n", p);
			if (primes[i]%4==3 && p%2) return false;
		}
	}
	//printf("left: %lld\n", n);
	if (n > 1LL)
	{
		if (n%4==3) return false;
	}
	return true;
}

bool solve2(LL n)
{
	if (n == 0) return true;
	LL s = sqrt(n);
	for (LL a = 1; a <= s; a++)
	{
		double b = sqrt(n-a*a);
		if (b-floor(b) == 0.0)
			return true;
	}
	return false;
}

int main()
{
	// build primes table, consisting of primes of the form 4m+3

	for (int i = 0; i <= 1000000; i++)
		sieve[i] = 1;

	sieve[0] = 0;
	sieve[1] = 0;
	int p = 0;
	while (true)
	{
		while (p <= 1000000 && sieve[p] == 0)
			p++;
		if (p > 1000000)
			break;
		for (int i = 2; i*p <= 1000000; i++)
			sieve[i*p] = 0;
		p++;
	}
	p = 0;
	for (int i = 2; i <= 1000000; i++)
	{
		if (sieve[i])
			primes[p++] = i;
	}
	numSpecialPrimes = p;
	int d;
/*
for (LL t = 1000000000000LL; t >= 0LL; t--)
{
	int s1, s2;
	if ((s1 = solve(t)) != (s2 = solve2(t)))
		printf("Wrong for %lld %d %d\n", t, s1, s2);
	if (t%1000LL == 0)
		printf("%d\n", int(t/1000LL));
}
exit(1);*/

	scanf("%d", &d);

	while (d-- > 0)
	{
		LL n;
		scanf("%lld", &n);
		printf("%s\n", solve(n)?"Yes":"No");
	}
	return 0;
}
