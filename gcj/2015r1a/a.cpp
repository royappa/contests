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


int f(vector<int> v)
{
	int n = v.size();
	int cur = v[0];
	int tot = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i-1] > v[i])
			tot += v[i-1]-v[i];
	}
	return tot;
}

int g(vector<int> v)
{
	int n = v.size();
	int most = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i-1] > v[i])
		{
			most = max(most, v[i-1]-v[i]);
		}
	}
	//cout << "most = " << most << endl;
	int tot = 0;
	for (int i = 1; i < n; i++)
	{
		if (v[i-1]-v[i] == most)
		{
			tot += most;
		}
		else
		{
			tot += min(v[i-1], most);
		}
	}
	return tot;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++)
		{
			cin >> v[i];
		}
		int x = f(v);
		int y = g(v);
		printf("Case #%d: %d %d\n", testCase, x, y);
	}
	return 0;
}
