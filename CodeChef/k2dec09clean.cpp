// SEE COMMENTS FOR CODE ATTRIBUTIONS (IF ANY)
// CAN'T FIND RULES ABOUT USING CODE FOUND ON WEB
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

using namespace std;

typedef long long LL;
typedef unsigned int UI; // for ugly optimizations to do LL for just a few steps then UI rest of the way

LL biggestPrimeFactor(LL N)
{
	LL m = 0;
	UI s = LL(ceil(sqrt(double(N))))+1;
	UI i;
	for (i = 2; i < s; i++)
	{
		if (N % i == 0)
		{
			m = i;
			do
			{
				N /= i;
			}
			while (N % i == 0);
			if (N < (1LL<<32))
				break;
		}
	}
	if (N < (1LL<<32))
	{
		UI NN = N;
		i++;
		for (; i < s; i++)
		{
			if (NN % i == 0)
			{
				m = i;
				do
				{
					NN /= i;
				}
				while (NN % i == 0);
			}
		}
		N = NN;
	}
	if (N > 1) // there could be one prime left that is larger than sqrt(n)
	{
		m = N;
	}
	return m;
}

UI vint[100];
bool isPalindromeInt(UI N, UI b)
{
	int len = 0;
	while (N > 0)
	{
		vint[len++] = N % b;
		N /= b;
	}
	for (int i = 0; i < len/2; i++)
	{
		if (vint[i] != vint[len-i-1])
			return false;
	}
	return true;
}

bool isPalindrome(LL N, LL b)
{
	if (N < (1LL<<32))
	{
		return isPalindromeInt((UI)N, (UI) b);
	}
	int len = 0;
	while (N >= (1LL<<32))
	{
		vint[len++] = N % b;
		N /= b;
	}
	UI NN = N, bb = b;
	while (NN > 0)
	{
		vint[len++] = NN % bb;
		NN /= bb;
	}
	for (int i = 0; i < len/2; i++)
	{
		if (vint[i] != vint[len-i-1])
			return false;
	}
	return true;
}

//
// define minbase(N) = the minimum base b, in which N's base-b representation is a palindrome
// unproven guess by trial and error observation of data:
// IF  (minbase(N) >= sqrt(N)) AND (p is the largest prime factor of N) AND (N is palindromic in base p) THEN
// 		minbase(N) = p-1
// So, the algorithm is:
// 1. Brute force up to sqrt(N).
// 2. If minbase(N) is not found, then test p-1, where p is the largest prime factor of N
// 3. If N is not palindromic in base p-1, then brute force the rest of the way
//
LL h(LL N)
{
	if (N <= 2)
		return 2;

	LL s = (LL)sqrt(N)+1;
	bool found = false;
	LL minb;
	for (LL b = 2; b <= s; b++)
	{
		if (isPalindrome(N, b))
		{
			found = true;
			minb = b;
			break;
		}
	}
	if (!found)
	{
		LL b = biggestPrimeFactor(N)-1;
		if (b > 1 && isPalindrome(N, b))
		{
			minb = b;
		}
		else
		{
			for (LL b = s+1; b <= N-1; b++)
			{
				if (isPalindrome(N, b))
				{
					minb = b;
					break;
				}
			}
		}
	}
	return minb;
}

int main()
{
	int T;
	char buf[1024];
	gets(buf); sscanf(buf, "%d", &T);
	while (T-- > 0)
	{
		LL N;
		gets(buf); sscanf(buf, "%lld", &N);
		LL t1, t2;
		printf("%lld\n", h(N));
	}

}

