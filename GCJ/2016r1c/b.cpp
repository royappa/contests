#include <bits/stdc++.h>
// GCJ 2016 R1C, problem B, small inputs

using namespace std;
typedef long long LL;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int B, M;
		cin >> B >> M;
		int t = B*(B-1)-(B-1);
		int A[6][6];
		for (int m = 1; m < (1<<t); m++)
		{
			memset(A, 0, sizeof(A));
			int r = 0, c = 1;
			for (int bit = 0; bit < t; bit++)
			{
				int bval = (m & (1<<bit)) != 0;
				A[r][c] = bval;
				if (bval == 1 && A[c][r] == A[r][c]) goto bad;
				c++;
				if (c == B)
				{
					r++;
					c = 0;
				}
				if (r == c)
					c++;
			}
			goto good;
			bad: continue;
			good:
			int Aorig[6][6];
			for (int i = 0; i < B; i++) for (int j = 0; j < B; j++) Aorig[i][j] = A[i][j];
			for (int k = 0; k < B; k++)
			{
				for (int i = 0; i < B; i++)
				{
					for (int j = 0; j < B; j++)
					{
						A[i][j] += A[i][k]*A[k][j];
					}
				}
			}
			if (A[0][B-1] == M)
			{
				printf("Case #%d: POSSIBLE\n", testCase);
				for (int i = 0; i < B; i++)
				{
					for (int j = 0; j < B; j++)
					{
						cout << Aorig[i][j];
					}
					cout << endl;
				}
				goto nextcase;
			}
		}
		printf("Case #%d: IMPOSSIBLE\n", testCase);
		nextcase: continue;
	}
	return 0;
}
