#include <bits/stdc++.h>

using namespace std;

int n, m;
int h[103][103];
int visited[103][103];

void dump() {
	for (int r = 0; r < n+2; r++) {
		for (int c = 0; c < m+2; c++) {
			printf("%2d", h[r][c]);
		}
		printf("\n");
	}
}

// can a column of water H units high stand over position(R,C)?
// Yes if a fish can swim through all connected water at height H without ever going over the edge
// We have added a border of height 0 all around the area so if level H is not enclosed, the fish will eventually
// reach a tile of height 0.

typedef pair<int,int> pi;

bool canPool(int H, int R, int C) {
	queue<pi> q;
	q.push({R, C});
	memset(visited, 0, sizeof(visited));
	visited[R][C] = 1;
	while (!q.empty()) {
		pi head = q.front();
		q.pop();
		int d[] = {-1, 0, 0, 1, 1, 0, 0, -1};
		for (int i = 0; i < 4; i++) {
			int dr = d[2*i], dc = d[2*i+1];
			int r = head.first + dr, c = head.second + dc;
			if (!visited[r][c]) {
				if (h[r][c] == 0) {
					return false; // fell over edge into 0 boundary
				}
				if (h[r][c] < h[R][C] + H) {
					visited[r][c] = 1;
					q.push({r, c});
				}
			}
		}
	}
	return true;
}

// how much water can stand at row R, column C?
int waterHeight(int R, int C) {
	if (!canPool(1, R, C)) {
		return 0;
	}
	int lo = 1, hi = 10000+1; // can(lo) = true, can(hi) = false;
	while (hi != lo+1) {
		int mid = (lo + hi) / 2;
		if (canPool(mid, R, C)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}	
	return lo;
}

int vol() {
	int volume = 0;
	for (int r = 2; r <= n-1; r++) {
		for (int c = 2; c <= m-1; c++) {
			volume += waterHeight(r, c);
		}
	}
	return volume;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		memset(h, 0, sizeof(h));
		scanf("%d%d", &n, &m);	
		for (int r = 1; r <= n; r++) {
			for (int c = 1; c <= m; c++) {
				scanf("%d", &h[r][c]);
			}
		}
		printf("%d\n", vol());
	}
	return 0;
}
