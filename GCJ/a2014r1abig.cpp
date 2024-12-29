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
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)
int N, L;
vector<string> vout, vdev;
int memo[50];

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cin >> N >> L;
		vout.resize(0);
		vdev.resize(0);
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			vout.push_back(s);
		}
		for (int i = 0; i < N; i++)
		{
			string s;
			cin >> s;
			vdev.push_back(s);
		}
		sort(vdev.begin(), vdev.end());
		int best = MAXVAL;
		// try each outlet for device 0
		for (int i = 0; i < N; i++)
		{
			// match outlet
			long long mask = 0;
			for (int j = 0; j < L; j++)
			{
				if (vout[i][j] != vdev[0][j])
					mask |= 1LL<<j;
			}
			vector<string> vout2 = vout;
			for (int k = 0; k < N; k++)
			{
				for (int j = 0; j < L; j++)
				{
					if ((mask&(1LL<<j)) == 0) continue;
					vout2[k][j] ^= 1;
				}
			}
			sort(vout2.begin(), vout2.end());
			if (vout2 == vdev)
			{
				best = min(best, __builtin_popcountll(mask));
			}
		}
		if (best == MAXVAL)
		{
			printf("Case #%d: NOT POSSIBLE\n", testCase);
		}
		else
		{
			printf("Case #%d: %d\n", testCase, best);
		}
	}
	return 0;
}
