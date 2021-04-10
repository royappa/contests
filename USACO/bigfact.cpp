/*
ID: royappa1
LANG: C++
PROG: bigfact
*/
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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int debug = 0;

int primes[20000];
int p;

bool isPrime(int x)
{
	int d = 2;
	while (d*d <= x)
	{
		if (x % d == 0)
			return false;
		d++;
	}
	return true;
}

void genPrimes()
{
	p = 2;
	primes[0] = 2;
	primes[1] = 3;
	for (int i = 5; i <= 19999; i++)
	{
		if (isPrime(i))
		{
			primes[p++] = i;
		}
	}
}

int factor(int num)
{
	int big = 1;
	for (int i = 0; i < p && primes[i] < num; i++)
	{
		if (num % primes[i] == 0)
		{
			big = max(big, primes[i]);
		}
	}
	return big;
}


main ()
{
    ifstream fin("bigfact.in");
    ofstream fout("bigfact.out");
	genPrimes();

   	int N;

   	fin >> N;

   	int best = 0, bestNum = 0;
   	for (int i = 0; i < N; i++)
   	{
   		int num;
   		fin >> num;
   		int f = factor(num);
   		if (debug) cout << num << " " << f << endl;
   		if (f > best)
   		{
   			best = f;
   			bestNum = num;
   		}
   	}
   	fout << bestNum << endl;
    exit (0);
}


/*
Problem 12: Max Factor [Hal Burch, 2005]

To improve the organization of his farm, Farmer John labels each of his N
(1 <= N <= 5,000) cows with a distinct serial number in the range
1..20,000.  Unfortunately, he is unaware that the cows interpret some
serial numbers as better than others.  In particular, a cow whose serial
number has the highest prime factor enjoys the highest social standing
among all the other cows.
(Recall that a prime number is just a number that has no divisors except
for 1 and itself.  The number 7 is prime while the number 6, being
divisible by 2 and 3, is not).

Given a set of N (1 <= N <= 5,000) serial numbers in the range
1..20,000, determine the one that has the largest prime factor.

PROBLEM NAME: bigfact

INPUT FORMAT:

* Line 1: A single integer, N

* Lines 2..N+1: The serial numbers to be tested, one per line

SAMPLE INPUT (file bigfact.in):

4
36
38
40
42

OUTPUT FORMAT:

* Line 1: The integer with the largest prime factor.  If there are
        more than one, output the one that appears earliest in the
        input file.

SAMPLE OUTPUT (file bigfact.out):

38

OUTPUT DETAILS:

19 is a prime factor of 38.  No other input number has a larger prime factor.
*/

