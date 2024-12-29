// SEE COMMENTS FOR CODE ATTRIBUTIONS (IF ANY)
// CAN'T FIND RULES ABOUT USING CODE FOUND ON WEB
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
#include <queue>

using namespace std;

#define Dstate(p,s) (((p)<<8)|(s)) // construct a state(p,s) in augmented graph D
#define Dpoint(state) ((state)>>8)
#define Dsum(state) ((state)&((1<<8)-1))

// representation of a pair(distance,state) for priority queue
#define qjoin(dist,state) (((dist)<<16)|(state))
#define qdist(q) ((q)>>16)
#define qstate(q) ((q)&((1<<16)-1))

#define INF 65535
#define LEN 11000
int Ddist[LEN];

typedef pair<int,int> pii;

int main()
{
	int A[200][200];

	int dr[] = {-1, 0, 1, 0};
	int dc[] = { 0, 1, 0,-1};

	int T;
	char buf[1024];
	gets(buf); sscanf(buf, "%d", &T);
	while (T-- > 0)
	{
		int M, N;
		gets(buf); // clear annoying extra blank line in FRONT of each test case
		gets(buf); sscanf(buf, "%d%d", &M, &N);
		memset(A, -1, sizeof(A));
		int startp;
		int points[110][3];
		int np = 0;
		for (int i = 0; i <= M; i++)
		{
			gets(buf);
			for (int j = 0; j <= N; j++)
			{
				if (buf[j] == '*')
				{
					A[i][j] = 0;
					points[np][0] = i;
					points[np][1] = j;
					points[np][2] = 0;
					startp = np;
					np++;
				}
				else if (buf[j] == '.')
				{
					A[i][j] = 0;
				}
				else if (isdigit(buf[j]))
				{
					A[i][j] = buf[j]-'0';
					if (A[i][j] > 0)
					{
						points[np][0] = i;
						points[np][1] = j;
						points[np][2] = A[i][j];
						np++;
					}
				}
			}
		}

		int X;
		gets(buf); sscanf(buf, "%d", &X);

		// construct a new graph D of distance between each pair of digits (including start point)
		int D[110][110];
		memset(D, -1, sizeof(D));
		int q[11000][2];
		int dist[110][110]; // for BFS
		for (int p = 0; p < np; p++)
		{
			memset(dist, -1, sizeof(dist));
			int pr = points[p][0], pc = points[p][1];
			dist[pr][pc] = 0;
			int qn = 0, qh = 0, qt = 0;
			q[qt][0] = pr;
			q[qt][1] = pc;
			qt++;
			qn++;
			while (qn > 0)
			{
				int r = q[qh][0], c = q[qh][1];
				qh++;
				qn--;
				for (int i = 0; i < 4; i++)
				{
					int rr = r+dr[i], cc = c+dc[i];
					if (rr < 0 || rr > M || cc < 0 || cc > N) continue;
					if (dist[rr][cc] >= 0) continue; // visited
					if (A[rr][cc] == -1) continue;
					dist[rr][cc] = dist[r][c]+1;
					q[qt][0] = rr;
					q[qt][1] = cc;
					qt++;
					qn++;
				}
			}
			// bfs starting at point p is complete
			for (int p2 = 0; p2 < np; p2++)
			{
				if (p == p2) continue;
				int p2r = points[p2][0], p2c = points[p2][1];
				D[p][p2] = D[p2][p] = dist[p2r][p2c];
			}
			// check if we should add an edge of length 2 from p to itself
			bool found = false;
			for (int i = 0; i < 4; i++)
			{
				int rr = pr+dr[i], cc = pc+dc[i];
				if (rr < 0 || rr > M || cc < 0 || cc > N) continue;
				if (A[rr][cc] == 0)
				{
					found = true;
					break;
				}
			}
			if (found && points[p][2] != 0)
				D[p][p] = 2;
		}

cout << "points = " << np << endl;
for (int i = 0; i < np; i++)
{
	printf("point %d is (%d,%d,%d)\n", i, points[i][0], points[i][1], points[i][2]);
	for (int j = 0; j < np; j++)
	{
		printf("%d ", D[i][j]);
	}
	printf("\n");
}
cout << endl;

		// now we have constructed a graph D of distances between the original digits in the graph.
		// Run Dijkstra on augmented graph where each node is a state (v,s) where v is a node in D and s is the sum reached so far
		// the number of nodes in this augmented graph can be about 100*100

		for (int i = 0; i < LEN; i++)
			Ddist[i] = INF;
		int startstate = Dstate(startp, 0);
		Ddist[startstate] = 0;
		priority_queue<int> pq;
		pq.push(qjoin(INF-0, startstate)); // pq is a max_pq, so negate dist values
		while (pq.size() > 0)
		{
			int closest = pq.top(); pq.pop();
			int d = INF-qdist(closest), v = qstate(closest);
			if (d > Ddist[v]) continue; // skip outdated vertices that we can't remove from stupid STL pq
			if (d == INF)
				break;
			int p = Dpoint(v), s = Dsum(v);
			for (int nbr = 0; nbr < np; nbr++) // iterate over all neighbors of popped point p
			{
				int step = D[p][nbr];
				if (step == -1) continue;
				int ss = s + points[nbr][2];
				int newdist = d + step;
				if (ss <= X) // reaching this new sum ss stays within our limits?
				{
					// neighbor state is (nbr,ss)
					int newstate = Dstate(nbr, ss);
					if (newdist < Ddist[newstate])
					{
						Ddist[newstate] = newdist;
						pq.push(qjoin(INF-(int)Ddist[newstate], newstate));
					}
				}
			}
		}
		int minmoves = INF;
		for (int st = 0; st < LEN; st++)
		{
			if (Dsum(st) == X)
			{
				minmoves = min(minmoves, (int)Ddist[st]);
			}
		}
		printf("%d\n", minmoves == INF ? -1 : minmoves);
	}

}

