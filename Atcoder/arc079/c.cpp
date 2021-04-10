#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<unordered_set<int>> v(N+1);
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].insert(b);
		v[b].insert(a);
	}
	queue<int> q;
	unordered_map<int,int> dist;
	dist[1] = 0;
	q.push(1);
	while (q.size() > 0) {
		int h = q.front();
		q.pop();
		for (auto nbr : v[h]) {
			if (dist.count(nbr) == 0) {
				dist[nbr] = dist[h]+1;
				q.push(nbr);
			}
		}
	}
	if (dist.count(N) > 0 && dist[N] <= 2) {
		cout << "POSSIBLE";
	}
	else {
		cout << "IMPOSSIBLE";
	}
	cout << endl;
	exit(0);
}
