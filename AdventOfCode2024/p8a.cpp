#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;
#define SQR(x) ((x)*(x))

bool antinode(vector<string> &grid, int ar, int ac) {
  int h = grid.size(), w = grid[0].size();
  vector<int> dist;
  for (int r1 = 0; r1 < h; r1++) {
    for (int c1 = 0; c1 < w; c1++) {
      if ((r1 == ar && c1 == ac) || grid[r1][c1] == '.') continue;
      for (int r2 = 0; r2 < h; r2++) {
        for (int c2 = 0; c2 < w; c2++) {
          if ((r2 == ar && c2 == ac) || grid[r2][c2] != grid[r1][c1]) continue;
          // check if (ar,ac), (r1,c1), (r2,c2) are collinear
          if ((ar-r1)*(ac-c2) != (ar-r2)*(ac-c1)) continue;
          // check if dist(a,p1) is twice of dist(a,p2)
          int d1s = SQR(ar-r1)+SQR(ac-c1);
          int d2s = SQR(ar-r2)+SQR(ac-c2);
          if (d1s == 4*d2s || d2s == 4*d1s) return true;
        }
      }
    }
  }
  return false;
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
      if (antinode(grid, r, c)) {
        res++;
      }
    }
  }
  cout << res << endl;
}

