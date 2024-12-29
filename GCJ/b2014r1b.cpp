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

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)
int N, M;
int A[10][10];
vector<string> zip;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{

		cin >> N >> M;
		memset(A, 0, sizeof(A));
		zip.resize(N);
		for (int i = 0; i < N; i++)
		{
			cin >> zip[i];
		}
		for (int i = 0; i < M; i++)
		{
			int x, y;
			cin >> x >> y;
			x--;
			y--;
			A[x][y] = A[y][x] = 1;
		}
		vector<int> v;
		for (int i = 0; i < N; i++)
		{
			v.push_back(i);
		}
		string best = "{";
		do
		{
			bool canVisit = true;
			for (int i = 1; i < N; i++)
			{
				// check if we can visit i by a direct step from any prior visited node, 0..(i-1)
				bool any = false;
				for (int j = 0; j < i; j++)
				{
					int ii = v[i], jj = v[j];
					if (A[jj][ii])
					{
						any = true;
						break;
					}
				}
				if (!any)
				{
					canVisit = false;
					break;
				}
			}
			out:

			if (canVisit)
			{
				string t = "";
				for (int i = 0; i < N; i++)
				{
					t += zip[v[i]];
				}
				if (t < best)
				{
					best = t;
					for (int i = 0; i < N; i++)
						cout << v[i]+1 << " "; cout << " canVisit = " << canVisit << endl;
				}
			}
		}
		while (next_permutation(v.begin(), v.end()));
		printf("Case #%d: %s\n", testCase, best.c_str());
	}
	return 0;
}
