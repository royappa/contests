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

int perm[100001];

int main()
{
	int n;
	scanf("%d", &n);
	while (n > 0)
	{
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &perm[i]);
		}
		bool amb = true;
		for (int i = 1; i <= n; i++)
		{
			if (perm[perm[i]] != i)
			{
				amb = false;
				break;
			}
		}
		printf("%s\n", amb?"ambiguous":"not ambiguous");
		scanf("%d", &n);
	}
	return 0;
}
