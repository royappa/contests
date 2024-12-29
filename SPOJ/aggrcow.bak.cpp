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
int debug=1;

vector<int> A;

bool canPlace(int N, int C, int L)
{
	int last = 0, cur = 0;
	C--;
	do
	{
		while (cur < N && A[cur]-A[last] < L)
		{
			cur++;
		}
		if (cur == N)
		{
			return false;
		}
		C--; // put a cow
		if (C == 0)
			return true;
		last = cur;
	} while (1);
}

int longestStall(int N, int C)
{
	int low = 0, high = A[N-1];
	int mid = 0;
	while (true)
	{
		if (high > low+1)
		{
			mid = (low+high)/2;
			if (canPlace(N, C, mid))
			{
				low = mid;
			}
			else
			{
				high = mid;
			}
		}
		else // high == low+1
		{
			if (canPlace(N, C, high))
			{
				mid = high;
				break;
			}
			mid = low;
			break;
		}
	}
	return mid;
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		int N, C;
		scanf("%d%d", &N, &C);
		A.resize(N, 0);
		for (int i = 0; i < N; i++)
		{
			int x;
			scanf("%d", &x);
			A[i] = x;
			if (debug) printf("%d\n", x);
		}
		sort(A.begin(), A.end());
		if (debug) printf("%d\n", A[0]);
		printf("%d\n", longestStall(N, C));
	}
	return 0;
}
