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
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;


int main()
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> v(n, 0);
	v[0] = s[0]=='0';
	for (int i = 1; i < n; i++)
	{
		v[i] = v[i-1] + (s[i] == '0');
	}
	int best = n;
	for (int i = 0; i < n-1; i++)
	{
		if (s[i] != '0') continue;
		// find the smallest p such that v[p]-v[i-1] >= k+1

		int lo = i, hi = n-1;
		int base = i == 0 ? 0 : v[i-1];
		if (v[hi]-base < k+1) break;
		// invariants: i..lo is not enough, i..hi is enough
		while (hi > lo+1)
		{
			int mid = (lo+hi)/2;
			if (v[mid]-base >= k+1)
			{
				hi = mid;
			}
			else
			{
				lo = mid;
			}
		}
		best = min(best, hi-i);
	}
	cout << best << endl;
	exit(0);
}
