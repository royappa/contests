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

int S(int n, int m)
{
	if (n == 0 && m == 0)
		return 1;
	else if (n > 0 || m > 0)
		return 0;
	else
		return ((m%2)*S(n-1, m)+S(n-1, m-1))%2;
}

int main()
{
	int t;

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		printf("%d\n", S(n, m));
	}
	return 0;
}
