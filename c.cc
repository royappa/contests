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

using namespace std;

class NewAlbum {
public:
int L, cap;
int memo[101];


int f(int n)
{
	if (n*L+(n-1) <= cap && n%13 != 0)
	{
		return 1;
	}
	else if (n*L+(n-1) <= cap && n%13 == 0)
	{
		return 2;
	}
	int &r = memo[n];
	if (r != -1)
		return r;
	
	r = 200;
	for (int p = 1; p <= n/2; p++)
	{
		r = min(r, f(p)+f(n-p));
	}
	return r;
}

int leastAmountOfCDs(int n, int _L, int cap) 
{
	L = _L;
	cap = cap;
	memset(memo, -1, sizeof(memo));
	return f(n);	
}

};
