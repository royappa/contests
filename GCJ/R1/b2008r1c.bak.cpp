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
int debug = 1;
char buf[4096];
typedef long long LL;
string s;
int n;
LL memo[50][2][3][5][7];

#define MF(a,m) (((a)%(m)+(m))%(m))

LL f(int p, int m2, int m3, int m5, int m7) // how many numbers can be made from [p,n) such that their remainder mod 2,3,5, or 7 is m2,m3,m5, or m7
{
	if (p == n)
	{
		int x = (m2 == 0 || m3 == 0 || m5 == 0 || m7 == 0);
if (debug) cout << p << " " << m2 << " " << m3 << " " << m5 << " " << m7 << " = " << x <<  "*" << endl;
		return x;
	}

	LL& r = memo[p][m2][m3][m5][m7];
	if (r != -1)
		return r;

	r = 0;
	int k2 = 0, k3 = 0, k5 = 0, k7 = 0;
	for (int i = p; i < n; i++)
	{
		// split into [p,i] to [i+1,n)
		k2 = (k2*10+(s[i]-'0'))%2;
		k3 = (k3*10+(s[i]-'0'))%3;
		k5 = (k5*10+(s[i]-'0'))%5;
		k7 = (k7*10+(s[i]-'0'))%7;
		r += f(i+1, MF(m2-k2,2), MF(m3-k3,3), MF(m5-k5,5), MF(m7-k7,7));
		if (i+1 < n)
			r += f(i+1, MF(k2-m2,2), MF(k3-m3,3), MF(k5-m5,5), MF(k7-m7,7));
	}
if (debug) cout << p << " " << m2 << " " << m3 << " " << m5 << " " << m7 << " = " << r <<  endl;

	return r;
}

int main()
{
	fgets(buf, 4096, stdin); // BE CAREFUL OF WINDOWS vs LINUX \n or \n\r!
	int N;
	sscanf(buf, "%d", &N);
	for (int testCase = 0; testCase < N; testCase++)
	{
		fgets(buf, 4096, stdin);
		int z = strlen(buf)-1;
		while (z >= 0 && (buf[z] == '\r' || buf[z] == '\n')) buf[z--] = '\0';
		s = string(buf);
		n = s.size();
		memset(memo, -1, sizeof(memo));
		printf("Case #%d: %lld\n", testCase+1, f(0, 0, 0, 0, 0));
	}
	return 0;
}
