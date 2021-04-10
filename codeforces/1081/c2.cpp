#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MOD = 998244353;
int n, m, k;
int A[2][2001][2001];

int main()
{
	cin >> n >> m >> k;
	// how many ways to place the first brick
	int turn = 0;
	for (int c = 0; c < m; c++) {
		A[turn][c][0] = 1;
	}
	// Place one more brick
	// Then A[c][d] represents how many ways could have led to that brick, if it was color c, and after placing it, there were d different bricks
	for (int i = 1; i < n; i++) {
		turn = 1-turn;
		for (int c = 0; c < m; c++) {
			for (int d = 0; d <= k; d++) {
				if (d == 0) {
					A[turn][c][d] = A[1-turn][c][d];
				}
				else {
					for (int x = 0; x < m; x++) {
						if (x == c) continue;
						A[turn][c][d] = (A[turn][c][d] + A[1-turn][x][d-1]) % MOD;
					}
				}
			}
		}
	}
	int res = 0; // count up the final
	for (int c = 0; c < m; c++) {
		res = (res + A[turn][c][k]) % MOD; // add up all the ways in which we had k different bricks and the last was color c
	}
	return res;
}
