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

int B, T, N;
vector<int> X, V;
int memo[51][51];

#define INF (1<<30)

int f(int p, int K)  // return min# of swaps to get at least K chicks in the range [p,n) to the barn B within time T; return INF if not possible
{
	if (K == 0)
	{
		return 0;
	}
	if (p == N)
	{
		return INF;
	}
	int& r = memo[p][K];
	if (r != -1)
		return r;

	r = f(p+1, K);
	if (X[p]+T*V[p] >= B)
	{
		// s = number of chicks ahead of p, that will not reach the barn
		int s = 0;
		for (int i = p+1; i < N; i++)
		{
			if (X[i]+T*V[i] < B)
			{
				s++;
			}
		}
		r <?= s+f(p+1, K-1);
	}
	return r;
}


int main()
{
	int C;
	string s;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int K;
		cin >> N >> K >> B >> T;
		X.resize(0);
		V.resize(0);
		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			X.push_back(tmp);
		}
		for (int i = 0; i < N; i++)
		{
			int tmp;
			cin >> tmp;
			V.push_back(tmp);
		}
		memset(memo, -1, sizeof(memo));

		int swaps = f(0, K);
		if (best == INF)
		{
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		}
		else
		{
			printf("Case #%d: %d\n", testCase+1, swaps);
		}
	}
	return 0;
}
