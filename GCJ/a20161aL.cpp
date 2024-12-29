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

// GCJ round 1A, problem A, large input
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
		string cur = string(1, S[0]);
		for (int i = 1; i < N; i++)
		{
			if (cur[0] > S[i])
				cur += S[i];
			else
				cur = string(1, S[i])+cur;
		}
		printf("Case #%d: %s\n", testCase, cur.c_str());
	}
	return 0;
}
