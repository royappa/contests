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
#include <string>
#include <cstring>

//http://codeforces.com/contest/472/problem/D

using namespace std;

typedef long long LL;

int A[2001][2001];
int n;
int main()
{

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (A[i][i] != 0)
		{
			cout << "NO";
			exit(0);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != A[j][i])
			{
				cout << "NO";
				exit(0);
			}
		}
	}

	cout << "YES";
	exit(0);
}

