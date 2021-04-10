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

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int D;
		vector<int> v;

		cin >> D;
		for (int i = 0; i < D; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}

		int m = *max_element(v.begin(), v.end());
		int best = m;
		for (int i = 1; i <= m; i++)
		{
			int t = 0;
			for (int j = 0; j < D; j++)
			{
				if (v[j] > i)
				{
					t += (v[j]-1)/i;
				}
			}
			best = min(best, t+i);
		}
		printf("Case #%d: %d\n", testCase, best);
	}
	return 0;
}
