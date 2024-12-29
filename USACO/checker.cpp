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
int colRow[50];
int tmp[50];

bool rowUsed[50];
bool colUsed[50];
bool antiDiagUsed[50];
bool diagUsed[50];
int total, N, t2, t3 = 0;
int calls = 0;

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
	colRow[col] = row;
}


void findAll(int row, ofstream& fout)
{
calls++;
	if (row > N)
	{
		total++;
		if (N > 4 && N%2 == 1 && rowCol[1] == (N+1)/2)
			t2++;
		//fout << total << endl;
		if (total <= 3)
		{

			for (int i = 1; i <= N; i++)
			{
				fout << rowCol[i];
				if (i < N) fout << " ";
			}
			fout << endl;
		}
		//////////////////
		/*
		bool flag = true;
		for (int i = 1; i <= N; i++)
		{
			tmp[N+1-i] = rowCol[i];
		}
		for (int i = 1; i <= N; i++)
		{
			if (N+1-rowCol[i] != tmp[i])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			//fout << "yes" << endl;
			total--;
		}
		*/
		//////////////////
		if (true) {//&& (rowCol[1] > (N+1)/2 || colRow[1] > (N+1)/2)) {
			for (int r = 1; r <= N; r++)
			{
				for (int c = 1; c <= N; c++)
				{
					fout << ((rowCol[r] == c) ? "o" : ".");
				}
				fout << endl;
			}
			fout << "*" << endl << endl;
		}
		return;
	}

	for (int col = 1; col <= (N > 4 && N%2==1 && row == 1 ? N/2 : N); col++)
	{
		/*if (col == 1 && row > (N+1)/2)
			continue;*/
		if (allowed(row, col))
		{
			place(row, col, true);
			findAll(row+1, fout);
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

	findAll(1, fout);
	fout << ((N > 4 && N%2==1) ? total*2-t2 : total )<< endl; // << " " << t2 << " " << t3 << endl;
    exit (0);
}
