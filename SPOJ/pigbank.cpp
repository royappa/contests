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

bool A[10000+1];
int M[10000+1];

int solve(int weight, int n, int V[], int W[])
{

	for (int i = 0; i <= weight; i++)
		A[i] = false;
	for (int i = 0; i <= weight; i++)
		M[i] = 1<<30;
	A[0] = true;
	M[0] = 0;

	for (int c = 0; c < n; c++)
	{
		for (int w = 1; w <= weight; w++)
		{
			if (w-W[c] >= 0 && A[w-W[c]])
			{
				A[w] = true;
				M[w] = min(M[w], M[w-W[c]]+V[c]);
			}
		}
	}

	return A[weight] ? M[weight] : -1;
}

int main()
{
	int t;
	int V[500], W[500];

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int e, f;
		cin >> e >> f;
		int n;
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> V[j] >> W[j];
		}

		int m = solve(f-e, n, V, W);
		if (m == -1)
		{
			printf("This is impossible.\n");
		}
		else
		{
			printf("The minimum amount of money in the piggy-bank is %d.\n", m);
		}
	}
	return 0;
}
