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
char buf[256];
int n;
map<string,int> memo;

// white=w=1=sweet, black=b=0=sour

int maxRock(int k, int b, int w)
{
	if (k == n)
	{
		return w > b ? w + b : 0;
	}
	char key[256];
	sprintf(key, "%d:%d:%d", k, b, w);
	if (memo.count(key) > 0)
	{
		return memo[key];
	}

	int& best = memo[key];
	best = 0;
	int bx = buf[k] == '0';
	int wx = buf[k] == '1';

	return max((w+wx > b+bx ? w+b+wx+bx : 0)+maxRock(k+1, 0, 0), maxRock(k+1, b+bx, w+wx));
}

int main()
{
	int test;
	scanf("%d", &test);
	while (test-- > 0)
	{
		scanf("%d", &n);
		scanf("%s", buf);
		printf("%d\n", maxRock(0, 0, 0));
	}
	return 0;
}
