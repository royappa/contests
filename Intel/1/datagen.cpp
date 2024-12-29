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

int rand_between(int a, int b)
{
	return a + rand() % (b-a+1);
}

double drand_between(double a, double b)
{
	return double(a+drand48()*(b-a));
}

void findAPSP(int S[][101], int N)
{
	// Floyd
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int a = S[i][j], b = S[i][k], c = S[k][j];
				if (a == 0)
				{
					if (b > 0 && c > 0)
					{
						S[i][j] = b+c;
					}
				}
				else
				{
					if (b > 0 && c > 0)
					{
						int d = b+c;
						if (d < a)
						{
							S[i][j] = d;
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		S[i][i] = 0; //?
	}
	if (0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				printf("%4d", S[i][j]);
			}
			printf("\n");
		}
	}
	return;
}

int main()
{
	int A[101][101];
	double x[101], y[101];
	double r[101];
	int N;
	int B[101][101];

	srand(time(NULL)*getpid());
	srand48(time(NULL)*getpid());
	int tries = 0;
	bool connected;
	do
	{
		connected = true;
		N = rand_between(5, 5); // 2,100
		double lower = drand_between(5, 30);
		double upper = drand_between(5, 30);

		if (upper < lower)
		{
			double t = lower;
			lower = upper;
			upper = t;
		}

		for(int i = 0; i < N; i++)
		{
			do
			{
				x[i] = drand_between(-50, 50);
				y[i] = drand_between(-50, 50);
			}
			while (x[i]*x[i]+y[i]*y[i] > 50*50);
			r[i] = drand_between(lower, upper);
		}
		memset(A, 0, sizeof(A));
		for(int i = 0; i < N; i++)
		{
			for(int j = i+1; j < N; j++)
			{
				double dij = hypot(x[i]-x[j], y[i]-y[j]);
				if(dij < r[i] && dij < r[j])
				{
					A[i][j] = A[j][i] = true;
				}
			}
		}
		memcpy(B, A, sizeof(A));
		findAPSP(A, N);
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (A[i][j] == 0)
				{
					connected = false;
					break;
				}
			}
		}
	} while (!connected);
	int M = rand_between(5, 5); // 10, 2000
	printf("%d %d\n", N, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%c", B[i][j] ? '1' : '0');
		}
		printf("\n");
	}
	for(int i = 0; i < M; i++)
	{
		int p0, p1;
		do
		{
			p0 = rand_between(0, N-1);
			p1 = rand_between(0, N-1);
		}
		while (p0 == p1);
		printf("%d %d\n", p0, p1);
	}

	return 0;
}
