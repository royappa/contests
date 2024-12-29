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

typedef vector<int> vi;

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

		queue<vi> q;
		q.push(v);
		map<vi,int> dist;
		dist[v] = 0;

		int turns = 1<<30;
		while (q.size() > 0)
		{
			vi h = q.front();
			q.pop();
			typeof(h.begin()) m = max_element(h.begin(), h.end());
			int t = dist[h];
			vi h2 = h;

			if (*m >= 2)
			{
				int mm = *m;
				for (int k = 1; k <= mm-1; k++)
				{
					h = h2;
					h.erase(m);
					h.push_back(k);
					h.push_back(mm-k);
					if (dist.count(h) == 0)
					{
						dist[h] = t+1;
						q.push(h);
					}
				}
			}
			h = h2;
			for (int i = h.size()-1; i >= 0; i--)
			{
				h[i]--;
				if (h[i] == 0)
				{
					h.erase(h.begin()+i);
				}
			}
			if (h.size() > 0 && dist.count(h) == 0)
			{
				q.push(h);
				dist[h] = t+1;
			}
			if (h.size() == 0)
			{
				turns = min(turns, t+1);
			}
		}
		printf("Case #%d: %d\n", testCase, turns);
	}
	return 0;
}
