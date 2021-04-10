/* New algorithm - not implemented

input range is 1..n
input intervals are i=0,1,...,m-1
define f[i] as follows

f(i) = 1, if e(i) = n
f(i) = 1+MIN(f(j), where
			j > i AND
			b(i) <= b(j) <= e(i) AND
			e(i) < e(j)
		 Note that the MIN expression is defined as oo if no j exists

Then, result = MIN(f(i) where b(i)=1)

Calculate f(i) in table f[i] using dynamic programming as follows

for i := m-1 downto 0 do
	if e(i) = n then
		f[i] = 1
		continue;

	for (each j such that

	add (b[i],e[i]) to a binary search tree

*/
#include <vector>
#include <bits/stdc++.h>
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

int debug = 0;

#define N 50000
#define M 500000

int edge[N+1];
int start[N+1];

int main()
{
	int tests;

	scanf("%d", &tests);

	while (tests-- > 0)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		memset(edge, 0, sizeof(edge));
		int numEdge = 0;
		for (int i = 0; i < m; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a] = max(edge[a], b);
		}
		for (int i = 0; i < n; i++)
		{
			if (edge[i] > 0)
			{
				start[numEdge++] = i;
			}
		}
		if (debug)
		{
			for (int i = 0; i < numEdge; i++)
			{
				printf("%d: %d %d\n", i, start[i], edge[start[i]]);
			}
		}
		int count = 1;
		int pos = 0;
		int end = edge[start[pos]];
		pos++;
		while (end < n)
		{
			count++;
			int newEnd = 0;
			int s = start[pos];
			while (pos < numEdge && s <= end)
			{
				newEnd = max(newEnd, edge[s]);
				s = start[++pos];
			}
			if (debug) printf("count = %d, end = %d, newEnd = %d, pos = %d\n", count, end, newEnd, pos);
			end = newEnd;

		}
		printf("%d\n", count);
	}
	return 0;
}
