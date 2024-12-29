// SEE COMMENTS FOR ALGORITHM/IDEA/CODE ATTRIBUTIONS (IF ANY)
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
#include <string>
#include <cstring>
#include <queue>

using namespace std;

typedef long long LL;

LL rand64()
{
	LL r1 = rand();
	LL r2 = rand();
	return ((r1<<32LL)|r2);
}

LL mypow(LL a, LL d, LL n)
{
	if (d == 0)
		return 1;
	if (d == 1)
		return a % n;

	LL p = mypow(a, d / 2, n);
	LL q = (p * p) % n;
	if (d % 2 == 0)
		return q;
	else
		return (q * a) % n;
}

bool isPrime(LL n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;

/*
http://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test

write n - 1 as 2^s·d with d odd by factoring powers of 2 from n - 1
LOOP: repeat k times:
   pick a randomly in the range [2, n - 1]
   x ? a^d mod n
   if x = 1 or x = n - 1 then do next LOOP
   for r = 1 .. s - 1
      x ? x2 mod n
      if x = 1 then return composite
      if x = n - 1 then do next LOOP
   return composite
return probably prime

*/
	int s = 0;
	LL d = n-1;
	while (d % 2 == 0)
	{
		d /= 2;
		s++;
	}
	// n-1 = (2^s)*d
	for (int i = 0; i < 60; i++)
	{
		LL a = rand64() % n;
		cout << i << " " << a << endl;
		if (a < 2)
			a = 2;
		LL x = mypow(a, d, n);
		cout << i << " " << a << " " << d << " " << x << endl;
		if (x  == 1 || x == n-1)
			continue;
		bool loop = false;
		for (int r = 1; r <= s-1; r++)
		{
			x = (x * x) % n;
			if (x == 1)
				return false;
			if (x == n-1)
			{
				loop = true;
				break;
			}
		}
		if (loop)
			continue;
		return false;
	}
	return true;
}

LL getPrime(string s)
{
	string orig = s;
	int n = orig.size();

	for (int i = 0; i < n; i++)
	{
		if (s[i] == '?')
		{
			s[i] = i == 0 ? '1' : '0';
		}
	}

	LL p = 0;
	for (int i = 0; i < n; i++)
	{
		p = p*10+(s[i]-'0');
	}

	while (!isPrime(p))
	{
		cout << p << " is not prime " << " s = " << s << endl;
		for (int i = n-1; i >= 0; i--)
		{
			if (orig[i] == '?')
			{
				if (s[i] < '9')
				{
					s[i]++;
					break;
				}
				else
				{
					s[i] = '0';
					int j = i-1;
					while (s[j] == '9')
					{
						s[j] = '0';
						j--;
					}
					s[j]++;
				}
			}
		}
		p = 0;
		for (int i = 0; i < n; i++)
		{
			p = p*10+(s[i]-'0');
		}
	}
	return p;
}

int main()
{

	cout << 100000000003LL << " " << isPrime(100000000003LL) << endl;
	exit(1);

	int T;
	char buf[1024];
	gets(buf); sscanf(buf, "%d", &T);
	while (T-- > 0)
	{
		gets(buf);
		printf("%lld\n", getPrime(string(buf)));
	}

}

