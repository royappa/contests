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

int main()
{
	int N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int G;
		cin >> G;
		map<int,int> c;
		while (G-- > 0)
		{
			int x;
			cin >> x;
			c[x]++;
		}
		for (typeof(c.begin()) it = c.begin(); it != c.end(); it++)
		{
			if (it->second == 1)
			{
				cout << "Case #" << testCase+1 << ": " << it->first << endl;
				break;
			}
		}
	}
	return 0;
}
