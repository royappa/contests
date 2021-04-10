// @JUDGE_ID:  1000AA  100  C++  "Easy algorithm"

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

main()
{
	char buf[100];
	while (!cin.getline(buf, 100).eof())
	{
		int a, b;
		sscanf(buf, "%d %d", &a, &b);
		cout << a << " " << b;
		int aa = min(a, b);
		int bb = max(a, b);
		int maxLen = 0;
		for (int i = aa; i <= bb; i++)
		{
			int len = 0;
			int n = i;
			while (n != 1)
			{
				n = (n % 2 == 1) ? 3*n+1 : n/2;
				len++;
			}
			maxLen >?= len;
		}
		cout << " " << maxLen+1 << endl;
	}
	return 0;
}
