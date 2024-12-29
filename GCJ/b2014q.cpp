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
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))


// initial rate is 2 cookies/s
// add +F to rate every time we get another C cookies
// return how long it takes us to get X cookies
// key observation: if a farm is ever necessary, there is no reason to wait. Buy it as soon as you can.
double solve(double C, double F, double X)
{
	// we start with 0 farms
	// with n farms, we grow at the rate (slope) of m=2+n*F
	// the n'th farm starts at t[n]
	vector<double> t(100001), m(100001);
	int n = 0;
	t[0] = 0.0;
	m[0] = 2.0;

	while (n < 100000 && t[n] <= 50000)
	{
		n++;
		// compute t[n] and m[n]
		// currently our slope is m[n-1] cookies per second
		t[n] = t[n-1]+C/m[n-1];
		m[n] = m[n-1]+F;
	}
	// now we have a bunch of lines. Which one reaches "X" cookies first?
	// constraints C,F,X >= 1 means we don't have to worry much about strange boundary cases
	vector<double> y;
	for (int i = 0; i <= n; i++)
	{
		// i'th line y(t) has equation y=m[i]*(t-t[i])
		// solving for y=X, we get X/m[i]+t[i]
		y.push_back(X/m[i]+t[i]);
	}
	sort(y.begin(), y.end());
	return y[0];
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		double C, F, X;
		cin >> C >> F >> X;
		printf("Case #%d: %.9lf\n", testCase, solve(C, F, X));
	}
	return 0;
}
