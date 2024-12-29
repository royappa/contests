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
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;
LL s, x;
int n; // why not
LL memo[43][2][2][2];

LL f(int p, int carry, int apos, int bpos) // number of pairs a,b whose bits [p..42) and carry are compatible with s, x
{
	if (p == n)
	{
		return carry == 0 && apos && bpos ? 1LL : 0LL;
	}
	LL& res = memo[p][carry][apos][bpos];
	if (res != -1LL)
		return res;


	int sp = (s&(1LL<<p)) ? 1 : 0;
	int xp = (x&(1LL<<p)) ? 1 : 0;


	res = 0;
	for (int a = 0; a <= 1; a++)
	{
		for (int b = 0; b <= 1; b++)
		{
			if (a^b != xp) continue;
			if ((a+b+carry)%2 != sp) continue;
			LL r = f(p+1, (a+b+carry)/2, a||apos, b||bpos);
			res += r;
		}
	}
	return res;
}

int main()
{
	cin >> s >> x;
	n = 43; // 2+int(log(s)/log(2)+1); // +2 because we need one extra bit for the carry, and then n has to be bigger than that. Not sure why +3. n=43 is safe.

	memset(memo, -1LL, sizeof(memo));
	cout << f(0, 0, 0, 0) << endl;
}
