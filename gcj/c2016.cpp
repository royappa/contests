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

LL bc(int x, int base)
{
	if (x == 0) return 0;
	return bc(x/2, base)*LL(base)+(x%2);
}

LL getDiv(LL num)
{
	LL d = 2;
	while (d*d <= num)
	{
		if (num%d == 0)
			return d;
		d++;
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
		for (int mask = (1<<N)/2+1; mask < (1<<N) && J > 0; mask += 2)
		{
			vector<LL> divisors;
			for (int base = 2; base <= 10; base++)
			{
				LL num = bc(mask, base);
				LL div = getDiv(num);
				//cout << mask << " " << base << " " << num << " " << div << endl;
				if (div == -1LL) break;
				divisors.push_back(div);
			}
			if (divisors.size() != 9) continue;
			J--;
			string s = "";
			int t = mask;
			while (t) { s += char('0')+(t%2); t /= 2; } reverse(s.begin(), s.end());
			cout << s;
			for (auto z : divisors) cout << " " << z; cout << endl;
		}
	}
	return 0;
}
