#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

bool checkLoop(vector<string> grid, int pr, int pc) {
  int h = grid.size(), w = grid[0].size();
  int d[] = {-1,0, 0,1, 1,0, 0,-1};
  string dirs = "^>v<";
  int dir = 0;
  do {
    int npr = pr + d[2*dir], npc = pc + d[2*dir+1];
    if (npr < 0 || npr == h || npc < 0 || npc == w) {
      return false; 
    }
    if (grid[npr][npc] == dirs[dir]) {
      return true;
    }
    if (grid[npr][npc] == '#') {
      dir = (dir + 1) % 4;
    }
    else {
      pr = npr;
      pc = npc;
      grid[pr][pc] = dirs[dir];
    }
  } while (true);
}

int main()
{
  string line;
  vector<string> grid;
  while (getline(cin, line)) {
      grid.push_back(line);
  }

  int h = grid.size(), w = grid[0].size();
  int pr, pc;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] == '^') {
        pr = r;
        pc = c;
      }
    }
  }
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      char ch = grid[r][c];
      if (ch == '.') {
        grid[r][c] = '#';
        if (checkLoop(grid, pr, pc)) {
          res++;
        }
        grid[r][c] = ch;
      }
    }
  }
  cout << res << endl;
}

