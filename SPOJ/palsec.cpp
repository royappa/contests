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
//#include <hash_map.h>

using namespace std;

int debug = 0;

char *cp(char *s)
{
	char *buf = (char *)malloc(strlen(s)+1);
	strcpy(buf, s);
	return buf;
}

vector<string> X, Y;
int n;
typedef long long LL;

map<string,LL> memo;
char buf[400*30+1024];

int isPal(string s)
{
	int len = s.size();

	for (int i = 0; i < len/2; i++)
	{
		if (s[i] != s[len-1-i])
			return 0;
	}
	return 1;
}

bool match(string& L, string& R)
{
	int a = 0, b = int(R.size())-1;

	while (a < L.size() && b >= 0)
	{
		if (L[a] != R[b])
			return false;
		a++;
		b--;
	}
	L = (a >= L.size()) ? "" : L.substr(a);
	R = (b < 0) ? "" : R.substr(0, b+1);
	return true;
}

LL f(int m, string left, string right)
{
	sprintf(buf, "%d:%s:%s", m, left.c_str(), right.c_str());
	string key = cp(buf)	;
	if (memo.count(key) > 0)
	{
		return memo[key];
	}

	LL& r = memo[key];

	r = 0;
	if (n%2 == 0 && m == n/2)
	{
		return r = isPal(left+right);
	}
	if (n%2 == 1 && m == (n-1)/2)
	{
		return r = isPal(left+X[m]+right)+isPal(left+Y[m]+right);
	}

	r = 0;

	int p = n-1-m;

	string L, R;

	L = left+X[m];
	R = X[p]+right;
	if (match(L, R))
	{
		r += f(m+1, L, R);
	}

	L = left+X[m];
	R = Y[p]+right;
	if (match(L, R))
	{
		r += f(m+1, L, R);
	}

	L = left+Y[m];
	R = X[p]+right;
	if (match(L, R))
	{
		r += f(m+1, L, R);
	}

	L = left+Y[m];
	R = Y[p]+right;
	if (match(L, R))
	{
		r += f(m+1, L, R);
	}
	return r;
}

LL solve()
{
	memo.clear();
	return f(0, "", "");
}

int main()
{
	int t;
	char buf[1024];

	cin >> t;

	while (t-- > 0)
	{
		cin >> n;
		X.clear();
		Y.clear();
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			X.push_back(s);
		}
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			Y.push_back(s);
		}
		printf("%lld\n", solve());
	}

	return 0;
}
