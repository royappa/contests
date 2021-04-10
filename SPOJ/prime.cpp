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

int primes[40000];
int n;

bool isPrime(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;
	int d = 3;
	while (d*d <= num)
	{
		if (num % d == 0)
			return false;
		d += 2;
	}
	return true;
}

bool isPrime2(int num)
{
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;

	for (int i = 0; primes[i]*primes[i] <= num; i++)
	{
		if (num % primes[i] == 0)
			return false;
	}
	return true;
}

int main()
{
	int t;
	n = 0;
	for (int p = 3; p <= 40000; p += 2)
	{
		if (isPrime(p))
		{
			primes[n++] = p;
		}
	}

	scanf("%d\n", &t);

	for (int i = 0; i < t; i++)
	{
		int a, b;
		scanf("%d %d\n", &a, &b);
		if (a == 2)
			printf("%d\n", a);
		if (a % 2 == 0)
			a++;
		for (int j = a; j <= b; j++)
		{
			if (isPrime2(j))
			{
				printf("%d\n", j);
			}
		}
		if (i != t-1) printf("\n");
	}
	return 0;
}
