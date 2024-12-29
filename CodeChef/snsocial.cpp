//https://www.codechef.com/SNCKPB17/problems/SNELECT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
int a[501][501];
set<pair<int,int>> v[2];

int d[] = {-1,-1,-1,0,-1,1, 0,-1,0,1, 1,-1,1,0,1,1};
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;

		int maxx = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				maxx = max(maxx, a[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == maxx) {
					v[0].insert(make_pair(i,j));
				}
			}
		}
		int hours = 0;
		int cur = 0;
		bool changes;
		do {
			changes = false;
			v[1-cur].clear();
			for (auto p : v[cur]) {
				bool surr = true;
				for (int k = 0; k < 8; k++) {
					int di = p.first+d[2*k];
					int dj = p.second+d[2*k+1];
					if (di < 0 || di == n || dj < 0 || dj == m) continue;
					if (a[di][dj] != maxx) {
						surr = false;
						break;
					}
				}
				if (!surr) {
					v[1-cur].insert(p);
				}
			}
			cur = 1-cur;
			v[1-cur].clear();
			for (auto p : v[cur]) {
				for (int k = 0; k < 8; k++) {
					int di = p.first+d[2*k];
					int dj = p.second+d[2*k+1];
					if (di < 0 || di == n || dj < 0 || dj == m) continue;
					if (a[di][dj] != maxx) {
						a[di][dj] = maxx;
						changes = true;
					}
					v[1-cur].insert(make_pair(di,dj));
				}
			}
			if (changes) {
				hours++;
			}
			cur = 1-cur;
		}
		while (changes);
		cout << hours << endl;
	}
	exit(0);
}

