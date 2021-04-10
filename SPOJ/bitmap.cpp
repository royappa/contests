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

using namespace std;

int A[182][182];

typedef pair<int,int> pi;

vector<pi> cur, next;

int main()
{
	int t;
	char buf[1024];

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		cur.clear();
		for (int r = 0; r < n; r++)
		{
			scanf("%s\n", buf);
			for (int c = 0; c < m; c++)
			{
				A[r][c] = 0;
				if (buf[c] == '1')
				{
					A[r][c] = -1;
					cur.push_back(make_pair(r, c));
				}
			}
		}
		int dr[] = {-1,  0, 1, 0};
		int dc[] = { 0, -1, 0, 1};

		while (cur.size() > 0)
		{
			next.clear();
			for (int i = 0; i < cur.size(); i++)
			{
				int r = cur[i].first, c = cur[i].second;
				for (int j = 0; j < 4; j++)
				{
					if (r+dr[j] >= 0 && r+dr[j] < n && c+dc[j] >= 0 && c+dc[j] < m && A[r+dr[j]][c+dc[j]] == 0)
					{
						A[r+dr[j]][c+dc[j]] = A[r][c] == -1 ? 1 : A[r][c]+1;
						next.push_back(make_pair(r+dr[j], c+dc[j]));
					}
				}
			}
			cur = next;
		}

		for (int r = 0; r < n; r++)
		{
			for (int c = 0; c < m; c++)
			{
				if (A[r][c] == -1)
				{
					A[r][c] = 0;
				}
				printf("%d", A[r][c]);
				if (c < m-1)
				{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
}
