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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int A[10001];

bool poss(vector<int> &v, int x)
{
	int n = v.size();
	if (n == 0)
		return false;

	memset(A, 0, sizeof(A));
	A[0] = 1; // always possible possible to make 0
	for (int c = 0; c < n; c++)
	{
		// A[z] contains whether it is possible to make a value z, with coins in [0,c)
		// We now try to update A[] to include using coin c
		for (int z = x; z >= A[c]; z--)
		{
			A[z] = A[z] || A[z-v[c]]; // already possible to make z without this coin, or, we can make z-v[c] and then use coin c
		}
	}
	return A[x];
}

int main()
{

	int n, x;
	scanf("%d%d", &n, &x);
	vector<int> v;
	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		v.push_back(c);
	}
	vector<int> needed;
	for (int i = 0; i < n; i++)
	{
		int coin = v[0];
		v.erase(v.begin());
		if (!poss(v, x))
		{
			needed.push_back(coin);
		}
		v.push_back(coin);
	}
	int k = needed.size();
	printf("%d\n", k);
	for (int i = 0; i < k; i++)
	{
		if (i > 0) printf(" ");
		printf("%d", needed[i]);
	}
	printf("\n");
}


