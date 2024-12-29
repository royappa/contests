// v3: articulation point heuristic added
// v2: fixed the bug whereby some packet could be moved twice in same timestep
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
typedef vector<int> vi;

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
	int art[MAX_N];		// record if a vertex is an articulation point

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

void dfs(int start, int avoid, int visited[])
{
	for (int i = 0; i < nbrCount[start]; i++)
	{
		int vn = adjL[start][i];
		if (!visited[vn] && vn != avoid)
		{
			visited[vn] = 1;
			dfs(vn, avoid, visited);
		}
	}
	return;
}

void findArticulationPoints()
{
	int visited[MAX_N];
	memset(art, 0, sizeof(art));
	for (int v = 0; v < N; v++)
	{
		memset(visited, 0, sizeof(visited));
		int start = v == 0 ? 1 : 0;
		dfs(start, v, visited);
		visited[v] = 0;
		int c = 0;
		for (int i = 0; i < N; i++)
		{
			c += visited[i];
		}
		if (c < N-1)
		{
			art[v] = true;
		}
		/*
		if (art[v])
		{
			printf("vertex %d is an articulation point; count = %d.\n", v, c);
		}
		*/
	}
	return;
}

// Find one solution - any solution, using some rough heuristics
vector<string> solve(int seed)
{
	int pos[MAX_P];
	vector<string> schedule;
	int used[MAX_N][MAX_N];
	int unreached[MAX_P];
	int numLeft = NP;
	int visited[MAX_P][MAX_N];
	int count[MAX_N];
	int done[MAX_P];

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < NP; i++)
	{
		unreached[i] = i;
		pos[i] = src[i];
		visited[i][src[i]] = 1;
	}

	srand(seed);
	while (numLeft > 0) // While some packages not reached
	{
		memset(used, 0, sizeof(used)); // initially in this step, all edges are free
		memset(count, 0, sizeof(count));
		memset(done, 0, sizeof(done));
		int i = 0;
		int q = rand() % numLeft;

		while (i < numLeft) // For each unreached packet
		{
			bool reached = false;
			int pi = unreached[q];
			if (done[pi])
			{
				i++;
				q = (q + 1) % numLeft;
				continue;
			}

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
					int cost;
					cost = art[vpi] ? S[vn][dst[pi]] : 3*count[vn] + 4*S[vn][dst[pi]];
					if (cost < best)
					{
						best = cost;
						jBest = j;
					}
				}
				int t = adjL[vpi][p];
				adjL[vpi][p] = adjL[vpi][jBest];
				adjL[vpi][jBest] = t;
			}

			int b = rand() % 50;

			if (!art[vpi])
			{
				int j = 0;
				for (int t = rand()%4; t < nbr && S[adjL[vpi][t]][dst[pi]] < 3*count[adjL[vpi][0]]+4*S[adjL[vpi][0]][dst[pi]]+5; t++)
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
						done[pi] = 1;
						count[vn]++;
						break;
					}
					j = (j + 1) % nbr;
				}
			}
			else
			{
				int j = 0;
				for (int t = 0; t < nbr && S[adjL[vpi][t]][dst[pi]] <= S[vpi][dst[pi]]; t++)
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
						done[pi] = 1;
						count[vn]++;
						break;
					}
					j = (j + 1) % nbr;
				}
			}
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

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	char *status = NULL;

	char *word;
	vector<string> results;
	while ((word = strtok_r(sC, sepC, &status)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

int test(vector<string> s)
{
	int used[MAX_N][MAX_N];
	for (int i = 1; i < s.size(); i++)
	{
		memset(used, 0, sizeof(used));
		vector<string> v1 = split_nonre(s[i], " ");
		vector<string> v0 = split_nonre(s[i-1], " ");
		int c = 0;
		for (int j = 0; j < NP; j++)
		{
			int va = atoi(v1[j].c_str());
			int vb = atoi(v0[j].c_str());
			if (va == vb)
				continue;
			c++;
			if (used[va][vb] || used[vb][va])
			{
				printf("%d conflict %d %d\n", i, va, vb);
				return 0;
			}
			used[va][vb] = used[vb][va] = 1;
		}
		//printf("step %d: %d moves\n", i, c);
	}
	return 1;
}


vector <string> route(int numNodes, vector <string> graph, vector <string> packets)
{
	debug = 1;
	N = numNodes;
	init(graph, packets);
	findArticulationPoints();
	findAPSP();

	/* print DOT format graph for visualization
	printf("graph\n{\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (adjM[i][j] > 0)
			{
				printf("%d--%d;\n", i, j);
			}
		}
	}
	printf("}\n");
	*/
	int best = 1<<30;
	vector<string> bestS;
	for (int i = 0; i < 10; i++)
	{
		vector<string> s = solve((i*i*i*i*i)%101+time(NULL));
		//printf("%d \n", s.size());
		printf("test = %s\n", test(s)?"ok":"bad");
		if (s.size() < best)
		{
			best = s.size();
			bestS = s;
		}
	}
	return bestS;
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
		/*
		for (int i = 0; i < schedule.size(); i++)
		{
			printf("%s\n", schedule[i].c_str());
		}
		printf("Total: %d steps.\n", schedule.size());
		*/
		printf("Best: %d\n", schedule.size());
	}
	return 0;
}
