#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int check(vector<string> &v, int r, int c) {
  string symbols = "+%*$#/=@-&";
  int n = v.size(), m = v[0].size();
  int d[] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
  for (int i = 0; i < 8; i++) {
    int rr = r+d[2*i];
    int cc = c+d[2*i+1];
    if (rr < n && cc < m && rr >= 0 && cc >= 0 && !isdigit(v[rr][cc]) && v[rr][cc] != '.') {
      return true;
    }
  }
  return false;
}

bool adjacent(vector<int> &part, vector<int> &g) {
  int pi = part[1], pj = part[2], plen = part[3];
  int gi = g[0], gj = g[1];
  for (int j = pj; j < pj+plen; j++) {
    if (max(abs(pi-gi), abs(j-gj)) <= 1) {
      return true;
    }
  }
  return false;
}
main() {
  string line;
  LL sum = 0;
  vector<string> v;
  // goddamn c++ returns a \r on the end of line!!!
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  int n = v.size(), m = v[0].size();
  vector<vector<int>> parts;
  vector<vector<int>> gears;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j] == '*') {
        gears.push_back({i, j});
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isdigit(v[i][j])) {
        int val = 0, jj = j;
        bool ok = false;
        while (j < m && isdigit(v[i][j])) {
          val = val*10+(v[i][j]-'0');
          ok = ok || check(v, i, j);
          j++;
        }
        if (ok) {
          parts.push_back({val, i, jj, j-jj});
        } 
      }
    }
  }
  for (auto g : gears) {
    vector<vector<int>> adj;
    for (auto part : parts) {
      if (adjacent(part, g)) {
        adj.push_back(part);
      }
    }
    if (adj.size() == 2) {
      printf("%d (%d,%d) * %d (%d, %d)\n", adj[0][0], adj[0][1], adj[0][2], adj[1][0], adj[1][1], adj[1][2]);
      sum += adj[0][0] * adj[1][0];
    }
  }
  printf("%lld\n", sum);
  exit(0);
}
