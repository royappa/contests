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
#define debug 0

int main()
{
	int t;

	scanf("%d", &t);

	while (t-- > 0)
	{
		int n, r;
		scanf("%d%d", &n, &r);
		vector<int> x, y;
		x.push_back(0);
		x.push_back(n);
		y.push_back(0);	// y increases downward..
		y.push_back(n);
		vector< vector<int> > orig;
		for (int i = 0; i < r; i++)
		{
			int L, R, B, T;
			scanf("%d%d%d%d", &L, &R, &B, &T);
			x.push_back(L);
			x.push_back(R);
			y.push_back(n-B);
			y.push_back(n-T);
			vector<int> row;
			row.push_back(L);
			row.push_back(R);
			row.push_back(n-T); // top <= bottom in orig
			row.push_back(n-B);
			orig.push_back(row);
		}
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		int nxL = x.size(), nyL = y.size();
		int nxC = nxL-1, nyC = nyL-1;
		vector< vector<int> > paper;
		for (int i = 0; i < nxC; i++)
		{
			vector<int> row;
			for (int j = 0; j < nyC; j++)
			{
				double px = x[i], py = y[j];
				px += 0.5;
				py += 0.5;
				bool blank = false;
				for (int k = 0; k < orig.size(); k++)
				{
					if (px > orig[k][0] && px < orig[k][1] && py > orig[k][2] && py < orig[k][3])
					{
						blank = true;
						break;
					}
				}
				row.push_back(!blank);
			}
			paper.push_back(row);
		}

		if (debug)
		{
			printf("***************\n");
			for (int i = 0; i < nxC; i++)
			{
				for (int j = 0; j < nyC; j++)
				{
					printf("%d %d paper=%d\n", x[i], y[j], paper[i][j]);
				}
				printf("-\n");
			}
		}

		int best = 0;

		for (int a = 0; a < nxC; a++)
		{
			for (int b = 0; b < nyC; b++)
			{
				if (paper[a][b])
				{
					int i = b;
					int end = nxC;
					while (i < nyC)
					{
						int j = a;
						while (j < end && paper[j][i])
						{
							best = max(best, (x[j+1]-x[a])*(y[i+1]-y[b]));
							j++;
						}
						end = j-1;
						if (end < a)
							break;
					}
				}
			}
		}

		printf("%d\n", best);
	}

	return 0;
}
