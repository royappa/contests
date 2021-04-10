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
int debug = 1;
typedef long long LL;
typedef long double LD;

#define eps 1.0e-12

// total time to cover the distance
// given "t" seconds of running left
void add(LD &totaltime, LD dist, LD &t, LD rspeed, LD wspeed)
{
	if (t >= -eps) // some time is left
	{
		LD t1 = dist/rspeed;
		if (t >= t1-eps) // can run the whole way
		{
			totaltime += t1;
			t -= t1;
		}
		else // can only run part of the way
		{
			totaltime += t;
			LD left = dist-rspeed*t;
			totaltime += left/wspeed;
			t = 0.0;
		}
	}
	else
	{
		LD t1 = dist/wspeed;
		totaltime += t1;
		t = 0;

	}
	return;
}

typedef vector<int> vi;
typedef vector<vi> vvi;

bool lessThan(vi a, vi b)
{
	return a[2] < b[2];
}

LD solve(LD X, LD S, LD R, LD t, vector<int> &B, vector<int> &E, vector<int> &w)
{
	int N = B.size();
	LD wlen = 0;
	LD totaltime = 0.0;
	for (int i = 0; i < N; i++)
	{
		wlen += E[i]-B[i];
	}
	add(totaltime, X-wlen, t, R, S);

	vvi m;
	for (int i = 0; i < N; i++)
	{
		vi z;
		z.push_back(B[i]);
		z.push_back(E[i]);
		z.push_back(w[i]);
		m.push_back(z);
	}
	sort(m.begin(), m.end(), lessThan);
	for (int i = 0; i < N; i++)
	{
		add(totaltime, m[i][1]-m[i][0], t, R+m[i][2], S+m[i][2]);
	}
	return totaltime;
}

int main()
{
	int T;

	cin >> T;

	for (int testCase = 0; testCase < T; testCase++)
	{
		int X, S, R, t, N;
		cin >> X >> S >> R >> t >> N;
		vector<int> B(N), E(N), w(N);
	for (int i = 0; i < N; i++)
		{
			cin >> B[i] >> E[i] >> w[i];
		}

		printf("Case #%d: %.10lf\n", testCase+1, (double) solve(X, S, R, t, B, E, w));

	}
	return 0;
}
