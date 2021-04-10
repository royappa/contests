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
#include <string>
#include <cstring>

using namespace std;

int memo[1001];

//catalan
int f(int N)
{
	if (N <= 2)
	{
		return 1;
	}
	int &r = memo[N];
	if (r != -1)
		return r;
	r = 0;
	for (int i = 1; i <= N-1; i++)
	{
		r = ((f(i)*f(N-i))%10000+r)%10000;
	}
	return r;
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int N;
		cin >> N;
		memset(memo, -1, sizeof(memo));
		cout << f(N) << endl;
	}
}

