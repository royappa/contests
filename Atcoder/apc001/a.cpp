#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int N;
int A[2][101];
int memo[2][101];

int f(int r, int c) {
	if (r == 1 && c == N-1) {
		return A[r][c];
	}
	int& res = memo[r][c];
	if (res != -1) return res;

	res = A[r][c];
	if (r == 0) {
		int t = f(1, c);
		if (c != N-1) {
			t = max(t, f(0, c+1));
		}
		res += t;
	}
	else {
		res += f(1, c+1);
	}
	return res;
}
int main()
{
	cin >> N;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}
	}
	memset(memo, -1, sizeof(memo));
	cout << f(0, 0) << endl;
	exit(0);
}
