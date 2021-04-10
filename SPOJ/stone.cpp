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

int debug = 0;

using namespace std;

typedef long long LL;

int main()
{
	int t;

	scanf("%d", &t);

	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		double x0, y0, x1, y1, xo, yo;
		scanf("%lf%lf", &x0, &y0);
		xo = x0;
		yo = y0;
		double A = 0.0, cx = 0.0, cy = 0.0;
		for (int i = 0; i < n; i++)
		{
			if (i == n-1)
			{
				x1 = xo;
				y1 = yo;
			}
			else
			{
				scanf("%lf%lf", &x1, &y1);
			}
			double q = x0*y1-x1*y0;
			A += q;
			cx += (x0+x1)*q;
			cy += (y0+y1)*q;
			x0 = x1;
			y0 = y1;
		}
		A /= 2.0;
		cx /= (6*A);
		cy /= (6*A);
		printf("%.2lf %.2lf\n", cx, cy);
	}

	return 0;
}

