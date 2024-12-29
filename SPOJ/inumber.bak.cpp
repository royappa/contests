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

LL s[1001][20][1001];  // s[L][S][M] = smallest number, L digits long, whose digits add up to S, and whose remainder mod n is M

main()
{

	int t;
	scanf("%d", &t);
	while (t-- > 0
	{
		int n;
		scanf("%d", &n);
		printf("%s\n", inumber(n).c_str());
	}
}
