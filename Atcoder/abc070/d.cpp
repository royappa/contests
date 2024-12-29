#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	map<int,set<int>> adj;
	map<pair<int,int>,int> cost;
	int N;
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].insert(b);
		adj[b].insert(a);
		cost[make_pair(a, b)] = c;
		cost[make_pair(b, a)] = c;
	}
	int Q, K;
	cin >> Q >> K;
	// calc single source shortest path distance from K to all others
	map<int,LL> dist;
	dist[K] = 0;
	queue<int> q;
	q.push(K);
	while (q.size() > 0) {
		int h = q.front();
		q.pop();
		for (auto v : adj[h]) {
			if (dist.count(v) == 0) {
				q.push(v);
				dist[v] = dist[h]+cost[make_pair(h,v)];
			}
		}
	}
	for (int i = 0; i < Q; i++) {
		int x, y;
		cin >> x >> y;
		cout << dist[x]+dist[y] << endl;
	}
	exit(0);
}
