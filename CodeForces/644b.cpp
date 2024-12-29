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
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;

int main()
{
	int n, b;
	cin >> n >> b;
	priority_queue<int,vector<int>,greater<int>> pq;

	int q = 0, e = 0;
	for (int i = 0; i < n; i++)
	{
		int t, d;
		cin >> t >> d;
		if (t >= e)
		{
			while (!pq.empty()) pq.pop();
			e = t+d;
			cout << e;
		}
		else
		{
			while (!pq.empty() && pq.top() <= t)
			{
				pq.pop();
			}
			if (b == (int) pq.size())
				cout << -1;
			else
			{
				e += d;
				pq.push(e);
				cout << e;
			}
		}
		if (i < n-1)
			cout << " ";
	}
	cout << endl;
	exit(0);
}
