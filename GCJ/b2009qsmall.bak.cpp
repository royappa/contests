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

typedef pair<int,int> pi;
int A[100][100];
int R[100][100], C[100][100];

void flow(int H, int W)
{
	int d[] = {-1,0,0,-1,0,1,1,0};

	memset(R, -1, sizeof(R));
	memset(C, -1, sizeof(C));
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			// find which sink (i,j) flows into and store that coord in R,C
			// hopefully fast enough to run in ~6 minutes... !
			int r = i, c = j;
			do
			{
				int mr, mc;
				mr = r;
				mc = c;
				for (int k = 0; k < 4; k++)
				{
					int dr = r+d[2*k], dc = c+d[2*k+1];
					if (dr < 0 || dr >= H || dc < 0 || dc >= W) continue;
					if (A[dr][dc] < A[mr][mc])
					{
						mr = dr;
						mc = dc;
					}
				}
				//cout << r << " " << c << " "  << mr << " " << mc << endl;
				if (mr == r && mc == c)
					break;
				r = mr;
				c = mc;
			}
			while (1);
			R[i][j] = r;
			C[i][j] = c;
		}
	}
}

void basins(int H, int W)
{
	char curBasin = 'a';
	map<pi,char> letter;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			int sr = R[i][j], sc = C[i][j];
			pi s = make_pair(sr,sc);
			if (letter.count(s) == 0)
			{
				letter[s] = curBasin++;
			}
			cout << letter[s];
		}
		cout << endl;
	}
}

int main()
{
	int T;

	cin >> T;

	for (int testCase = 0; testCase < T; testCase++)
	{
		int H, W;
		cin >> H >> W;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> A[i][j];
			}
		}
		flow(H, W);
		cout << "Case #" << 1+testCase << ":" << endl;
		basins(H, W);
	}
	return 0;
}
