#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef pair<int,int> pi;

void walk(int x, int y) {
    queue<pi> q;
    map<pi,int> depth;
    depth[{0,0}] = 0;
    q.push({0,0});
    while (q.size() > 0 && q.size() < 100000) {
        pi h = q.front(); q.pop();
        int r = h.first, c = h.second;
        cout << r << " " << c << " " << depth[h] << endl;
        int d = depth[h];
        int step = 1<<d;
        int dir[] = {-1,0, 0,1, 1,0, 0,-1};  // NESW
        for (int i = 0; i < 4; i++) {
            int dr = r+step*dir[2*i], dc = c+step*dir[2*i+1];
            if (depth.count({dr,dc}) == 0) {
                depth[{dr,dc}] = d+1;
                q.push({dr,dc});
            }
        }
    }
}

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		int x, y;
		cin >> x >> y;
        walk(x, y);

		printf("Case #%d: %s\n", testCase+1, "FOO");
	}
	return 0;
}
