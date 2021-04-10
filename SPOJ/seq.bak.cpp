/*

General solution for any LINEAR RECURRENCE using matrix exponentiation. DO NOT USE MATRIX CODE FROM HERE. USE SRM 403.
Tested & correct!
References:http://en.wikibooks.org/wiki/High_School_Mathematics_Extensions/Matrices/Linear_Recurrence_Relations_Revisite

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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

int debug = 1;


/*
  Given a sequence a0,a1,a2...,a[n-1],a[n] defined as follows:
  a[n] = b[n], for 0 <= n < r
 	vector<int> b contains b[i]
  a[n] = c[0]*a[n-1]+c[1]*a[n-2]+...+c[r-1]*a[n-r], for n >= r

  This function will efficiently calculate and return a[p]%MODULUS

  The method for large n, is to set up a matrix equation:

  ( a[n]     )    ( c[0] c[1] c[2] ... c[r-1] )  ( a[n-1] )
  ( a[n-1]   )    ( 1    0    0        0      )  ( a[n-2] )
  ( a[n-2]   )  = ( 0    1    0        0      )  (        )
  ( ......   )    (                ...        )  ( ...    )
  ( a[n-r+1] )    ( 0    0    0      1 0      )  ( a[n-r] )

  Then, multiplying by the matrix on both sides will promote A[n] to A[n+1] in the result.

  By computing A^p for some large power (see below), we just need to first compute A^p and then
  multiply by (A[r-1],...A[0]) = (b[r-1],...,b[0])
  All computations are done modulo some MODULUS
 */

#define MODULUS 1000000000

// change MTYPE to int below if needed, all should still work
typedef long long MTYPE;
typedef vector<MTYPE> vT;
typedef vector<vT> matrixT;

// return new zero-filled matrix
matrixT matNew(int rows, int cols)
{
	matrixT m(rows);

	for (int i = 0; i < rows; i++)
	{
		vT v(cols, 0);
		m[i] = v;
	}
	return m;
}

// Not very efficient because of matrices being dynamically created - only use
// if number of calls will be reasonable!
// X is (p x q) and Y is (q x r)
// Note this procedure has NOT been tested with anything other than squaring of two square matrices (i.e. as used below).
matrixT matMult(matrixT X, matrixT Y)
{
	int p = X.size(), q = X[0].size(), r = Y[0].size();
	matrixT C = matNew(p, r);
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < r; j++)
		{
			MTYPE sum = 0;
			for (int k = 0; k < q; k++)
			{
				MTYPE prod = (X[i][k]*Y[k][j])%MODULUS;
				sum = (sum + prod) % MODULUS;
			}
			C[i][j] = sum;
		}
	}
	return C;
}

int recsolve(vector<int> b, vector<int> c, int r, int n)
{
	if (n < r)
	{
		return b[n]%MODULUS;
	}

	// Now consider cases where n > r
	// For convenience first set p=n-r+1. We need to compute A^p*(A[r-1],...A[0]) = A^p*(b[r-1],...,b[0]).
	int p = n-r+1;

	// First, set up A, which is an (r x r) matrix, according to pattern above
	matrixT A = matNew(r, r);
	for (int i = 0; i < r; i++)
	{
		A[0][i] = c[i];
	}
	for (int i = 1; i < r; i++)
	{
		A[i][i-1] = 1;
	}

	// compute A^p for p >= 1, by repeated squaring
	int t = 0;
	// invariant: M = A^t
	// initially, M = identity matrix
	matrixT M = matNew(r, r);
	for (int i = 0; i < r; i++)
	{
		M[i][i] = 1;
	}
	while (t < p)
	{
		int q = 1;
		int s = p-t;
		matrixT B = A;
		while (2*q < s)
		{
			// pre: B^q
			// compute: C = (B^q)^2 = B^(2*q)
			B = matMult(B, B);
			q *= 2;
		}
		M = matMult(M, B);
		t += q;
	}

	// now M = A^p.
	// Calculate v = Mb, and then return v[0]
	// So just calculate v0 directly

	MTYPE v0 = 0;
	for (int j = 0; j < r; j++)
	{
		MTYPE prod = (M[0][j]*b[r-1-j])%MODULUS;
		v0 = (v0 + prod) % MODULUS;
	}

	return int(v0);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		int r;
		scanf("%d", &r);
		vector<int> b(r, 0), c(r, 0);
		for (int i = 0; i < r; i++)
		{
			scanf("%d", &b[i]);
		}
		for (int i = 0; i < r; i++)
		{
			scanf("%d", &c[i]);
		}
		int n;
		scanf("%d", &n);
		printf("%d\n", recsolve(b, c, r, n-1)); // Note the "n-1" because the solver starts the index of a[i] at 0
	}
	return 0;
}
