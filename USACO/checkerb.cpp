/*
ID: royappa1
LANG: C++
PROG: checker
*/
/* User: royappa1 Password: evarg5f */
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

int rowCol[50];
bool rowUsed[50];
bool colUsed[50];
bool antiDiagUsed[50];
bool diagUsed[50];
int total, N, t2;
int calls = 0;
vector< vector<int> > r;

bool allowed(int row, int col)
{
	return not (rowUsed[row] or colUsed[col] or diagUsed[row+col] or antiDiagUsed[20+row-col]);
}

bool place(int row, int col, bool val)
{
	rowUsed[row] = val;
	colUsed[col] = val;
	diagUsed[row+col] = val;
	antiDiagUsed[20+row-col] = val;
	rowCol[row] = col;
}

void findAll(int row)
{
	if (row > N)
	{
		if (total < 3)
		{
			vector<int> x;
			for (int i = 1; i <= N; i++)
			{
				x.push_back(rowCol[i]);
			}
			r.push_back(x);
		}
		total++;
		if (rowCol[1] == (N+1)/2)
			t2++;
		return;
	}

	for (int col = 1; col <= (N%2==1 && row==1 ? (N+1)/2 : N); col++)
	{
		if (allowed(row, col))
		{
			place(row, col, true);
			findAll(row+1);
			place(row, col, false);
		}
	}
	return;
}

main ()
{
    ifstream fin("checker.in");
    ofstream fout("checker.out");

    fin >> N;

	total = 0;
	t2 = 0;

	findAll(1);
	for (int j = 0; j < 3; j++)
	{
			for (int i = 1; i <= N; i++)
			{
				fout << r[j][i-1];
				if (i < N) fout << " ";
			}
			fout << endl;
	}
	fout << total*2 - t2 << endl;
    exit (0);
}
