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
#include <string.h>

// GCJ 2016, qualification, B
using namespace std;
typedef long long LL;

int up(char x) { return x == '-' ? 0 : 1; }

int f(string s)
{
	int n = s.size();
	int cur = up(s[0]);
	int steps = 0;
	for (int i = 1; i < n; i++)
	{
		if (s[i-1] != s[i])
		{
			steps++;
			cur = 1-cur;
		}
	}
	if (cur == 0) steps++;
	return steps;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string S;
		cin >> S;
		printf("Case #%d: %d\n", testCase, f(S));
	}
	return 0;
}
