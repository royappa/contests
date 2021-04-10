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

//http://codeforces.com/contest/471/problem/C

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;
map<pLL,bool> memo;

bool f(LL x, LL h)
{
	if (h == 1)
		return true;
	LL z = (h*(h+1LL))/2LL;
	if (x < z)
		return false;
	pLL key = make_pair(x, h);
	if (memo.count(key) > 1)
		return memo[key];

	for (LL k = x-1; k >= 1 && (x-k) >= ((h-1)*(h))/2; k--)
	{
		if (f(x-k, h-1))
			return memo[key] = true;
	}
	return memo[key] = false;
}

bool possible(LL n, LL h)
{
	if (n+h <= 0)
		return false;
	//n = 3*(r1+r2+..rh)-h
	if ((n+h)%3 != 0)
		return false;
	return f((n+h)/3, h);
}


int main()
{
	LL n;

	cin >> n;
	int num = 0;
	for (LL h = 1; h <= 1000001; h++)
	{
		if (possible(n, h))
			num++;
	}
	cout << num << endl;
	exit(0);
}

