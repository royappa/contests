// CORRECT
// Single source shortest path Dijkstra's algorithm (SSSP)
// Uses C++ STL priority queue (priority_queue) data structure.
// Priority queue notes:
// 1. C++ STL default priority queue is a MAX heap and we need a MIN heap here.
// 2. When doing this as part of a class, may need to define the "<" operator outside the class.
// 3. Need to include <queue> to get this data structure.
// 4. Note that there is no way to update the priority queue directly. So, we just insert another node with an updated cost (lesser cost).
//    This would mean that a node with an older (larger) value would get pulled later in the process and should be discarded. That is
//	  the purpose of the "visited" array in this case, something which is not actually needed for Dijkstra's algorithm, just needed
//	  for the C++ STL to work.

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
char city[10000][11];

typedef struct {
	int v;
	int cost;
} pqNode;

pqNode *edgeCost[10000];

vector<int> dist(10000);
const int MAX_DIST = 20000;
vector<bool> visited(10000);

bool operator<(const pqNode &left, const pqNode &right)
{
	return left.cost > right.cost; // C++ STL default priority queue is a MAX heap and we need a MIN heap here.
}

int minCost(int n, int src, int dst)
{
	// dijkstra's

	priority_queue<pqNode> pq;

	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	for (int i = 0; i < n; i++)
	{
		dist[i] = MAX_DIST;
	}
	dist[src] = 0;
	pqNode s;
	s.v = src;
	s.cost = 0;
	pq.push(s);
	while (!pq.empty())
	{
		pqNode top = pq.top();
		pq.pop();

		int v = top.v, vCost = top.cost;
		if (visited[v])
			continue;
		visited[v] = true;
		if (v == dst)
		{
			return vCost;
		}
		// For each Neighbor of v, check if we can get to that neighbor cheaper by first visiting v. If so, adjust the neighbor's DIST value
		// (and update that value in the priority queue as well)
		for (int i = 0; edgeCost[v][i].v != -1; i++)
		{
			int vNbr = edgeCost[v][i].v, vToNbrCost = edgeCost[v][i].cost;

			if (dist[v]+vToNbrCost < dist[vNbr])
			{
				dist[vNbr] = dist[v]+vToNbrCost;
				pqNode nbrNode;
				nbrNode.v = vNbr;
				nbrNode.cost = dist[vNbr];
				pq.push(nbrNode);
			}
		}
	}
	return MAX_DIST;
}

int main()
{
	int d;
	scanf("%d", &d);

	for (int i = 0; i < d; i++)
	{
		int n;

		cin >> n;

		for (int j = 0; j < n; j++)
		{
			string c;
			scanf("%s", city[j]);
			int p;
			scanf("%d", &p);
			edgeCost[j] = (pqNode *) malloc(sizeof(pqNode) * (p+1));
			for (int k = 0; k < p; k++)
			{
				int nr, cost;
				scanf("%d%d", &nr, &cost);
				edgeCost[j][k].v = nr-1;
				edgeCost[j][k].cost = cost;
			}
			edgeCost[j][p].v = -1;
		}

		int r;
		cin >> r;
		for (int j = 0; j < r; j++)
		{
			char n1[11], n2[11];
			scanf("%s", n1);
			scanf("%s", n2);
			int v1 = 0, v2 = 0;
			for (int k = 0; k < n; k++)
			{
				if (!strcmp(n1, city[k]))
				{
					v1 = k;
					break;
				}
			}
			for (int k = 0; k < n; k++)
			{
				if (!strcmp(n2, city[k]))
				{
					v2 = k;
					break;
				}
			}

			cout << minCost(n, v1, v2) << endl;
		}
	}
	return 0;
}
