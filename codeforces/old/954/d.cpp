#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int getDist(int s, int t, map<int,unordered_set<int>> &e, int n) {
	queue<int> q;
	unordered_map<int,int> dist;
	dist[s] = 0;
	q.push(s);
	while (q.size() > 0) {
		int h = q.front();
		q.pop();
		for (auto nbr : e[h]) {
			if (dist.count(nbr) == 0) {
				if (nbr == t) {
					return dist[h]+1;
				}
				dist[nbr] = dist[h]+1;
				q.push(nbr);
			}
		}
	}
	exit(1);
}
int main()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;

	map<int,unordered_set<int>> e;
	set<int> nodes;
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].insert(v);
		e[v].insert(u);
		nodes.insert(u);
		nodes.insert(v);
	}
	int dist = getDist(s, t, e, n);
	int num = 0;
	vector<int> vn(nodes.begin(), nodes.end());
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			int x = vn[i], y = vn[j];
			if (e[x].count(y) > 0) continue;
			e[x].insert(y);
			e[y].insert(x);
			if (getDist(s, t, e, n) >= dist) {
				num++;
			}
			e[x].erase(y);
			e[y].erase(x);
		}
	}
	cout << num << endl;
	exit(0);
}
