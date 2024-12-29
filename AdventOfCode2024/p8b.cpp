#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

#define GOOD(r,c,h,w)  ((r) >= 0 && (r) < (h) && (c) >= 0 && (c) < (w))

int antinodes(vector<string> &grid) {
  int h = grid.size(), w = grid[0].size();
  int res = 0;
  set<pair<int,int>> s;
  for (int r1 = 0; r1 < h; r1++) {
    for (int c1 = 0; c1 < w; c1++) {
      if (grid[r1][c1] == '.') continue;
      for (int r2 = 0; r2 < h; r2++) {
        for (int c2 = 0; c2 < w; c2++) {
          if ((r1 == r2 && c1 == c2) || grid[r2][c2] != grid[r1][c1]) continue;
          int dr = r2 - r1, dc = c2 - c1;
          int rt = r1, ct = c1;
          while (GOOD(rt,ct,h,w)) {
            s.insert({rt,ct});
            rt -= dr;
            ct -= dc;
          }
          rt = r1, ct = c1;
          while (GOOD(rt,ct,h,w)) {
            s.insert({rt,ct});
            rt += dr;
            ct += dc;
          }          
        }
      }
    }
  }
  return s.size();
}

int main()
{
  string line;
  vector<string> grid;

  while (getline(cin, line)) {
      grid.push_back(line);
  }
  int res = antinodes(grid);
  cout << res << endl;
}

