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
char buf[4096];
typedef long long LL;

LL choose(LL n, LL k)
{
	if (k > n)
		return 0;
	LL r = 1;
	LL nk = n-k;
	while (n > 1)
	{
		r *= n;
		n--;
		while (k > 1 && r % k == 0)
		{
			r /= k;
			k--;
		}
		while (nk > 1 && r % nk == 0)
		{
			r /= nk;
			nk--;
		}
	}
	return r;
}


int main()
{
	int N;
	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		LL m, A, B, C, D, x0, y0, M;
		cin >> m >> A >> B >> C >> D >> x0 >> y0 >> M;
		vector<LL> x, y;
		LL X = x0, Y = y0;
		x.push_back(X);
		y.push_back(Y);
		for (int i = 1; i <= m-1; i++)
		{
			X = (A*X+B) % M;
			Y = (C*Y+D) % M;
			x.push_back(X);
			y.push_back(Y);
		}
		int n = x.size();
		LL num = 0;
		LL sig[9];
		memset(sig, 0, sizeof(sig));
		for (int i = 0; i < n; i++)
		{
			sig[x[i]%3*3+y[i]%3]++;
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = i+1; j < 9; j++)
			{
				for (int k = j+1; k < 9; k++)
				{
					int x1 = i/3, y1 = i%3;
					int x2 = j/3, y2 = j%3;
					int x3 = k/3, y3 = k%3;
					int cx = x1+x2+x3, cy = y1+y2+y3;
					if (cx%3 != 0 || cy%3 != 0)
						continue;
					LL q = num;
					num += sig[i]*sig[j]*sig[k];
					if (debug && testCase+1==10) printf("%d,%d:%lld %d,%d:%lld %d,%d:%lld %lld %lld\n", x1,y1,sig[i], x2,y2,sig[j], x3,y3,sig[k], num, num-q);
				}
			}
		}
		for (int i = 0; i < 9; i++)
		{
			int x1 = i/3, y1 = i%3;
			int x2 = i/3, y2 = i%3;
			int x3 = i/3, y3 = i%3;
			int cx = x1+x2+x3, cy = y1+y2+y3;
			if (cx%3 != 0 || cy%3 != 0)
				continue;
			num += choose(sig[i], 3);
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (i == j) continue;
				int x1 = i/3, y1 = i%3;
				int x2 = i/3, y2 = i%3;
				int x3 = j/3, y3 = j%3;
				int cx = x1+x2+x3, cy = y1+y2+y3;
				if (cx%3 != 0 || cy%3 != 0)
					continue;
				// use i twice, j once
				num += choose(sig[i], 2)*sig[j];
			}
		}
		/*
		for (int i = 0; i < n; i++)
		{
			LL x1 = x[i], y1 = y[i];
			for (int j = i+1; j < n; j++)
			{
				LL x2 = x[j], y2 = y[j];
				for (int k = j+1; k < n; k++)
				{
					LL x3 = x[k], y3 = y[k];
					LL cx = (x1+x2+x3), cy = (y1+y2+y3);

					if (cx%3 != 0 || cy % 3 != 0)
						continue;
					num += sig[i];
				}
			}
		}
		*/

		cout << "Case #" << testCase+1 << ": " << num << endl;
	}
	return 0;
}
