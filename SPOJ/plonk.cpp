
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
typedef pair<int,int> pi;

int main()
{
	int t;

	scanf("%d", &t);

	while (t-- > 0)
	{
		int n;
		scanf("%d", &n);
		vector<pi> vx;
		for (int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vx.push_back(make_pair(x,y));
		}
		sort(vx.begin(), vx.end());

		vector<pi> vy;

		for (int i = n/2; i < n && vx[i].first == vx[n/2].first; i++)
		{
			vy.push_back(make_pair(vx[i].second, vx[i].first));
		}
		sort(vy.begin(), vy.end());

		int m = vy.size();

		pi p = make_pair(vy[m/2].second, vy[m/2].first);

printf("%d %d\n", p.first, p.second);
		long long total = 0;


		for (int i = 0; i < n; i++)
		{
			total += abs(vx[i].first-p.first)+abs(vx[i].second-p.second);
		}
		printf("%lld\n", total);
	}
	return 0;
}

