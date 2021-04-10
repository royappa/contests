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
typedef pair<LL,int> pii;

LL solve(LL L, LL t, LL N, LL C, vector<LL> &dist)
{
	LL t2 = 0;
	int i;
	for (i = 0; i < N; i++)
	{
		if (t2+dist[i]*2 < t)
		{
			t2 += dist[i]*2;
		}
		else
		{
			break;
		}
	}
	// traveling between i and (i+1)

	vector<LL> benefit;

	if (i == N) // reached the end
	{
		; // nothing to do
	}
	else if (t2+dist[i]*2 == t) // it will be built exactly at next
	{
		i++;
	}
	else // t2+dist[i]*2 > t // it will be built before we reach the next
	{
		LL t3 = t-t2;
		LL d = t3/2;
		LL left = dist[i]-d;
		benefit.push_back(left);
		i++;
	}
	for (; i < N; i++)
	{
		benefit.push_back(dist[i]);
	}
	sort(benefit.rbegin(), benefit.rend());
	LL b = 0;
	for (i = 0; i < L && i < benefit.size(); i++)
	{
		b += benefit[i];
	}
	LL tot = 0;
	for (int i = 0; i < N; i++)
	{
		tot += dist[i]*2;
	}
	return tot-b;
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		LL L, t, N, C;

		cin >> L >> t >> N >> C;
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
		cout << "Case #" << testCase+1 << ": " << solve(L, t, N, C, data) << endl;
	}
	return 0;
}
