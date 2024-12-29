#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	
	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

// handle blasted c++ on cygwin returning a \r on the end of line!!!
void getInput(vector<string> &v) {
  string line;
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}

typedef pair<int,int> pii;

main() {
  vector<string> v;
  getInput(v);
  int n = v.size(), m = v[0].size(), sr, sc;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == 'S') {
        sr = i;
        sc = j;
      }
    }
  }
  v[sr][sc] = '-';
  string row(m, '.');
  vector<string> canvas(n, row);
  canvas[sr][sc] = '-';
  map<pii,int> dist;
  dist[{sr,sc}] = 0;
  queue<pii> q;
  set<pii> path;
  q.push({sr,sc});
  path.insert({sr,sc});
  while (q.size() > 0) {
    pii head = q.front();
    q.pop();
    auto [r,c] = head;
    vector<pii> nbrs;
    if (v[r][c] == '|') {
      nbrs.push_back({r-1,c});
      nbrs.push_back({r+1,c});
    }
    else if (v[r][c] == '-') {
      nbrs.push_back({r,c+1});
      nbrs.push_back({r,c-1});
    }
    else if (v[r][c] == 'L') {
      nbrs.push_back({r-1,c});
      nbrs.push_back({r,c+1});
    }
    else if (v[r][c] == 'J') {
      nbrs.push_back({r-1,c});
      nbrs.push_back({r,c-1});
    }
    else if (v[r][c] == '7') {
      nbrs.push_back({r+1,c});
      nbrs.push_back({r,c-1});
    }
    else {
      nbrs.push_back({r+1,c});
      nbrs.push_back({r,c+1});
    }
    for (auto nbr : nbrs) {
      auto [dr, dc] = nbr;
      if (dr < 0 || dr >= n || dc < 0 || dc >= m || v[dr][dc] == '.' || dist.count(nbr) > 0) {
          continue;
      }
      dist[nbr] = dist[head] + 1;
      canvas[dr][dc] = v[dr][dc];
      q.push(nbr);
      path.insert(nbr);
    }
  }
  for (int r = 0; r < n; r++) {
    for (int c = 0; c < m; c++) {
      if (path.find({r,c}) == path.end()) {
        canvas[r][c] = '.';
      }
    }
  }
  canvas[sr][sc] = 'S';
  for (auto line : canvas) {
    cout << line << endl;
  }
  int inside = 0;
  // first try CW, then CCW
}
