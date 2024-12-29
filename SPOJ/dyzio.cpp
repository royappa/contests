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
int debug = 0;

char buf[20*1024];
int n, maxDepth, maxCuts, numCuts;

void cut(int& pos, int depth)
{
	if (pos == n || buf[pos] == '0')
	{
		if (depth > maxDepth)
		{
			maxDepth = depth;
			maxCuts = numCuts;
		}
		pos++;
		return;
	}
	pos++;
	numCuts++;
	cut(pos, depth+1); // left side
	cut(pos, depth+1); // right side;
	return;
}


int main()
{
	int t;
	t = 10;
	while (t-- > 0)
	{
		scanf("%d", &n);
		scanf("%s", buf);
		if (debug) { printf("%d(%s)\n", n, buf); }
		maxDepth = 0;
		maxCuts = 0;
		numCuts = 0;
		int pos = 0;
		cut(pos, 0);
		printf("%d\n", maxCuts);
	}
	return 0;
}
