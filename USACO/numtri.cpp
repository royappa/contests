/*
ID: royappa1
LANG: C++
PROG: numtri
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

int A[1000][1000];
main ()
{
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int N;
    fin >> N;
    for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < i+1; j++)
		{
			fin >> A[i][j];
		}
	}

	for (int r = N-2; r >= 0; r--)
	{
		for (int j = 0; j < r+1; j++)
		{
			A[r][j] += max(A[r+1][j], A[r+1][j+1]);
		}
	}
	fout << A[0][0] << endl;

    exit (0);
}
