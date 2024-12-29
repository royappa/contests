#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;



int main()
{
  string line;
  vector<string> grid;
  
  while (getline(cin, line)) {
    grid.push_back(line);
  }
  int h = grid.size(), w = grid[0].size();
  int A[61][61][2];
  memset(A, 0, sizeof(A));
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if(grid[r][c] == '9') {
        A[r][c][0] = 1;
      }
    }
  }
  int p = 0;
  for (char i = '8'; i >= '0'; i--) {
    int q = 1-p;
    for (int r = 0; r < h; r++) {
      for (int c = 0; c < w; c++) {
        if (grid[r][c] == i) {
          int dirs[] = {-1,0, 0,1, 1,0, 0,-1};
          for (int d = 0; d < 4; d++) {
            int nr = r+dirs[2*d], nc = c+dirs[2*d+1];
            if (nr < 0 || nr >= h || nc < 0 || nc >= w || grid[nr][nc] != i+1) continue;
            A[r][c][q] += A[nr][nc][p];
          }
        }
      }
    }
    p = q;
  }
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] == '0') {
        res += A[r][c][p];
      }
    }
  }
  cout << res << endl;
}

