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

#define MAX_NUM (200+1)
#define MAX_FLOW_VAL (1<<30)  // infinity for min-finding
vector< vector<int> > graph; // indexed starting at 0
int n;
int q[MAX_NUM*MAX_NUM+100];
int qn, qh, qt;
bool visited[MAX_NUM];
int prev[MAX_NUM];
int cap[MAX_NUM][MAX_NUM];	// capacity of an edge, at first in original graph, then in residual graph

// Compute and return maximum flow in a network (graph) represented in adjacency-list format in the global variable "graph" as above, with n vertices.
// In this graph, "source" is always vertex 0 and "destination" is always vertex n-1.
// The original graph is directional, but in the adjacency-list, we keep both edges(u,v) and (v,u).
// But if (u,v) is the original "forward" edge, we just set capacity[v][u] (the opposite direction) to zero, initially.


// NOTE:
// This WILL NOT WORK if the original graph can have two forward edges (u,v) and (v,u), i.e. bidirectional.


// search the residual network
int findAugPathBFS()
{
	int src = 0, dst = n-1;	// set source, destination according to application needed

	qn = 0, qh = 0, qt = 0;

	q[qt++] = src;
	qn++;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		prev[i] = -1;
	}
	visited[src] = true;
	if (debug) printf("start\n");
	bool found = false;
	while (qn > 0)
	{
		int cur = q[qh++];
		qn--;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int nbr = graph[cur][i];
			if (cur == dst)
			{
				found = true;
				break;
			}
			if (!visited[nbr] && cap[cur][nbr] > 0)
			{
				visited[nbr] = true;
				prev[nbr] = cur;
				q[qt++] = nbr;
				qn++;
			}
		}
	}
	if (!found)
	{
		return 0;	// No augmenting path
	}

	// Now we know there is a path from src to dst. Walk this path and find the minimum capacity. This will be the augmenting flow.
	int cur = dst;
	int augFlow = MAX_FLOW_VAL;
	while (prev[cur] != -1)
	{
		int p = prev[cur];
		augFlow = min(cap[p][cur], augFlow);
		cur = p;
	}
	// now adjust the flow along the augmenting path
	cur = dst;
	while (prev[cur] != -1)
	{
		int p = prev[cur];
		cap[p][cur] -= augFlow;	// we reduce the capacity of the forward edge
		cap[cur][p] += augFlow;	// and increase the capacity of the reverse edge
		cur = p;
	}
	return augFlow;	// This is how much the augmenting path increased (the smallest flow along the augmenting path)

}
int maxFlow()
{
	// Ford Fulkerson algorithm, with Edmunds Karp variation to use BFS

	int flow = 0, a;
	while ((a = findAugPathBFS()) > 0)
	{
		flow += a;
	}
	return flow;
}
int main()
{
	int test;
	scanf("%d", &test);
	while (test-- > 0)
	{
		graph.clear();
		memset(cap, 0, sizeof(cap));
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			vector<int> dummy;
			graph.push_back(dummy);
		}
		for (int v = 0; v < n-1; v++)	 // in this problem the last vertex is not specified, just understood
		{
			int numAdj;
			scanf("%d", &numAdj);
			for (int j = 0; j < numAdj; j++)
			{
				int w;
				scanf("%d", &w);
				w--; // convert to zero-based nodes
				int c;
				if (v == 0 || w == n-1) // edge with source or destination as one of the vertices
				{
					c = 1;
				}
				else
				{
					c = n+1; // all other edges have infinite capacity
				}
				graph[v].push_back(w);
				cap[v][w] = c;
				graph[w].push_back(v);
				cap[w][v] = 0;
			}
		}
		printf("%d\n", maxFlow());
	}
	return 0;
}
