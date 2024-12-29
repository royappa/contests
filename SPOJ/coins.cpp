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

map<int,long long> memo;

long long solve(int n)
{
	if (n <= 4)
		return n;
	if (memo.count(n) > 0)
		return memo[n];
	long long result = n >? solve(n/2)+solve(n/3)+solve(n/4);
	return memo[n] = result;
}

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		memo.clear();
		cout << solve(n) << endl;
	}
	return 0;
}
