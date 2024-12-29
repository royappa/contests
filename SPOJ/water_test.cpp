#include <bits/stdc++.h>

using namespace std;
#ifdef DEBUG
int debug = 1;
#else
int debug = 0;
#endif

int n, m;
int h[101][101];
int v[101][101];
int vLake[101][101];

int d[] = {-1,0, 0,1, 1,0, 0,-1};

struct ph {
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const {
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);
		return h1 ^ h2;
	}
};

void dump() {
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			printf("%4d", h[r][c]);
		}
		printf("\n");
	}
}

typedef pair<int,int> pt;

void fillLake(pair<int,unordered_set<pt,ph>> &lake, unordered_set<pt,ph> &b, unordered_set<pt,ph> &bi, int &volume) {
	auto [level, lakePoints] = lake;
	for (auto x : lakePoints) {
		auto [r,c] = x;
		volume += max(level-h[r][c], 0);
		v[r][c] = 1;
	}
	for (auto x : lakePoints) {
		auto [r,c] = x;
		for (int i = 0; i < 4; i++) {
			int dr = d[2*i], dc = d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			if (v[dr][dc] == 0) {
				bi.insert({dr,dc});
			}
		}
	}
	return;
}

void dumph(unordered_set<pt,ph> &b, unordered_set<pt,ph> &e) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %c", b.count({i,j}) > 0 ? 'b' : e.count({i,j}) > 0 ? 'e' : '-');
		}
		printf("\n");
	}
}

void bfsBoundary(pt start, unordered_set<pt,ph> &b) {
	queue<pt> q;
	q.push(start);
	v[start.first][start.second] = 1;
	while (q.size() > 0) {
		auto [r,c] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dr = r+d[2*i], dc = c+d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			if (h[dr][dc] >= h[r][c] && v[dr][dc] == 0) {
				v[dr][dc] = 1;
				b.insert({dr,dc});
				q.push({dr,dc});
			}
		}
	}
}

// isolate and process each lake:
//   start with any known lake edge
//   crawl until all reachable lake edges are found. this is the edge-ring of that lake. also find the lowest border, this is the water level of that lake.
//   add those points to a list, sorted by decreasing height, mark as visited, if any is under water, add its volume, then reset its height to waterlevel -1
//   from each point, explore to any unvisited neighbor x that is waterlevel-1 or less. 
//   	any neighbors of waterlevel or more must be island boundaries, add to a list


void processLakes(unordered_set<pt,ph> &b, unordered_set<pt,ph> &bi, int &volume) {
	unordered_set<pt,ph> e;
	memset(vLake, 0, sizeof(vLake));

	// find all lake edges
	for (auto x : b) {
		auto [r,c] = x;
		for (int i = 0; i < 4; i++) {
			int dr = r+d[2*i], dc = c+d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			if (v[dr][dc] == 0) {
				e.insert({dr,dc});
			}
		}
	}

if (debug) dumph(b, e);

	// process each lake separately
	for (auto x : e) {
		auto [r,c] = x;
		if (vLake[r][c]) continue;
		int waterLevel = 1e6;
		// BFS from this lake edge
		queue<pt> q;
		q.push(x);
		vLake[r][c] = 1; // visit the entire lake starting from here, including all parts of interior islands and sublakes, and isolate the edges of this lake
		unordered_set<pt,ph> eLake;
		while (q.size() > 0) {
			auto [nr,nc] = q.front();
			q.pop();
			// check if this point is a lake edge
			for (int i = 0; i < 4; i++) {
				int dr = nr+d[2*i], dc = nc+d[2*i+1];
				if (b.count({dr,dc}) > 0) {
					waterLevel = min(waterLevel, h[dr][dc]);
					eLake.insert({nr,nc});
				}
			}
			for (int i = 0; i < 4; i++) {
				int dr = nr+d[2*i], dc = nc+d[2*i+1];
				if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
				if (vLake[dr][dc] == 0 && b.count({dr,dc}) == 0) {
					vLake[dr][dc] = 1;
					q.push({dr,dc});
				}
			}
		}

		// now process this lake, which has edges of eLake and waterLevel
		queue<pt> q2;
		for (auto y : eLake) {
			auto [nr,nc] = y;
			v[nr][nc] = 1;
			q2.push({nr,nc});
		}
		// find the island boundaries inside this lake and calculate the water up to those boundaries
		while (q2.size() > 0) {
			auto [nr,nc] = q2.front();
			q2.pop();
			volume += max(waterLevel-h[nr][nc], 0);
			for (int i = 0; i < 4; i++) {
				int dr = nr+d[2*i], dc = nc+d[2*i+1];
				if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
				if (v[dr][dc] == 0) {
					v[dr][dc] = 1;
					if (h[dr][dc] >= waterLevel) {
						bi.insert({dr,dc});						
					}
					else {
						q2.push({dr,dc});
					}
				}
			}
		}
	}
}

// Algorithm:
// set b = { all edge points }  // the boundary
// while (some unvisited points are left) do
//     for each unvisited point x in b, add all points reachable from x by equal or higher step to b (including x) , while marking them as visited
//	   assert: b and unvisited will now be disjoint
//     assert: every unvisited point adjacent to b must be either water (part of a lake) or lead to water (because it is lower)
//     for each such point (in decreasing order of height), find all points reachable by equal or lower steps. this will be a lake.
//	   for each lake, find its lowest border point
//	   fill each lake to the height of its lowest border point, marking it as visited. Then add any unvisited adjacent non-border point (islands) to the next border set
//     assert: all islands from each lake have border points, which become the new border, to explore inwards


int vol() {
	unordered_set<pt,ph> b;
	memset(v, 0, sizeof(v));
	memset(vLake, 0, sizeof(vLake));

	// get initial boundary
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (r == 0 || r == n-1 || c == 0 || c == m-1) {
				b.insert({r,c});
				v[r][c] = 1;
			}
		}
	}
	int volume = 0;
	while (b.size() > 0) {
		unordered_set<pt,ph> bc = b; // current boundary
		for (auto x : bc) {
			bfsBoundary(x, b); // go sideways or up, adding to b and updating v
		}

		// assert: b and unvisited are disjoint now
		// assert: every unvisited point adjacent to b must be strictly lower: either water (part of a lake) or lead to water

		unordered_set<pt,ph> bi; 
		processLakes(b, bi, volume);

		// assert: all new outermost boundary points are marked. these are islands that rise out of the water, which may themselves have lakes
		b = bi;
	}
	return volume;
}

int main() {

	int t;
	scanf("%d", &t);

	while (t-- > 0) {
		memset(h, 0, sizeof(h));
		scanf("%d%d", &n, &m);
		for (int r = 0; r < n; r++) {
			for (int c = 0; c < m; c++) {
				scanf("%d", &h[r][c]);
			}
		}
		printf("%d\n", vol());
	}
	return 0;
}
