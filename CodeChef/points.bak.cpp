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

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int N;
		cin >> N;
		while (N-- > 0)
		{
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, -y));
		}
		sort(v.begin(), v.end());
		double d  = 0;
		for (int i = 1; i < v.size(); i++)
		{
			d += hypot(v[i].first-v[i-1].first, v[i].second-v[i-1].second);
		}
		printf("%.2lf\n", d);
	}
}

