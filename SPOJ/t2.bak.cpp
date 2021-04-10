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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long LL;

string start(int n)
{
	string r = "";
	for (int d = 9; d >= 1; d--)
	{
		while (n / d >= 1)
		{
			r += string(n/d, char('0'+d));
			n -= (n/d)*d;
		}
	}
	reverse(r.begin(),r.end());
	return r;
}

main()
{

	for (int i = 1; i <= 200; i++)
	{
		string s = start(i);
		LL si;
		sscanf(s.c_str(), "%lld", &si);
		printf("%d(%lld %lld)", i, si, LL(i)*((si+LL(i)-1LL)/LL(i)));
		si = LL(i)*((si+LL(i)-1LL)/LL(i));
		for (LL j = si; ; j += i)
		{
			int d = 0, k = j;
			while (k > 0)
			{
				d += k % 10;
				k /= 10;
			}
			if (d == i && j % LL(i) == 0)
			{
				printf("%lld\n", j);
				fflush(stdout);
				break;
			}
		}
	}
	exit(0);
}
