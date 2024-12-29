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
int debug = 1;
char buf[4096];

typedef pair<int,int> pi;

vector<int> v1, v2;
int main()
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int n;
		cin >> n;
		v1.resize(n,0);
		v2.resize(n,0);
		for (int i = 0; i < n; i++)
		{
			cin >> v1[i];
		}
		for (int i = 0; i < n; i++)
		{
			cin >> v2[i];
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		long long t = 0;
		for (int i = 0; i < n; i++)
		{
			t += (long long)((long long)v1[i]*(long long)v2[n-i-1]);
		}
		printf("Case #%d: %lld\n", testCase+1, t);
	}
	return 0;
}
