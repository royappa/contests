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

using namespace std;
int debug = 0;
typedef long long LL;

LL bestTime(LL t, LL N, vector<LL> &dist, int L0, int L1)
{
	LL t2 = 0;
	for (int i = 0; i < N; i++)
	{
		// going from star i = i+1, check if there is a booster here
		if (i == L0 || i == L1)
		{
			if (t <= t2) // booster will be built already
			{
				t2 += dist[i];
			}
			else if (t2 < t && t < t2+dist[i]*2) // booster will be built before we reach next star
			{
				LL t3 = t-t2; // time to finish building booster   v=d/t => d = v*t
				LL d = t3/2; // dist to build point is t3*0.5
				t2 += d*2;
				d = dist[i]-d;
				t2 += d*1;
			}
			else
			{
				t2 += dist[i]*2;
			}
		}
		else
		{
			t2 += dist[i]*2;
		}
	}
	return t2;

}


LL solve(LL L, LL t, LL N, LL C, vector<LL> &data)
{
	bool first = true;
	LL mint = 0;
	// try every possibility
	if (L == 0)
	{
		mint = bestTime(t, N, data, -1, -1);
	}
	else if (L == 1)
	{
		for (int i = 0; i < N; i++)
		{
			LL t2 = bestTime(t, N, data, i, -1);
			if (first || t2 < mint)
			{
				mint = t2;
				first = false;
			}
		}
	}
	else  // L == 2
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				LL t2 = bestTime(t, N, data, i, j);
				if (first || t2 < mint)
				{
					mint = t2;
					first = false;
				}
			}
		}
	}
	return mint;
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		LL L, t, N, C;

		cin >> L >> t >> N >> C;
if (debug) cout << L << " " << t << " " << N << " " << C << endl;
		vector<LL> a;
		for (int i = 0; i < C; i++)
		{
			LL x;
			cin >> x;
			a.push_back(x);
		}
		vector<LL> data;
		for (int i = 0; i < N; i++)
		{
			data.push_back(a[i%C]);
		}
if (debug)
{
		for (int i = 0; i < data.size(); i++)
		{
			cout << data[i] << endl;
		}
}
		cout << "Case #" << testCase+1 << ": " << solve(L, t, N, C, data) << endl;

	}
	return 0;
}
