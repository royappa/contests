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

int L[81][81];
int n, m;
string x, y;

void LCS(string x, string y)
{
	int m = x.size(), n = y.size();

	for (int i = m; i >= 0; i--)
	{
		for (int j = n; j >= 0; j--)
		{
			if (i == m || j == n)
			{
				L[i][j] = 0;
			}
			else if (x[i] == y[j])
			{
				L[i][j] = 1 + L[i+1][j+1];
			}
			else
			{
				L[i][j] = max(L[i+1][j], L[i][j+1]);
			}
		}
	}
}

typedef pair<int,int> pi;
typedef vector<string> vs;
map<pi,vs> memo;

vector<string> solutions(int i, int j)
{
	vector<string> r(0);
	string e = "";
	if (i == m || j == n)
	{
		r.push_back(e);
		return r;
	}
	pi key = make_pair(i, j);
	if (memo.count(key) > 0)
		return memo[key];

	if (x[i] == y[j])
	{
		r = solutions(i+1, j+1);
		for (int k = 0; k < r.size(); k++)
		{
			r[k] = e + x[i] + r[k];
		}
	}
	else if (L[i+1][j] > L[i][j+1])
	{
		r = solutions(i+1, j);
	}
	else if (L[i][j+1] > L[i+1][j])
	{
		r = solutions(i, j+1);
	}
	else
	{
		vector<string> r1 = solutions(i, j+1);
		for (int k = 0; k < r1.size(); k++)
			r.push_back(r1[k]);
		vector<string> r2 = solutions(i+1, j);
		for (int k = 0; k < r2.size(); k++)
			r.push_back(r2[k]);
		sort(r.begin(), r.end());
		r.erase(unique(r.begin(), r.end()), r.end());
	}
	memo[key] = r;
	return r;
}

int main()
{
	int d;

	scanf("%d", &d);

	for (int i = 0; i < d; i++)
	{
		cin >> x >> y;
		m = x.size();
		n = y.size();
		memset(L, 0, sizeof(L));
		memo.clear();
		LCS(x, y);
		vector<string> r = solutions(0, 0);

		sort(r.begin(), r.end());
		r.erase(unique(r.begin(), r.end()), r.end());
		for (int j = 0; j < r.size(); j++)
		{
			cout << r[j] << endl;
		}
		if (i != d-1)
			cout << endl;
	}
	return 0;
}
