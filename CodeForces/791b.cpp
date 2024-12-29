#include <bits/stdc++.h>

//http://codeforces.com/contest/791/problem/A


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main() {

	int n, m;
	cin >> n >> m;
	vector<unordered_set<int>> v(n+1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
	}
	unordered_set<LL> s;
	for (int x = 1; x <= n; x++) {
		for (auto y : v[x]) {

			int xx = min(x, y), yy = max(x, y);
			LL p = (xx<<31LL)|yy;
			if (s.count(p) > 0) continue;
			s.insert(p);

			if (y == x) continue;
			for (auto z : v[y]) {
				if (z == x) continue;
				if (v[z].count(x) == 0) {
					cout << "NO" << endl;
					exit(0);
				}
			}
		}
	}
	cout << "YES" << endl;
}
