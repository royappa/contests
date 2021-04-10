#include <bits/stdc++.h>
#include<unistd.h> 
#include<stdio.h> 
#include<fcntl.h>

using namespace std;
int debug=1;

int n, m;
int h[101][101];
int d[] = {-1,0, 0,1, 1,0, 0,-1};

struct pair_hash
{
	template <class T1, class T2>
	std::size_t operator () (std::pair<T1, T2> const &pair) const
	{
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

void dump(int n, int m)
{

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < m; c++)
		{
			printf("%4d", h[r][c]);
		}
		printf("\n");
	}
	return;
}

typedef pair<int,int> pt;

void fillLake(pair<int,unordered_set<pt,pair_hash>> &lake, unordered_set<pt,pair_hash> &b, unordered_set<pt,pair_hash> &bi, unordered_set<pt,pair_hash> &u, int &volume) {
	auto [level, lakePoints] = lake;
	for (auto x : lakePoints) {
		auto [r,c] = x;
		volume += max(level-h[r][c], 0);
		u.erase(x);
	}
	for (auto x : lakePoints) {
		auto [r,c] = x;
		for (int i = 0; i < 4; i++) {
			int dr = d[2*i], dc = d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			pt nx = {dr,dc};
			if (u.count(nx) > 0 && b.count(nx) == 0) {
				bi.insert(nx);
			}
		}
	}
	return;
}

int borderHeight(pt p, unordered_set<pt,pair_hash> b) {
	int low = 1e7;
	auto [r,c] = p;
	for (int i = 0; i < 4; i++) {
		int dr = r + d[2*i], dc = c + d[2*i+1];
		if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
		pt x = {dr,dc};
		if (b.count(x) > 0) {
			low = min(low, h[dr][dc]);
		}
	}
	return low;
}
void bfsFindLakes(pt start, vector<pair<int,unordered_set<pt,pair_hash>>> &lakes, unordered_set<pt,pair_hash> &allLakePoints, unordered_set<pt,pair_hash> &b, unordered_set<pt,pair_hash> &u) {
	// add point to new lake
	unordered_set<pt,pair_hash> lake;
	lake.insert(start);
	int lowBorder = borderHeight(start, b);

	queue<pt> q;
	unordered_set<pt,pair_hash> v;
	q.push(start);
	allLakePoints.insert(start);
	while (q.size() > 0) {
		auto [r,c] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dr = r + d[2*i], dc = c + d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			pt x = {dr,dc};
			if (h[dr][dc] <= h[r][c]) {
				if (b.count(x) == 0 && allLakePoints.count(x) == 0) {
					lake.insert(x);
					allLakePoints.insert(x);
					lowBorder = min(lowBorder, borderHeight(x, b));
				}
			}
		}
	}
	lakes.push_back({lowBorder,lake});
}

bool adjToSet(pt x, unordered_set<pt,pair_hash> b) {
	auto [r,c] = x;
	for (int i = 0; i < 4; i++) {
		int dr = r+d[2*i], dc = c+d[2*i+1];
		if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
		if (b.count({dr,dc}) > 0) {
			return true;
		}
	}
	return false;
}

void bfsBoundary(pt start, unordered_set<pt,pair_hash> &b, unordered_set<pt,pair_hash> &u) {
	queue<pt> q;
	q.push(start);
	u.erase(start);
	while (q.size() > 0) {
		auto [r,c] = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dr = r+d[2*i], dc = c+d[2*i+1];
			if (dr < 0 || dr >= n || dc < 0 || dc >= m) continue;
			pt x = {dr,dc};
			if (h[dr][dc] >= h[r][c] && u.count(x) > 0 && b.count(x) == 0) {
				u.erase(x);
				b.insert(x);
			}
		}
	}
	return;
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
	unordered_set<pt,pair_hash> b, u;
	// get initial boundary
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < m; c++) {
			if (r == 0 || r == n-1 || c == 0 || c == m-1) {
				b.insert({r,c});
			}
			else {
				u.insert({r,c});
			}
		}
	}
	int volume = 0;
	while (u.size() > 0) {
		unordered_set<pt,pair_hash> bc = b; // current boundary
		for (auto x : bc) {
			bfsBoundary(x, b, u); // go sideways or up, adding to b and updating u
		}
		// assert: b and u are disjoint now
		// assert: every unvisited point adjacent to b must be strictly lower: either water (part of a lake) or lead to water
		// for each such point (considered in decreasing height), find all non-boundary points reachable by equal or lower steps. this will be a lake (with islands)
		// for each lake, find its lowest border point
		set<pair<int,pt>> lakeStarts;
		for (auto x : u) {
			if (adjToSet(x, b)) {
				lakeStarts.insert({-h[x.first][x.second], x});
			}
		}
		vector<pair<int,unordered_set<pt,pair_hash>>> lakes;
		unordered_set<pt,pair_hash> allLakePoints;
		for (auto xh : lakeStarts) {
			if (allLakePoints.count(xh.second) == 0) { // skip starting points of previously found lakes
				bfsFindLakes(xh.second, lakes, allLakePoints, b, u);
			}
		}
		// fill each lake to the height of its lowest border point, marking it as visited, while adding any unvisited adjacent point (islands) to the border (without marking as visited)
		unordered_set<pt,pair_hash> bi; // new island boundaries to be found
		for (auto lake : lakes) {
			fillLake(lake, b, bi, u, volume);
		}
		// assert: all new outermost boundary points are marked. these are islands that rise out of the water, which may themselves have lakes
		// mark the new boundary as visited
		b = bi;
		for (auto x : b) {
			u.erase(x);
		}
	}
	return volume;
}

int main() {
	/*
	int d = open("water.dat", O_RDONLY);
	dup2(d, 0);
	*/
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
