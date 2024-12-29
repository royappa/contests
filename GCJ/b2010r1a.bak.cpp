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

int D, I, M, N;
vector<int> v;
int memo[110][260][2];

#define INF (1<<26)

int f(int p, int last, int ins)// cost to make v[p,n) smooth given that v[0,p) is already smooth, and the value to the left of p is "last", and num pixels have been inserted so far
{
	int& r = memo[p][last][ins];
	if (r != -1)
		return r;

	if (p == N-1) // at last pixel
	{
		if (p == 0)
			return 0;
		if (abs(v[p]-last) <= M)
			return 0;
		r = D; // delete last pixel
		r <?= abs(M-abs(v[p]-last)); // change last pixel by least amount needed

			for (int x = 0; x <= 255; x++)
			{
				if ((ins == 0 || x > last) && abs(x-last) <= M)
				{
					r <?= I+f(p, x, 1);
				}
			}

		return r;
	}

	r = INF;
	// options: delete, insert, change
	// 1. delete

	r <?= D+f(p+1, last, 0);

	// 2. change
	for (int x = 0; x <= 255; x++)
	{
		if (last == 256 || abs(x-last) <= M)
		{
			r <?= abs(v[p]-x)+f(p+1, x, 0);
		}
	}
	// 3. insert - only if we are between characters, and there is a benefit to inserting - avoid recursion
	if (p != 0)
	{
		for (int x = 0; x <= 255; x++)
		{
			if ((ins == 0 && x > last) && abs(x-last) <= M)
			{
				r <?= I+f(p, x, 1);
			}
		}
	}
if (debug) cout << p << " " << last << " " << ins << " = " << r << endl;
	r <?= INF;
	return r;
}

int main()
{
	int T;
	string s;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		cin >> D >> I >> M >> N;
		v.resize(0);
		for (int i = 0; i < N; i++)
		{
			int x;
			cin >> x;
			v.push_back(x);
		}
		memset(memo, -1, sizeof(memo));

		int best = f(0, 256, 0);
		printf("Case #%d: %d\n", testCase+1, best);
	}
	return 0;
}
