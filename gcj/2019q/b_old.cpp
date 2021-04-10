#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> cell;
typedef pair<cell,cell> edge;

string findPath(map<cell,cell> &path, cell cur)
{
	if (cur == make_pair(1,1)) {
		return "";
	}
	string R = findPath(path, path[cur]);
	cell prev = path[cur];
	string step = prev.first == cur.first ? "E" : "S";
	return R + step;
}

void solve(int testCase, int N, string P) {
	set<edge> forbid;
	int row = 1, col = 1;
	for (int i = 0; i < P.size(); i++) {
		int nrow = row, ncol = col;
		if (P[i] == 'S') nrow = row+1; else ncol = col+1;
		forbid.insert({{row,col},{nrow,ncol}});
		row = nrow;
		col = ncol;
	}
	set<cell> visited;
	queue<cell> q;
	q.push({1,1});
	map<cell,cell> path;
	while (q.size() > 0) {
		cell h = q.front();
		if (h.first == N && h.second == N) {
			break;
		}
		q.pop();
		cell ne = {h.first,h.second+1};
		if (ne.second <= N && forbid.count({h,ne}) == 0 && visited.count(ne) == 0) {
			path[ne] = h;
			visited.insert(ne);
			q.push(ne);
		}
		cell ns = {h.first+1,h.second};
		if (ns.first <= N && forbid.count({h,ns}) == 0 && visited.count(ns) == 0) {
			path[ns] = h;
			visited.insert(ns);
			q.push(ns);
		}
	}
	string R = findPath(path, {N,N});
	cout << "Case #" << testCase << ": " << R << endl;

}
int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{

		int N;
		string P;
		cin >> N >> P;
		solve(testCase, N, P);
	}
	return 0;
}
