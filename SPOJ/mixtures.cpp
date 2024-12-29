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
typedef long long LL;

int A[100];
LL color[100][100], smoke[100][100];



LL solve(int n)
{
	memset(color, 0, sizeof(color));
	memset(smoke, 0, sizeof(smoke));
	for (int i = 0; i < n; i++)
	{
		color[i][0] = A[i];
		smoke[i][0] = 0LL;
	}

	for (int d = 1; d < n; d++)
	{
		// calculate color[i][d] = result of mixing colors i..(i+d)
		for (int i = 0; i+d < n; i++)
		{
			LL bestSmoke = 1LL<<62, bestColor = 0LL;
			for (int j = 0; j < d; j++)
			{
				LL smokeLeft = smoke[i][j], smokeRight = smoke[i+j+1][d-j-1];
				LL colorLeft = color[i][j], colorRight = color[i+j+1][d-j-1];
				LL s = smokeLeft+smokeRight+colorLeft*colorRight;
				if (s < bestSmoke)
				{
					bestSmoke = s;
					bestColor = (colorLeft+colorRight)%100;
				}
			}
			smoke[i][d] = bestSmoke;
			color[i][d] = bestColor;
		}
	}
	if (debug)
	{
		for (int i = 0; i < n; i++)
		{ for (int j = 0; j < n; j++)
			cout << color[i][j] << " "; cout << endl; }
	}
	return smoke[0][n-1];
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
		}
		cout << solve(n) << endl;
	}
	return 0;
}
