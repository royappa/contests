// @JUDGE_ID:  55118HH  108  C++  "Maximum Sum"

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

using namespace std;

int A[110][110];

typedef long long LL;

// CORRECT

main()
{
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> A[i][j];
		}
	}
	// first calculate cumulative sub-sums of A[0][0]..A[i][j]	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// A[i][j] = A[i-1][j]+A[i][j-1]+A[i][j] - A[i-1][j-1]
			if (i > 0)
			{
				A[i][j] += A[i-1][j];
			}
			if (j > 0)
			{
				A[i][j] += A[i][j-1];
			}
			if (i > 0 && j > 0)
			{
				A[i][j] -= A[i-1][j-1];
			}
		}
	}
	// now calculate maxes, using the cumulative sub-sums to calculate sums of region form A[i][j] to A[k][m]
	// in constant time
	LL M = -(1LL<<40LL);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = i; k < N; k++)
			{
				for (int m = j; m < N; m++)
				{
					// LL sum = A[k][m] - A[i-1][m] - A[k][j-1] + A[i-1][j-1];
					LL sum = A[k][m];
					if (i > 0)
					{
						sum -= A[i-1][m];
					}
					if (j > 0)
					{
						sum -= A[k][j-1];
					}
					if (i > 0 && j > 0)
					{
						sum += A[i-1][j-1];
					}
					if (sum > M)
					{
						M = sum;
					}
				}
			}
		}
	}
				
	cout << M << endl;	
	
	exit(0);
}
