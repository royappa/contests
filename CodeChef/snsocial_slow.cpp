//https://www.codechef.com/SNCKPB17/problems/SNELECT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
int a[501][501];
int v[250000][2], w[250000][2];

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
		int p = 0, q = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] < maxx) {
					v[p][0] = i;
					v[p][1] = j;
					p++;
				}
				else if (a[i][j] == maxx) {
					w[q][0] = i;
					w[q][1] = j;
					q++;
				}
			}
		}
		int hours = 0;
		for (int i = 0; i < p; i++) {
			int z = 1000000000;
			for (int j = 0; j < q; j++) {
				int x = abs(v[i][0]-w[j][0]);
				int y = abs(v[i][1]-w[j][1]);
				z = min(z, max(x, y));
			}
			hours = max(hours, z);
		}
		cout << hours << endl;
	}
	exit(0);
}

