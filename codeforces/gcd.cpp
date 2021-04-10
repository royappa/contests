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
#include <string>
#include <cstring>

using namespace std;

typedef long long LL;

void gcd(int X, int Y, int& G, int& A, int& B)
{
	if (Y == 0)
		return;

	if (X%Y == 0)
	{
		G = Y;
		A = 0;
		B = 1;
	}
	else
	{
		// X = q*Y+r
		int q = X/Y, r = X%Y;
		// X = q*Y+r
		// gcd(X,Y) = gcd(Y,r)
		int C, D;
		gcd(Y, r, G, C, D);
		// C*Y+D*r = G
		// X-q*Y = r
		// D*X-D*q*Y = D*r = G-C*Y
		// D*X-D*q*Y+C*Y = G
		// D*X+(C-D*q)*Y = G
		A = D;
		B = C-D*q;
	}
	return;
}


int main()
{
	int X, Y;

	cin >> X >> Y;

	if (X < Y)
		swap(X, Y);
	int A, B, G;
	gcd(X, Y, G, A, B);

	printf("%d*(%d) + %d*(%d) = %d %d\n", A, X, B, Y, G, A*X+B*Y);

	exit(0);
}

