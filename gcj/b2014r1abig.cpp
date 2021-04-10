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
#include <string.h>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)

typedef map<int,vector<int>> graph;
typedef map<int,int> mii;
int calc(int r, graph& A, mii& num, mii& visited)
{
	int kids = 0;
	visited[r] = 1;
	for (int i = 0; i < A[r].size(); i++)
	{
		if (visited[A[r][i]]) continue;
		kids += calc(A[r][i], A, num, visited);
	}
	return num[r] = 1+kids;
}

int prune(int r, graph& A, mii& num)
{
	queue<int> q;
	mii visited;

	q.push(r);
	visited[r] = 1;

	int del = 0;

	while (!q.empty())
	{
		int qh = q.front();
		q.pop();
		vector<pair<int,int>> tc;
		for (int i = 0; i < A[qh].size(); i++)
		{
			int child = A[qh][i];
			if (visited[child]) continue;
			tc.push_back(make_pair(num[child],child));
		}
		if (tc.size() == 1)
		{
			del += tc[0].first;
			continue;
		}
		if (tc.size() > 2)
		{
			sort(tc.begin(), tc.end());
			int bad = int(tc.size())-2;
			for (int i = 0; i < bad; i++)
			{
				del += tc[i].first;
				tc.erase(tc.begin());
			}
		}
		for (int i = 0; i < tc.size(); i++)
		{
			visited[tc[i].second] = 1;
			q.push(tc[i].second);
		}
	}
	return del;
}


int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;

		graph A;
		set<int> v;
		for (int i = 0; i < N-1; i++)
		{
			int x, y;
			cin >> x >> y;
			v.insert(x);
			v.insert(y);
			A[x].push_back(y);
			A[y].push_back(x);
		}
		int best = MAXVAL;
		for (auto it = v.begin(); it != v.end(); it++)
		{
			int r = *it;
			mii num, visited;
			num[r] = calc(r, A, num, visited);

			best = min(best, prune(r, A, num));
		}

		printf("Case #%d: %d\n", testCase, best);
	}
	return 0;
}
