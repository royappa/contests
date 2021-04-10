#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

int main()
{
	int A[101][101];

	int H, W;
	int N;
	cin >> H >> W;
	cin >> N;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int cur = 0;
	int row = 0, col = 0;
	int dir = 1;
	while (row < H) {
		if (v[cur] > 0) {
			A[row][col] = 1+cur;
			v[cur]--;
		}
		else {
			cur++;
			A[row][col] = 1+cur;
			v[cur]--;
		}
		col += dir;
		if (row%2 == 0 && col == W) {
			row++;
			col = W-1;
			dir *= -1;
		}
		else if (row%2 == 1 && col == -1) {
			row++;
			col = 0;
			dir *= -1;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A[i][j];
			if (j != W-1) cout << " ";
		}
		cout << endl;
	}
	exit(0);
}
