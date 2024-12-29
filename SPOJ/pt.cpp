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

int p10[23];

bool isPal(int n)
{
	char buf[100];
	sprintf(buf, "%d", n);

	int k = strlen(buf);

	for (int i = 0; i < k/2; i++)
	{
		if (buf[i] != buf[k-i-1])
			return false;
	}
	return true;
}

int main()
{
	p10[0] = 1;
	for (int i = 1; i <= 8; i++)
	{
		p10[i] = p10[i-1]*10;
	}

	int m, s;
	scanf("%d%d", &m, &s);

	int c = 0;
	for (int i = p10[s-1]; i < p10[s]; i++)
	{
		if (isPal(i) && i%m == 0)
		{
			c++;
			printf("%d\n", i);
		}
	}
	printf("total = %d\n", c);
	return 0;
}
