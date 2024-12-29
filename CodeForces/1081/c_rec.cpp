#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MOD = 998244353;
int n, m, k;
int A[20][20][20];

// how many ways to color bricks [p..n-1],
// given that the previous color is c,
// and up to d bricks have been different from their left nbr, so far
int f(int p, int c, int d) {
	if (p == n) {
		return d == k;
	}
	int& res = A[p][c][d];
	if (res != -1) {
		return res;
	}
	res = 0;
	if (d == k) { // all remaining colors must stay the same as the nbr to the left, so only one way left to paint
		return res = 1;
	}
	// try all possible different colors for slot p
	for (int i = 0; i < m; i++) {
		if (i != c) {
			res = (res + f(p+1, i, d+1)) % MOD;
		}
	}
	res += f(p+1, c, d);
	return res;
}

int main()
{
	cin >> n >> m >> k;
	memset(A, -1, sizeof(A));
	int res = 0;
	for (int c = 0; c < m; c++) {
		res = (res + f(1, c, 0)) % MOD;
	}
	cout << res << endl;
	exit(0);
}
