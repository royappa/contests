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

int best[210][410];


int main()
{
	int test;
	scanf("%d", &test);
	while (test-- > 0)
	{
		int n;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &A[i][j]);
			}
		}
		memset(memo, -1, sizeof(memo));
		printf("%d\n", f(0, 0));
	}
	return 0;
}
