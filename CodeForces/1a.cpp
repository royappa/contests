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
#include <string.h>

using namespace std;

typedef long long LL;

string s;
int n;
int memo[5001][5001];

const int MOD = 1000000000+7;


bool smaller(int p1, int len1, int p2, int len2)
{
	if (len1 != len2)
		return len1 < len2;
	int p =
	return false; // exactly equal
}
// number of ways to split sequence from position p+len to the end
// given that the previous number started at p and had length of len

int f(int p, int len)
{
	int& r = memo[p][len];
	if (r != -1)
		return r;
	if (p+len >= n)
		return 1;
	r = 0;
	int p2 = p+len;
	if (p2 == n || s[p2] == '0')
		return r;

	for (int len2 = len; p2+len2 <= n; len2++)
	{
		if (smaller(p, len, p2, len2))
		{
			r = (r+f(p2, len2))%MOD;
		}
	}
	return r;
}

int main()
{
	cin >> n;
	cin >> s;
	memset(memo, -1, sizeof(memo));


	cout << f(0, 0) << endl;
}

