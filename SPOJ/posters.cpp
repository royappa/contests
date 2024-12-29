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

typedef map<int,int> mii;
mii m;
mii id;

vector< pair<pair<int,int>, int> > changes;
vector<int> changed;

void add(int num, int L, int R)
{
	changes.clear();
	changed.clear();
	// trim everything against L, R
	mii::iterator i = m.lower_bound(L);
	if (i == m.end())
		i = m.begin();
	while (i != m.begin() && i->first >= L)
		i--;
	if (debug)
	{
		if (i == m.end())
		{
			printf("nothing in map\n");
		}
		else
		{
			printf("starting at: [%d,%d]:%d\n", i->first, i->second, id[i->first]);
		}
	}
	for (; i != m.end(); i++)
	{
		int a = i->first, b = i->second;
		if (a > R)
			break;

		if (b < L)
			continue;
		bool overlap = false;
		int idx = id[a];
		if (a <= L)
		{
			if (b <= R)
			{
				// overlap: split [a,b] into [a,L-1]*, [L,b]
				overlap = true;
				changes.push_back(make_pair(make_pair(a,L-1),idx));
			}
			else
			{
				// overlap: split [a,b] into [a,L-1]*,[L,R],[R+1,b]*
				overlap = true;
				changes.push_back(make_pair(make_pair(a,L-1),idx));
				changes.push_back(make_pair(make_pair(R+1,b),idx));
			}
		}
		else // a <= R
		{
			if (b <= R)
			{
				// full overlap - nothing left
				overlap = true;
			}
			else
			{
				// overlap: split [a,b] into [a,R],[R+1,b]*
				overlap = true;
				changes.push_back(make_pair(make_pair(R+1,b),idx));
			}
		}
		if (overlap)
		{
			changed.push_back(a);
		}
	}
	for (int i = 0; i < changed.size(); i++)
	{	m.erase(changed[i]);
		id.erase(changed[i]);
	}
	for (int i = 0; i < changes.size(); i++)
	{
		int x = changes[i].first.first, y = changes[i].first.second;
		if (debug) printf("[%d,%d]\n", x, y);
		if (x <= y)
		{
			m[x] = y;
			id[x] = changes[i].second;
		}
	}
	m[L] = R;
	id[L] = num;
	return;
}


int main()
{
	int t;
	scanf("%d\n", &t);
	while (t-- > 0)
	{
		m.clear();
		id.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int L, R;
			scanf("%d%d", &L, &R);
			add(i, L, R);
		}
		int count = 0;
		vector<bool> mark(n, false);
		for (mii::iterator it = m.begin(); it != m.end(); it++)
		{
			if (debug) printf("[%d,%d]:%d\n", it->first, it->second, id[it->first]);

			if (!mark[id[it->first]])
				count++;
			mark[id[it->first]] = true;
		}

		printf("%d\n", count);
	}
	return 0;
}
