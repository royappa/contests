#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
const int MOD = 1000000007;

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		vector<vector<int>> v(n);
		for (int i = 0; i < n; i++) {
			int len;
			scanf("%d", &len);
			v[i].resize(len);
			for (int j = 0; j < len; j++) {
				int x;
				scanf("%d", &x);
				v[i][j] = x;
			}
		}
		set<int> all;
		for (int i = 1; i <= k; i++) {
			all.insert(i);
		}
		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				set<int> u;
				u.insert(v[i].begin(), v[i].end());
				u.insert(v[j].begin(), v[j].end());
				if (u == all) {
					num++;
				}
			}
		}
		cout << num << endl;
	}
	exit(0);
}

