/*
ID: royappa1
LANG: C++
PROG: wall
*/

/*
** Acknowledgement: Used C++ STL documentation from the web at http://www.sgi.com/tech/stl/. The rules mentioned "Java API documentation from the web" is ** allowed, as is system help files. I don't keep C++ STL help files on my system so I used the web.
** I understand that this may result in disqualification if my interpretation of the rules was wrong.
*/
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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef pair<int,int> pi;
typedef vector<int> vi;

int H, F;


#define MULT 100

vi grid[1000][300];
int fx[11000], fy[11000];

int visited[11000];
int dist[11000];
int q[11000];
int nbr[11000];

int shortest(int src)
{
	int qn = 0, qh = 0, qt = 0;

	memset(visited, 0, sizeof(visited));
	memset(dist, 0, sizeof(dist));
	visited[src] = 1;
	dist[src] = 1;
	q[qt++] = src;
	qn++;

	while (qn > 0)
	{
		src = q[qh++];
		qn--;
		if (fy[src] >= H-1000)
			return dist[src];
		int x = fx[src]/MULT, y=fy[src]/MULT;
		int num = 0;
		for (int dx = -1; dx <= 1; dx++)
		{
			for (int dy = -1; dy <= 1; dy++)
			{
				for (int i = 0; i < grid[x+dx][y+dy].size(); i++)
				{
					if (x+dx < 0 || x+dx > 31 || y+dy < 0 || y+dy > 31)
						continue;
					int v = grid[x+dx][y+dy][i];
					if (v == src || visited[v])
						continue;
					int xx = fx[v], yy = fy[v];
					int d2 = (xx-fx[src])*(xx-fx[src])+(yy-fy[src])*(yy-fy[src]);
					if (d2 <= 1000*1000)
					{
						nbr[num++] = v;
					}
				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			int v = nbr[i];
			if (!visited[v])
			{
				visited[v] = 1;
				dist[v] = dist[src]+1;
				q[qt++] = v;
				qn++;
			}
		}
	}
}

main ()
{
    ifstream fin("wall.in");
    ofstream fout("wall.out");

    fin >> H >> F;

	for (int i = 0; i < F; i++)
	{
		fin >> fx[i] >> fy[i];
		grid[fx[i]/MULT][fy[i]/MULT].push_back(i);
	}
	int best = 1<<30;
	for (int i = 0; i < F; i++)
	{
		if (fy[i] <= 1000)
		{
			best = min(best, shortest(i));
		}
	}
	fout << best << endl;

    exit (0);
}
