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
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

#define INF (1000000)
#define add(a,b)	 ((a)>=INF?INF:(b)>=INF?INF:(a)+(b))


vector<int> v, op, change;
int M; // number of tree nodes

#define RETURN(x) retval=(x); goto END;

int memo[15000][2];

int f(int node, int V) // return min changes to change node to value, or INF if impossible
{
	int& retval = memo[node][V];
	if (retval != -1)
		return retval;

	int orcost=-10, andcost=-10;
	if (node > (M-1)/2) // it is a leaf
	{
		RETURN(v[node] == V ? 0 : INF);
	}
	int L = node*2, R = node*2+1;
	int a = add(f(L,0),f(R,0));
	int b = add(f(L,0),f(R,1));
	int c = add(f(L,1),f(R,0));
	int d = add(f(L,1),f(R,1));

	if (V == 0)
	{
		orcost = a;
		andcost = min(a, min(b, c));
	}
	else
	{
		orcost = min(b, min(c, d));
		andcost = d;
	}

	if (change[node] == 0) // node is interior, and we cannot change it
	{
		RETURN(op[node]==0?orcost:andcost);
	}
	if (op[node] == 0)
	{
		RETURN(min(orcost, add(1,andcost)));
	}
	RETURN(min(andcost, add(1, orcost)));

END:
if (debug) cout << node << " " << V << " " << orcost << " " << andcost << " " << retval << endl;;
	return retval;
}



int main()
{
	int N;
	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int V;
		cin >> M >> V;
		v.resize(M+1, 0);
		op.resize(M+1, 0);
		change.resize(M+1, 0);
		int i;
		for (i = 1; i <= (M-1)/2; i++)
		{
			cin >> op[i] >> change[i];
		}
		for (; i <= M; i++)
		{
			cin >> v[i];
		}

		int num = f(1, V);
		if (num != INF)
		{
			printf("Case #%d: %d\n", testCase+1, num);
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		}
	}
	return 0;
}
