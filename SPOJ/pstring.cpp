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

/*
Given two strings X and Y, your task is find the minimum number of characters to be removed from X in order to obtain a string X' that does not contain Y as a substring.

Length of X <= 10000, Length of Y <= 1000.


Equivalent: find p = the length of the longest subsequence of X which does not contain Y as a substring
			return |X|-p

*/

using namespace std;

char *cp(char *s)
{
	char *buf = (char *)malloc(strlen(s)+1);
	strcpy(buf, s);
	return buf;
}

char X[1024*10], Y[1024];

int f(int m, n)
{

}
int main()
{
	while (gets(X) != NULL)
	{
		gets(Y);

		int m = strlen(X), n = strlen(Y);

		printf("%d\n", m-f(m, n));

	}

	return 0;
}
