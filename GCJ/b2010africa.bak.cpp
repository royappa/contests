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
char buf[16384];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

typedef pair<int,int> pi;

int f(int town, vector<int> &H, vector<int> &P)
{
	vector<int> cap;
	int numPeople == 0, totalCap = 0;
	for (int i = 0; i < H.size(); i++)
	{
		if (H[i] == town)
		{
			numPeople++;
			if (P[i] > 0)
			{
				totalCap += P[i];
				cap.push_back(P[i]);
			}
		}
	}
	if (numPeople > totalCap)
		return -1;
	if (numPeople == 0)
		return 0;

	sort(cap.rbegin(), cap.rend());
	int cars = 0;
	for (int i = 0; i < cap.size(); i++)
	{
		numPeople -= cap[i];
		cars++;
		if (numPeople <= 0)
			break;
	}
	return cars;
}

int main()
{
	int C;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int N, T;
		cin >> N >> T; // number of towns and office town
		int E;
		cin >> E;
		vector<int> H, P;
		for (int i = 0; i < E; i++)
		{
			int x, y;
			cin >> x >> y;
			H.push_back(x);
			P.push_back(y);
		}
		vector<int> R(N, 0); // result
		bool possible = true;
		for (int i = 1; i <= N; i++)
		{
			if (i != T)
			{
				int r = f(i, H, P);
				if (r == -1)
				{
					possible = false;
					break;
				}
				else
				{
					R[i-1] = r;
				}
			}
		}
		if (!possible)
		{
			cout << "Case #" << testCase+1 << ": " << "IMPOSSIBLE" << endl;
		}
		else
		{
			cout << "Case #" << testCase+1 << ":";
			for (int i = 0; i < N; i++)
			{
				cout << " " << R[i];
			}
			cout << endl;
		}
	}
	return 0;
}
