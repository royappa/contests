#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int A[1001][1001];

void fillX(int xa, int xb, int y) {
	for (int i = min(xa, xb); i <= max(xa, xb); i++) {
		A[i][y] = 1;
	}
}

void fillY(int ya, int yb, int x) {
	for (int i = min(ya, yb); i <= max(ya, yb); i++) {
		A[x][i] = 1;
	}
}

int main()
{
	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya;
	cin >> xb >> yb;
	cin >> xc >> yc;

	memset(A, 0, sizeof(A));
	fillX(xa, xb, min(ya, yb));
	fillX(xa, xc, min(ya, yc));
	fillX(xb, xc, min(yb, yc));
	fillY(ya, yb, min(xa, xb));
	fillY(ya, yc, min(xa, xc));
	fillY(yb, yc, min(xb, xc));
	int num = 0;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (A[i][j]) {
				num++;
			}
		}
	}
	cout << num << endl;
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (A[i][j]) {
				num++;
				cout << i << " " << j << endl;
			}
		}
	}
}
