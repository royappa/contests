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

int solve(int N, int L, int H, vector<int> &notes)
{
	for (int f = L; f <= H; f++)
	{
		bool all = true;
		for (int i = 0; i < N; i++)
		{
			if (notes[i] % f == 0 || f % notes[i] == 0) continue;
			all = false;
			break;
		}
		if (all)
			return f;
	}
	return -1;
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N, L, H;

		cin >> N >> L >> H;
		vector<int> notes;
		for (int i = 0; i < N; i++)
		{
			LL x;
			cin >> x;
			notes.push_back(x);
		}
		int f = solve(N, L, H, notes);
		if (f == -1)
		{
			cout << "Case #" << testCase+1 << ": " << "NO" << endl;
		}
		else
		{
			cout << "Case #" << testCase+1 << ": " << f << endl;
		}
	}
	return 0;
}
