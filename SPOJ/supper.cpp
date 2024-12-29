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
int A[100001], L[100001];

int n;

void solve(int n)
{
	L[0] = 1;
	for (int k = 1; k < n; k++)
	{
		L[k] = 1;
		for (int j = 0; j < k; j++)
		{
			if (A[k] >= A[j])
			{
				L[k] = L[j] + 1;
			}
		}
	}
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		cout << L[i] << " ";
		m = max(m, L[i]);
	}
	cout << endl;
	cout << m << endl;
}

int main()
{
	int d;

	d = 10;

	for (int i = 0; i < d; i++)
	{
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[j]);
		}
		solve(n);
	}
	return 0;
}
