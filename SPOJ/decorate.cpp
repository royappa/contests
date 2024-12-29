// NOT WORKING BUT RIGHT IDEA (SAME AS CUTOUT).
// REQUIRES O(N^3) SOLUTION, AM DOING O(N^4) RIGHT NOW - GOOD ENOUGH FOR CUTOUT
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

bool inside[201][201];

int main()
{
	int t;

	scanf("%d", &t);

	while (t-- > 0)
	{
		int n, w, h;
		scanf("%d%d%d", &n, &w, &h);

		vector<double> x, y;

		vector< vector<double> > orig;
		for (int i = 0; i < n; i++)
		{
			int x1, y1, x2, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x.push_back(x1);
			x.push_back(x2);
			y.push_back(y1);
			y.push_back(y2);
			vector<double> row;
			row.push_back(x1);
			row.push_back(y1);
			row.push_back(x2); // top <= bottom in orig
			row.push_back(y2);
			orig.push_back(row);
		}
		int wnew, hnew;
		scanf("%d%d", &wnew, &hnew);

		x.push_back(0);
		x.push_back(w);
		y.push_back(0);
		y.push_back(h);
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		y.erase(unique(y.begin(), y.end()), y.end());
		int nx = x.size(), ny = y.size();

		for (int i = 0; i < nx-1; i++)
		{
			for (int j = 0; j < ny-1; j++)
			{
				bool flag = false;
				for (int k = 0; k < orig.size(); k++)
				{
					if (orig[k][0] <= x[i]+0.5 && x[i]+0.5 <= orig[k][2] &&
						orig[k][1] <= y[j]+0.5 && y[j]+0.5 <= orig[k][3])
					{
						flag = true;
						break;
					}
				}
				inside[i][j] = flag;
			}
		}

		if (debug)
		{
			printf("***************\n");
			printf("wnew = %d hnew = %d\n", wnew, hnew);
			for (int i = 0; i < nx-1; i++)
			{
				for (int j = 0; j < ny-1; j++)
				{
					printf("%.0lf %.0lf inside(%d %d)=%d\n", x[i], y[j], i, j, inside[i][j]);
				}
				printf("-\n");
			}
		}

		int best = 0;
		// O(n^4) loop - needs to be O(n^3)

		for (int a = 0; a < ny-1; a++)
		{
			for (int b = 0; b < nx-1; b++)
			{
				int yend = ny-1;
				int j = a, i = b;
				while (i < nx-1 && !inside[i][j])
				{
					while (j < yend && !inside[i][j])
					{
						if (debug) printf("%d %d is inside\n", i, j);
						if ((x[i+1]-x[b]) >= wnew && (y[j+1]-y[a]) >= hnew)
						{
							if (debug)
								printf("%.0lf %.0lf (%d %d)(%.0lf %.0lf)->(%d %d)(%.0lf %.0lf) \n", x[b], y[a], b, a, x[b],y[a], i+1, j+1, x[i+1],y[j+1]);
							printf("%.0lf %.0lf\n", x[b], y[a]);
							goto next;
						}
						j++;
					}
					i++;
					yend = j;
					j = a;
				}
			}
		}
		printf("Fail!\n");
		continue;
next:	best = best; // dummy;
	}

	return 0;
}
