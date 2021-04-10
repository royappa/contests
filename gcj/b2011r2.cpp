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

bool poss(vector<string> &v, int D, int r, int c, int dim)
{
	int R = v.size(), C = v[0].size();
	LD x = 0.0, y = 0.0;
	LD total = 0;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			if (i == 0 && j == 0) continue;
			if (i == 0 && j == dim-1) continue;
			if (i == dim-1 && j == 0) continue;
			if (i == dim-1 && j == dim-1) continue;
			LD mass = v[r+i][c+j]-'0'+D;
			x += mass*(i+0.5);
			y += mass*(j+0.5);
			total += mass;
		}
	}
	x /= total;
	y /= total;
	return x == dim/2.0 && y == dim/2.0;
}

int solve(vector<string> &v, int D)
{
	int best = -1;
	int R = v.size(), C = v[0].size();
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			for (int dim = 3; dim <= min(R-i,C-j); dim++)
			{
				if (i+dim > R || j+dim > C) continue;
				if (dim > best && poss(v, D, i, j, dim))
				{
					best = dim;
				}
			}
		}
	}
	return best;
}

int main()
{
	int T;

	cin >> T;

	for (int testCase = 0; testCase < T; testCase++)
	{
		int R, C, D;
		cin >> R >> C >> D;
		vector<string> data;
		for (int i = 0; i < R; i++)
		{
			string s;
			cin >> s;
			data.push_back(s);
		}
		int x = solve(data, D);
		if (x == -1)
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		else
			printf("Case #%d: %d\n", testCase+1, x);
	}
	return 0;
}
