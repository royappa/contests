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
int grid[101][101], grid2[101][101];

#define INF (1<<30)


int main()
{
	int C;
	string s;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int R;
		cin >> R;
		memset(grid, 0, sizeof(grid));
		int num = 0;
		for (int i = 0; i < R; i++)
		{
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			for (int r = y1; r <= y2; r++)
			{
				for (int c = x1; c <= x2; c++)
				{
					grid[r][c] = 1;
					num = 1;
				}
			}
		}
		int turns = 0;
		while (num > 0)
		{
			turns++;
			num = 0;
			memset(grid2, 0, sizeof(grid2));
			for (int r = 0; r <= 100; r++)
			{
				for (int c = 0; c <= 100; c++)
				{
					grid2[r][c] = grid[r][c];
					if (r == 0)
					{
						grid2[r][c] = 0;
					}
					else if (c == 0)
					{
						grid2[r][c] = 0;
					}
					else if (grid[r-1][c] == 0 && grid[r][c-1] == 0)
					{
						grid2[r][c] = 0;
					}
					else if (grid[r][c] == 0 && grid[r-1][c] == 1 && grid[r][c-1] == 1)
					{
						grid2[r][c] = 1;
					}
					if (grid2[r][c] == 1)
						num = 1;
				}
			}
			memcpy(grid, grid2, sizeof(grid));
		}
		printf("Case #%d: %d\n", testCase+1, turns);
	}
	return 0;
}
