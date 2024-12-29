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
vector<string> solve(int seed)
{
	int pos[MAX_P];
	vector<string> schedule;
	vector< list<int> > q(MAX_N);
	vector<int> unreached;
	int used[MAX_N][MAX_N];
	int count[MAX_N];

	for (int i = 0; i < NP; i++)
	{
		unreached.push_back(i);
		q[src[i]].push_back(i);
		pos[i] = src[i];
	}

	while (unreached.size() > 0)
	{
		map<int,int> step;
		memset(used, 0, sizeof(used));
		bool moved = true;
		int num = 0;
		memset(count, 0, sizeof(count));
		for (int i = 0; i < NP; i++)
		{
			if (pos[i] != dst[i])
				count[pos[i]]++;
		}
		while (moved)
		{
			moved = false;
			int v = rand()%N;
			for (int i = 0; i < N; i++)
			{
				int best = 100000;
				int pi = -1;
				for (list<int>::iterator it = q[v].begin(); it != q[v].end(); it++)
				{
					int pk = *it;
					if (pos[pk] == dst[pk])
						continue;
					if (S[pos[pk]][dst[pk]] < best)
					{
						pi = pk;
						best = S[pos[pk]][dst[pk]];
					}
					break;
				}
				if (pi != -1 && step.count(pi) == 0)
				{
					for (int j = 0; j < nbrCount[v]; j++)
					{
						int best = 10000;
						int kBest;
						for (int k = j; k < nbrCount[v]; k++)
						{
							int vn = adjL[v][k];
							int cost = count[vn] + S[vn][dst[pi]];
							if (cost < best)
							{
								best = cost;
								kBest = k;
							}
						}
						int t = adjL[v][j];
						adjL[v][j] = adjL[v][kBest];
						adjL[v][kBest] = t;
					}
					for (int t = 0; t < nbrCount[v]; t++)
					{
						int vn = adjL[v][t];
						if (!used[v][vn])
						{
							used[v][vn] = used[vn][v] = 1;
							step[pi] = vn;
							count[vn]++;
							count[v]--;
							printf("vertex %d packet %d to vertex %d\n", v, pi, step[pi]);
							moved = true;
							num++;
							break;
						}
					}
				}
				v = (v + 1) % N;
			}
		}
		for (map<int,int>::iterator it = step.begin(); it != step.end(); it++)
		{
			int pi = it->first;
			int vi = it->second;
			// printf("moved %d %d %d\n", pi, pos[pi], vi);
			q[pos[pi]].remove(pi);
			q[vi].push_front(pi);
			pos[pi] = vi;
		}
		// Update schedule
		string s = "";
		unreached.clear();
		for (int i = 0; i < NP; i++)
		{
			if (pos[i] != dst[i])
				unreached.push_back(i);
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
		printf("step %d: %d moves\n", i, c);
	}
	return 1;
}

vector <string> route(int numNodes, vector <string> graph, vector <string> packets)
{
	debug = 0;
	N = numNodes;
	init(graph, packets);
	findAPSP();

	int best = 1<<30;
	vector<string> bestS;
	for (int i = 0; i < 20; i++)
	{
		vector<string> s = solve((i*i*i*i*i)%101+time(NULL));
		if (debug)
		{
			printf("test = %s\n", test(s)?"ok":"bad");
			printf("****\n");
			for (int j = 0; j < packets.size(); j++)
			{
				int x, y;
				sscanf(packets[j].c_str(), "%d%d", &x, &y);
				if (j > 0)
					printf(" ");
				printf("%d", x);
			}
			printf("\n----\n");
			for (int j = 0; j < s.size(); j++)
			{
				printf("%s\n", s[j].c_str());
			}
			printf("----\n");
			for (int j = 0; j < packets.size(); j++)
			{
				int x, y;
				sscanf(packets[j].c_str(), "%d%d", &x, &y);
				if (j > 0)
					printf(" ");
				printf("%d", y);
			}
			printf("\n****\n");
		}

		printf("steps %d \n", s.size());
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
