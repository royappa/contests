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
#include <string.h>

using namespace std;


int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}
int lcm(int a, int b)
{
	return a/gcd(a,b)*b;
}

typedef pair<int,int> pi;
int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int B, N;
		cin >> B >> N;
		vector<int> v(B);
		for (int i = 0; i < B; i++)
		{
			cin >> v[i];
		}
		int L = v[0];
		for (int i = 1; i < B; i++)
		{
			L = lcm(L, v[i]);
		}
		int R = 0;
		for (int i = 0; i < B; i++)
		{
			R += L/v[i];
		}
		N--;
		N %= R;
cout << B << " " << N << " " << L << " " << R << endl;
		vector<pi> q;
		for (int i = 0; i < B; i++)
		{
			q.push_back(make_pair(v[i], i));
		}
		int ans = 0;
		while (N > 0)
		{
			pi h = *min_element(q.begin(), q.end());
			for (int i = 0; i < B; i++)
			{
				q[i].first -= h.first;
			}
			for (int i = 0; i < B; i++)
			{
				if (i == N && q[i] == 0)
				{
					ans = i;
					goto outer;
				}
			}
			for (int i = 0; i < B; i++)
			{
				if (q[i] == 0)
				{
					q[i] = make_pair(v[q[i].second], i);
				}
			}
			N -= B;
		}
		outer:
		printf("Case #%d: %d\n", testCase, ans+1);
	}
	return 0;
}
