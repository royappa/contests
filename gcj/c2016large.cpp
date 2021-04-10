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
typedef long long LL;

LL getDiv(LL mask, LL base)
{
	vector<LL> divs = {3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59};
	vector<int> digits;
	while (mask)
	{
		digits.push_back(mask%2);
		mask /= 2;
	}

	for (auto p : divs)
	{
		LL mod = 0;
		LL powMod = 1;
		for (int i = 0; i < digits.size(); i++)
		{
			mod += (digits[i]*powMod)%p;
			powMod = (powMod*base)%p;
		}
		if (mod%p == 0)
			return p;
	}
	return -1LL;
}

int main()
{
	int T;
	cin >> T;

	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N, J;
		cin >> N >> J;
		printf("Case #%d:\n", testCase);
		for (LL mask = (1LL<<N)/2+1; mask < (1LL<<N) && J > 0; mask += 2LL)
		{
			vector<LL> divisors;
			for (LL base = 2; base <= 10; base++)
			{
				LL div = getDiv(mask, base);
				//cout << mask << " " << base << " " << div << endl;
				if (div == -1LL) break;
				divisors.push_back(div);
			}
			if (divisors.size() != 9) continue;
			J--;
			string s = "";
			LL t = mask;
			while (t) { s += char('0')+(t%2); t /= 2; } reverse(s.begin(), s.end());
			cout << s;
			for (auto z : divisors) cout << " " << z; cout << endl;
		}
	}
	return 0;
}
