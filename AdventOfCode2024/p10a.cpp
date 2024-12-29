#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

int visited[61][61];
int hike(vector<string> &grid, int r, int c, int h, int w) {
  if (grid[r][c] == '9') {
    visited[r][c] = 1;
    return 1;
  }
  visited[r][c] = 1;
  int dirs[] = {-1,0, 0,1, 1,0, 0,-1};
  int tot = 0;
  for (int d = 0; d < 4; d++) {
    int dr = dirs[2*d], dc = dirs[2*d+1];
    int nr = r+dr, nc = c+dc;
    if (nr < 0 || nr >= h || nc < 0 || nc >= w || visited[nr][nc]) continue;
    if (grid[nr][nc] != grid[r][c]+1) continue;
    tot += hike(grid, nr, nc, h, w);
  }
  return tot;
}

int main()
{
  string line;
  vector<string> grid;
  
  while (getline(cin, line)) {
    grid.push_back(line);
  }
  int h = grid.size(), w = grid[0].size();
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] == '0') {
        memset(visited, 0, sizeof(visited));
        res += hike(grid, r, c, h, w);
      }
    }
  }
  cout << res << endl;
}

