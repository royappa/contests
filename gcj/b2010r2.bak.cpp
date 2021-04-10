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
int debug = 0;

int B, T, N;
vector<int> X, V;
int grid[101][101], grid2[101][101];

#define INF (1<<30)

int plays(int i, int g, int P)
{
	int num = 0;


bool mustBuy(int g, int price[], int M[], int P)
{
	for (int i = 0; i < (1<<P); i++)
	{
		int k = plays(i, g, P);
		if (k > M[t])
			return false;
	}
	return true;
}
int main()
{
	int T;
	string s;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int P;
		cin >> P;

		for (int i = 0; i < (1<<P); i++)
		{
			cin >> M[i];
		}
		for (int i = 0; i < P; i++)
		{
			cin >> price[i];
		}
		map<int, vector<int> > teams;
		for (int r = 1; r <= P; r++)
		{
			for (int g = r
		int cost = 0;
		for (int i = 0; i < P; i++))
		{
			if (mustBuy(i, price, M, P))
			{
				cost += price[i];
			}
		}
		printf("Case #%d: %d\n", testCase+1, cost);
	}
	return 0;
}
