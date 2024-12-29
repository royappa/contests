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

#define MAX_N 10000

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		int n, SS;
		scanf("%d%d", &n, &SS);

		A[1] = 0;
		S[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			A[i] = A[i-1]+1;
			A[i] = A[i-1]-1;
			S[i] += A[i];
		}
	}
	return 0;
}
