#include <bits/stdc++.h>

using namespace std;

#define NODE(i,j,R) ((i)*(R)+(j))

void flood(int r, int c, int N, int M, vector<vector<int>> &v, vector<vector<int>> &done) { // mark every reachable place
	queue<int> q;
	unordered_map<int,int> dist;
	int h = NODE(r,c,M);
	dist[h] = 0;
	int maxd = v[r][c];
	q.push(h);
	vector<int> d = {0,-1, -1,0, 0,1, 1,0};

	while (q.size() > 0) {
		h = q.front();
		q.pop();
		r = h/M;
		c = h%M;
		for (int i = 0; i < 4; i++) {
			int nr = r+d[2*i], nc = c+d[2*i+1];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
			int nbr = NODE(nr,nc,M);
			if (dist.count(nbr) > 0) continue; // already visited
			if (dist[h]+1 > maxd || v[nr][nc] == -1) {
				dist[nbr] = 1000000000; // don't visit it again
				continue;
			}
			dist[nbr] = dist[h]+1;
			done[nr][nc] = 1;
			q.push(nbr);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T-- > 0)
	{
		int N, M;
		cin >> N >> M;
		vector<vector<int>> v(N, vector<int>(M));
		vector<vector<int>> done(N, vector<int>(M));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int x;
				scanf("%d", &x);
				v[i][j] = x;
				done[i][j] = 0;
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] >= 1) {
					flood(i, j, N, M, v, done);
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (v[i][j] < 0) {
					putchar('B');
				}
				else if (v[i][j] > 0) {
					putchar('Y');
				}
				else if (done[i][j]) {
					putchar('Y');
				}
				else {
					putchar('N');
				}
			}
			putchar('\n');
		}
	}
	exit(0);
}

