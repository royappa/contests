/*
ID: royappa1
LANG: C++
PROG: stroll
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

int A[40][40];
int H, W, rowBarn, colBarn;
int memo[40][40];

int paths(int r, int c)
{
	if (r == rowBarn && c == colBarn)
	{
		return 1;
	}

	int &num = memo[r][c];
	if (num != -1)
		return num;
	num = 0;
	int d[] = {0,1, 1,0};
	for (int i = 0; i < 2; i++)
	{
		int dr = r+d[2*i], dc = c+d[2*i+1];
		if (dr > rowBarn || dc > colBarn)
			continue;
		if (A[dr][dc])
			continue; // rock
		num += paths(dr, dc);
	}
	return num;
}

main ()
{
    ifstream fin("stroll.in");
    ofstream fout("stroll.out");

    int N;
    fin >> H >> W;

	memset(A, 0, sizeof(A));
	memset(memo, -1, sizeof(memo));

	int rowBetsy = -1, colBetsy = -1;
	rowBarn = -1, colBarn = -1;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			char ch;
			fin >> ch;
			A[i][j] = ch == '.' ? 0 : 1;
			if (ch == 'B')
			{
				A[i][j] = 0;
				if (rowBetsy == -1)
				{
					rowBetsy = i;
					colBetsy = j;
				}
				else
				{
					rowBarn = i;
					colBarn = j;
				}
			}
		}
	}

	fout << paths(rowBetsy, colBetsy) << endl;

    exit (0);
}
