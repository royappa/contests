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

bool possible(int mask, vector< vector<int> > &flavor, vector< vector<int> > &typ, int N)
{
	int M = flavor.size();
	int num = 0;
	for (int i = 0; i < M; i++) // for each customer
	{
		for (int j = 0; j < flavor[i].size(); j++)
		{
			int f = flavor[i][j]-1;
			int t = typ[i][j];
			if (((mask&(1<<f))!=0) == t)
			{
				num++;
				break;
			}
		}
	}
	return num == M;
}

int main()
{
	int C;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int N, M;
		cin >> N >> M;
		vector< vector<int> > flavor;
		vector< vector<int> > typ;
		for (int i = 0; i < M; i++)
		{
			int T;
			cin >> T;
			vector<int> f;
			vector<int> t;
			for (int j = 0; j < T; j++)
			{
				int X, Y;
				cin >> X >> Y;
				f.push_back(X);
				t.push_back(Y);
			}
			flavor.push_back(f);
			typ.push_back(t);
		}
		bool poss = false;
		int best = 1<<30;
		int bestMask = 0;
		for (int m = 0; m < (1<<N); m++)
		{
			if (possible(m, flavor, typ, N))
			{
				if (__builtin_popcount(m) < best)
				{
					best = __builtin_popcount(m);
					bestMask = m;
					poss = true;
				}
			}
		}
		if (!poss)
		{
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		}
		else
		{
			printf("Case #%d:", testCase+1);
			for (int i = 0; i < N; i++)
			{
				printf(" %d", bestMask&(1<<i)?1:0);
			}
			printf("\n");
		}
	}
	return 0;
}
