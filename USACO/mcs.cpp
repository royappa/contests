/*
ID: royappa1
LANG: C++
PROG: mcs
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
int dist[60][60][2];

int qr[5000], qc[5000], qp[5000];
int knight[] = {-1,-2, -2,-1, -2,1, -1,2, 1,2, 2,1, 2,-1, 1,-2};
int others[] = {0,-2, -2,0, 0,2, 2,0};

/*
void printmat(int H, int W)
{
	for (int r = 0; r < H; r++)
	{
		for (int c = 0; c < W; c++)
		{
			printf("%c", dist[r][c]>=0?char(dist[r][c]+'0'):'.');
		}
		printf("\n");
	}
	printf("%s\n", string(W,'-').c_str());
}
*/

int bfs(int H, int W, int sr, int sc, int er, int ec)
{
	memset(dist, -1, sizeof(dist));

	int qn = 0, qh = 0, qt = 0;

	qr[qt] = sr;
	qc[qt] = sc;
	qp[qt] = 0;
	qt++;
	qn++;
	dist[sr][sc][0] = 0;
	//printmat(H, W);
	while (qn > 0)
	{
		int r = qr[qh];
		int c = qc[qh];
		int p = qp[qh];
		if (r == er && c == ec)
			return dist[r][c][p];
		qh++;
		qn--;
		int *d, num;
		if (p%2) // last was odd, so this is even
		{
			d = others;
			num = 4;
		}
		else // last was even, so this is odd
		{
			d = knight;
			num = 8;
		}
		int po = (p+1)%2;
		for (int i = 0; i < num; i++)
		{
			int dr = d[2*i], dc = d[2*i+1];
			if (r+dr < 0 || r+dr >= H || c+dc < 0 || c+dc >= W)
				continue;
			if (dist[r+dr][c+dc][po] != -1)
			{
					continue;
			}
			dist[r+dr][c+dc][po] = dist[r][c][p]+1;
			//printf("prev(%d,%d) = (%d,%d)\n", r+dr, c+dc, r, c);
			qr[qt] = r+dr;
			qc[qt] = c+dc;
			qp[qt] = po;
			qt++;
			qn++;
		}
		//printmat(H, W);
	}
	return -1;
}

main ()
{
    ifstream fin("mcs.in");
    ofstream fout("mcs.out");
	int H, W, sr, sc, er, ec;

   	fin >> H >> W;
   	fin >> sr >> sc;
   	fin >> er >> ec;

	fout << bfs(H, W, sr-1, sc-1, er-1, ec-1) << endl;

    exit (0);
}
