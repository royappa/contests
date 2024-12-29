#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


//https://www.hackerrank.com/contests/w19/challenges/fix-the-cycles

#define INF (1<<20)

int main()
{
	int n = 4;
    int Adj[n][n];


    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5;
	int A = 0, B = 1, C = 2, D = 3;

    vector<int> v(6);
    cin >> v[a] >> v[b] >> v[c] >> v[d] >> v[e] >> v[f];

    int best = INF;
    for (int t = 0; t < 6; t++)
    {
		for (int p = 0; p <= 10000; p++)
		{
			for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) Adj[i][j] = INF;

			Adj[D][A] = v[a]+(t==a?p:0);
			Adj[A][B] = v[b]+(t==b?p:0);
			Adj[B][C] = v[c]+(t==c?p:0);
			Adj[C][D] = v[d]+(t==d?p:0);
			Adj[A][C] = v[e]+(t==e?p:0);
			Adj[B][D] = v[f]+(t==f?p:0);


			for (int k = 0; k < n; k++)
			{
				for (int i = 0; i < n; i++)
				{
					for (int j = 0; j < n; j++)
					{
						Adj[i][j] = min(Adj[i][j], Adj[i][k]+Adj[k][j]);
					}
				}
			}
			bool isNeg = false;
			for (int k = 0; k < 4; k++)
			{
				if (Adj[k][k] < 0)
					isNeg = true;
			}
			if (!isNeg)
			{
				best = min(best, p);
				break;
			}
		}
	}
	cout << best << endl;
    return 0;
}
