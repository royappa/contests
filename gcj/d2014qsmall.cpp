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
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

int war(int N, vector<double> naomi, vector<double> ken)
{
	int points = 0;
	for (int i = N-1; i >= 0; i--)
	{
		int k = ken.size();
		if (ken[k-1] > naomi[i])
		{
			int p;
			for (p = 0; p < k; p++)
			{
				if (ken[p] > naomi[i])
				{
					ken.erase(ken.begin()+p);
					break;
				}
			}
		}
		else
		{
			points++;
			ken.erase(ken.begin());
		}
	}
	return points;
}

bool allbigger(vector<double> &a, vector<double> &b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < b[i])
			return false;
	}
	return true;
}

int dwar(int N, vector<double> naomi, vector<double> ken)
{
	while (!allbigger(naomi, ken))
	{
		naomi.erase(naomi.begin());
		int k = ken.size();
		ken.erase(ken.begin()+(k-1));
	}
	return naomi.size();
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;

		cin >> N;
		vector<double> naomi(N), ken(N);

		for (int i = 0; i < N; i++)
		{
			cin >> naomi[i];
		}
		for (int i = 0; i < N; i++)
		{
			cin >> ken[i];
		}
		sort(naomi.begin(), naomi.end());
		sort(ken.begin(), ken.end());
		int dw = dwar(N, naomi, ken);
		int w = war(N, naomi, ken);

		printf("Case #%d: %d %d\n", testCase, dw, w);
	}
	return 0;
}
