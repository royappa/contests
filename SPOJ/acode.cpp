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

int debug = 0;

using namespace std;

string s;
int n;

typedef long long LL;
map<int,LL> memo;

LL count(int p)
{
	if (debug) cout << p << " " << n << endl;
	int len = n-p;
	if (len == 0)
	{
		if (debug) cout << "return " << p << " 0" << endl;
		return 1LL;
	}
	else if (s[p] == '0')
	{
		if (debug) cout << "return " << p << " 0" << endl;
		return 0LL;
	}
	else if (len == 1)
	{
		if (debug) cout << "return " << p << " 0" << endl;
		return 1LL;
	}

	if (memo.count(p) > 0)
	{
		if (debug) cout << "return " << p << " " << memo[p] << endl;
		return memo[p];
	}

	LL total = count(p+1);
	if (debug && len >= 1) cout << p << " " << n << " "  << s[p] << s[p+1] << " " << s << endl;
	if ((s[p]-'0')*10+(s[p+1]-'0') >= 1 && (s[p]-'0')*10+(s[p+1]-'0')  <= 26)
	{
		total += count(p+2);
	}
	memo[p] = total;
	if (debug) cout << "return " << p << " " <<  total << endl;
	return total;
}

int main()
{
	cin >> s;
	n = s.size();
	while (s != "0")
	{
		memo.clear();
		if (debug) cout << s << endl;
		n = s.size();
		cout << count(0) << endl;
		cin >> s;
	}

	return 0;
}
