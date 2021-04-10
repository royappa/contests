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
int debug=0;

typedef long long LL;

LL best[510][510];
int prev[510][510];
LL p[510];

int main()
{
	int t;
	scanf("%d", &t);
	while (t-- > 0)
	{
		int d;
		scanf("%d", &d);
		int sum = 0;
		int i = 0;
		while (sum < d)
		{
			i++;
			sum += i;
		}
		int num, den;
		if (i%2 == 0)
		{
			num = 1;
			den = i;
		}
		else
		{
			num = i;
			den = 1;
		}

		for (int k = 0; k < d-(sum-i)-1; k++)
		{
			if (i%2 == 0)
			{
				num++;
				den--;
			}
			else
			{
				num--;
				den++;
			}
		}
		printf("TERM %d IS %d/%d\n", d, num, den);
	}
	return 0;
}
