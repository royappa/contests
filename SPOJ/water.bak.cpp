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
int debug=1;

int A[101][101], visited[101][101]	;

void dump(int n, int m)
{

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			printf("%4d", A[r][c]);
		}
		printf("\n");
	}
	return;
}

int dfs(int row, int col)
{
	if (A[row][col] < 0)
	{
		return 1; // reached sink
	}
	visited[row][col] = 1;
	int dr[] = {0, -1, 0, 1};
	int dc[] = {-1, 0, 1, 0};
	for (int i = 0; i < 4; i++)
	{
		int r = row+dr[i], c = col+dc[i];
		if (abs(A[r][c]) <= A[row][col])
		{
			if (A[r][c] < 0 || (!visited[r][c] && dfs(r, c)))
			{
				A[row][col] *= -1;
				return 1;
			}
			if ()
			{
				cout << row <<  " " << col << " " << 1 << endl;
				A[row][col] *= -1;
				return 1;
			}
		}
	}
	cout << row <<  " " << col << " " << 0 << endl;
	return 0; // can't reach a sink
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		memset(A, 0, sizeof(A));
		memset(visited, 0, sizeof(visited));
		int n, m;
		scanf("%d%d", &n, &m);
		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				scanf("%d", &A[r][c]);
				if (r == 0 || r == n-1 || c == 0 || c == m-1)
				{
					A[r][c] *= -1;
					visited[r][c] = 1;
				}
			}
		}
		// Algorithm:
		// Step 1: Mark all sinks. A sink is a square which is:
		// (a) on the boundary or
		// (b) has a path of sequentially non-increasing height to another sink
		// A sink is marked by making its height negative
		for (int c = 1; c < m-1; c++)
		{
			for (int r = 1; r < n-1; r++)
			{
				if (!visited[r][c])
				{
					dfs(r, c);
				}
			}
		}

		if (debug) dump(n, m);

		//printf("%d\n", volume);
	}
	return 0;
}
