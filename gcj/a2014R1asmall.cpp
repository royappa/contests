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


int f(int b)
{
	if (b == L)
	{
		return 0;
	}
	int& r = memo[b];
	if (r != -1)
		return r;
	r = MAXVAL;
	// check if outlet b is compatible with the devices leads b, with lead b as-is

	// then check if outlet leads 0..b are compatible with the device leads 0..b if we have flipped lead b
}

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
		// try flipping every subset
		memset(memo, -1, sizeof(memo));
		int best = f(0);
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
