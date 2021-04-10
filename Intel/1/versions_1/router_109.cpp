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

class RoutePackets
{
	static const int MAX_N = 100;
	static const int MAX_P = 2000;

	int adjM[MAX_N][MAX_N];	// adjacency matrix
	int adjL[MAX_N][MAX_N];	// adjacency list
	int S[MAX_N][MAX_N];		// shortest-path cost matrix
	int nbrCount[MAX_N];  	// neighbor count for adjacency list
	int N, NP;				// Number of nodes, packets
	int src[MAX_P], dst[MAX_P];		// start & destination of each packet
	int debug;

public:

void init(vector<string> graph, vector<string> packets)
{
	memset(S, 0, sizeof(S));
	memset(adjM, 0, sizeof(adjM));
	memset(nbrCount, 0, sizeof(nbrCount));

	int ne = graph.size();
	for (int i = 0; i < ne; i++)
	{
		int vi, vj;
		sscanf(graph[i].c_str(), "%d%d", &vi, &vj);
		S[vi][vj] = S[vj][vi] = adjM[vi][vj] = adjM[vj][vi] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adjM[i][j])
			{
				adjL[i][nbrCount[i]++] = j;
			}
		}
	}
	NP = packets.size();
	for (int i = 0; i < NP; i++)
	{
		sscanf(packets[i].c_str(), "%d%d", &src[i], &dst[i]);
	}

	return;
}

void findAPSP()
{
	// Floyd
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a = S[i][j], b = S[i][k], c = S[k][j];
				if (a == 0)
				{
					if (b > 0 && c > 0)
					{
						S[i][j] = b+c;
					}
				}
				else
				{
					if (b > 0 && c > 0)
					{
						int d = b+c;
						if (d < a)
						{
							S[i][j] = d;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		S[i][i] = 0; //?
	}

	if (0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%4d", S[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

// Find one solution - any solution, using some rough heuristics
vector<string> solve()
{
	int pos[MAX_P];
	vector<string> schedule;
	int used[MAX_N][MAX_N];
	int unreached[MAX_P];
	int numLeft = NP;
	int visited[MAX_P][MAX_N];

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < NP; i++)
	{
		unreached[i] = i;
		pos[i] = src[i];
		visited[i][src[i]] = 1;
	}

	srand(time(NULL)+getpid());
	while (numLeft > 0) // While some packages not reached
	{
		memset(used, 0, sizeof(used)); // initially in this step, all edges are free
		int i = 0;
		int q = rand() % numLeft;
		while (i < numLeft) // For each unreached packet
		{
			bool reached = false;
			int pi = unreached[q];

			int vpi = pos[pi]; // current vertex where packet pi is located
			int nbr = nbrCount[vpi];
			for (int p = 0; p < nbr; p++)
			{
				// find closest in p..n-1
				int jBest;
				int best = 100000;
				for (int j = p; j < nbr; j++)
				{
					int vn = adjL[vpi][j]; // neighbor
					if (S[vn][dst[pi]] < best)
					{
						best = S[vn][dst[pi]];
						jBest = j;
					}
				}
				int t = adjL[vpi][p];
				adjL[vpi][p] = adjL[vpi][jBest];
				adjL[vpi][jBest] = t;
			}

			int b = rand() % 50;
			int j = 0;
			bool moved = false;
			for (int t = 0; t < nbr && S[adjL[vpi][t]][dst[pi]] < S[adjL[vpi][0]][dst[pi]]+3; t++)
			{
				int vn = adjL[vpi][j];
				if (!used[vpi][vn]) // && visited[pi][vn] < 20)
				{
					used[vpi][vn] = used[vn][vpi] = 1;
					visited[pi][vn]++;
					pos[pi] = vn;
					if (vn == dst[pi])
					{
						reached = true;
					}
					moved = true;
					break;
				}
				j = (j + 1) % nbr;
			}
			/*
			if (!moved)
			{
				printf("%d: ", pi);
				for (int k = 0; k < N; k++)
				{
					printf("%d ", visited[pi][k]);
				}
				printf("\n");
				//memset(visited[pi], 0, MAX_N*sizeof(int));
			}
			*/
			if (reached) // this packet reached
			{
				unreached[q] = unreached[numLeft-1];
				numLeft--;
				q = 0;
			}
			else
			{
				i++;
				q = (q + 1) % numLeft;
			}
		}
		// Update schedule
		string s = "";
		for (int i = 0; i < NP; i++)
		{
			char buf[100];
			sprintf(buf, "%d", pos[i]);
			if (i > 0)
				s += " ";
			s += buf;
		}
		schedule.push_back(s);
	}
	return schedule;
}


vector <string> route(int numNodes, vector <string> graph, vector <string> packets)
{
	debug = 1;
	N = numNodes;
	init(graph, packets);
	findAPSP();

	return solve();

}

};

int main()
{
	char buf[256];
	int t;
	gets(buf);
	sscanf(buf, "%d", &t);
	while (t-- > 0)
	{
		RoutePackets router;
		vector<string> graph;
		int N, NP;
		gets(buf);
		sscanf(buf, "%d%d", &N, &NP);
		for (int r = 0; r < N; r++)
		{
			gets(buf);
			for (int c = 0; c < r; c++)
			{
				if (buf[c] == '1')
				{
					char edge[100];
					sprintf(edge, "%d %d", r, c);
					graph.push_back(edge);
				}
			}
		}
		vector<string> packets;
		for (int i = 0; i < NP; i++)
		{
			gets(buf);
			packets.push_back(buf);
		}

		vector<string> schedule = router.route(N, graph, packets);

		for (int i = 0; i < schedule.size(); i++)
		{
			printf("%s\n", schedule[i].c_str());
		}
		printf("Total: %d steps.\n", schedule.size());
	}
	return 0;
}
