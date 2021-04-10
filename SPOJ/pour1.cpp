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
typedef pair<int,int> pi;
#define QMAX 41000
int qa[QMAX];
int qb[QMAX];

int dv[4][QMAX];

int& dist(int A, int B, int a, int b)
{
	if (A == 0 || A == a)
	{
		return A == 0 ? dv[0][B] : dv[1][B];
	}
	return B == 0 ? dv[2][A] : dv[3][A];
}

int minSteps(int a, int b, int c)
{
	if (c == 0)
		return 0;
	int qnum = 0, qhead = 0, qtail = 0;
	memset(dv, -1, sizeof(dv));
	qa[qtail] = 0;
	qb[qtail] = 0;
	qtail++;
	qnum++;
	dist(0, 0, a, b) = 0;
	int kx[10], ky[10];
	while (qnum > 0)
	{
		int A = qa[qhead], B = qb[qhead];
		qhead++;
		if (qhead == QMAX)
			qhead = 0;
		qnum--;
		if (A == c || B == c)
				return dist(A, B, a, b);
		//cout << "pop " << A << " " << B << endl;
		int n = 0;
		kx[n] = 0; ky[n] = B; n++;
		kx[n] = A; ky[n] = 0; n++;
		kx[n] = a; ky[n] = B; n++;
		kx[n] = A; ky[n] = b; n++;
		// A into B until A is empty
		if (b-B >= A)
		{
			kx[n] = 0; ky[n] =  B+A; n++;
		}
		if (b-B <= A) // A into B until B is full
		{
			kx[n] = A-(b-B); ky[n] = b; n++;
		}
		// B into A until B is empty
		if (a-A >= B)
		{
			kx[n] = A+B; ky[n] = 0; n++;
		}
		// B into A until A is full
		if (a-A <= B)
		{
			kx[n] = a; ky[n] = B-(a-A); n++;
		}
		for (int i = 0; i < n; i++)
		{
			int x = kx[i], y = ky[i];
			//cout << "test " << x << " " << y << endl;
			if (dist(x, y, a, b) == -1)
			{
				// cout << "push " << x << " " << y << endl;
				qa[qtail] = x;
				qb[qtail] = y;
				qtail++;
				qnum++;
				if (qtail == QMAX)
					qtail = 0;
				dist(x, y, a, b) = dist(A, B, a, b) + 1;
			}
		}

	}
	return -1;
}


int main()
{
	int t;

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		printf("%d\n", minSteps(a, b, c));
	}
	return 0;
}
