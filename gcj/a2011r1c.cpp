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

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		vector<string> v;
		int R, C;
		cin >> R >> C;
		for (int i = 0; i < R; i++)
		{
			string x;
			cin >> x;
			v.push_back(x);
		}
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (i+1 >= R || j+1 >= C) continue;
				if (v[i][j] == '#' && v[i][j+1] == '#' && v[i+1][j] == '#' && v[i+1][j+1] == '#')
				{
					v[i][j] = '/';
					v[i][j+1] = '\\';
					v[i+1][j] = '\\';
					v[i+1][j+1] = '/';
				}
			}
		}
		if (debug)
		{
			cout << "foo" << endl;
			for (int i = 0; i < R; i++)
			{
				cout << " " << v[i] << endl;
			}
		}
		double blue = false;
		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				if (v[i][j] == '#')
				{
					//cout << i << " " << j << endl;
					blue = true;
					break;
				}
			}
		}

		cout << "Case #" << testCase+1 << ":" << endl;
		if (blue)
		{
			cout << "Impossible" << endl;
		}
		else
		{
			for (int i = 0; i < R; i++)
			{
				cout << " " << v[i] << endl;
			}
		}
	}
	return 0;
}
