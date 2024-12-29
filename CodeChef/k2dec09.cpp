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
typedef pair<int,int> pLL;

LL biggestPrimeFactor(LL n)
{
	LL m = 0;
	LL s = LL(ceil(sqrt(double(n))))+1;
	for (LL i = 2; i < s; i++)
	{
		if (n % i == 0)
		{
			m = i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1) // there could be one prime left that is larger than sqrt(n)
	{
		m = n;
	}
	return m;
}

LL v[100];
typedef unsigned int UI;

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

int f(LL N)
{
	if (N == 1) return 2;
	else if (N == 2) return 3;

	for (LL b = 2; b <= N-1; b++)
	{
		if (isPalindrome(N, b))
			return b;
	}
}

LL h(LL N/*, string &extra*/)
{
	//extra = "";
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
					//extra = "*";
					break;
				}
			}
		}
	}
	return minb;
}

int main()
{

	for (int i = 1; i <= 20; i++)
	{
		cout << f(i) << endl;
	}
	exit(0);
/* test harness
	for (LL N = 9000000000LL; N <= 9000000000LL+1000LL; N++)
	//for (LL N = 1000000LL; N <= 1000000LL+1000LL; N++)
	//for (int i = 0; i < 1000; i++)
	{
		//LL N = 9000000342LL;
		//LL N = 2000000063LL;
		string extra;
		LL hn = h(N); // , extra*
		cout << N << "\t" << hn << endl;
		//LL fn = f(N);
		//cout << N << "\t\t" << fn << " " << "\t\t" << hn << extra << "\t\t" << (fn != hn ? "MISMATCH" : "") << endl;
	}
	exit(0);
*/
/*
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
*/

}

