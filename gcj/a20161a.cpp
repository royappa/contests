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
typedef long long LL;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string S;
		cin >> S;
		int N = S.size();
		set<string> w;
		w.insert(string(1, S[0]));
		//for (auto x : w) cout << x << endl;
		for (int i = 1; i < N; i++)
		{
			set<string> ww;
			for (auto z : w)
			{
				ww.insert(z+S[i]);
				ww.insert(string(1, S[i])+z);
			}
			w = ww;
		}
		string q;
		for (auto x : w) q = x;
		printf("Case #%d: %s\n", testCase, q.c_str());
	}
	return 0;
}
