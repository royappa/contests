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

vector<int> v;
int N;
typedef pair<int,int> pii;


// wsum = weird-sum (xor)
// return the biggest subset-sum I can make from [p,N-1] such that the xor of one part summed with lxor equals the xor of the other part summed with rxor
int f(int p, int lxor, rxor)
{
}


int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		cin >> N;
		v.resize(0);
		int allXor = 0;
		for (int i = 0; i < N; i++)
		{
			int C;
			cin >> C;
			allXor ^= C;
			v.push_back(C);
		}
		memset(memo, -1, sizeof(memo));
		int res = f(0, 0);
		if (res == 0)
		{
			cout << "Case #" << testCase+1 << ": " << "NO" << endl;
		}
		else
		{
			cout << "Case #" << testCase+1 << ": " << res << endl;
		}
	}
	return 0;
}
