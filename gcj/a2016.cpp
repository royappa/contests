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
		LL N;
		cin >> N;
		if (N == 0)
		{
			printf("Case #%d: INSOMNIA\n", testCase);
			continue;
		}
		set<int> dig;
		LL last, inc = 1, orig = N;
		do
		{
			N = orig*inc++;
			last = N;
			while (N)
			{
				dig.insert(N%10);
				N /= 10;
			}
		}
		while (dig.size() != 10);
		printf("Case #%d: %lld\n", testCase, last);
	}
	return 0;
}
