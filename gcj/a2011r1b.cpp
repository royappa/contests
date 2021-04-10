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

// calculate winning percentage of team t, excluding games against team e
double winper(vector<string> &v, int t, int e)
{
	int n = v.size();
	int played = 0, won = 0;
	for (int j = 0; j < n; j++)
	{
		if (j == e) continue;
		if (v[t][j] == '.') continue;
		played++;
		if (v[t][j] == '1') won++;
	}
	return double(won)/double(played);
}

double oppwinper(vector<string> v, int t)
{
	int numopp = 0;
	int n = v.size();
	double owp = 0.0;
	for (int j = 0; j < n; j++)
	{
		if (j == t) continue;
		if (v[t][j] == '.') continue;
		numopp++;
		owp += winper(v, j, t);
	}
	return owp / numopp;
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		vector<string> v;
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			string x;
			cin >> x;
			v.push_back(x);
		}
		printf("Case #%d:\n", testCase+1);
		for (int i = 0; i < N; i++)
		{
			// find the RPI of team i
			double wp = winper(v, i, i);
			double owp = oppwinper(v, i);
			double oowp = 0;
			int numopp = 0;
			for (int j = 0; j < N; j++)
			{
				if (v[i][j] == '.') continue;
				numopp++;
				oowp += oppwinper(v, j);
			}
			oowp /= numopp;
			printf("%.12lf\n", 0.25*wp+0.50*owp+0.25*oowp);
		}
	}
	return 0;
}
