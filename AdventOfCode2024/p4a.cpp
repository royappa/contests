#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;


int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);

  string line;
  vector<string> grid;
  while (getline(infile, line)) {
      grid.push_back(line);
  }
  int h = grid.size(), w = grid[0].size();
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      int d[] = {-1,-1,-1,0,-1,1, 0,-1,0,1, 1,-1,1,0,1,1};
      for (int i = 0; i < 8; i++) {
        int dr = d[2*i], dc = d[2*i+1];
        string look = "XMAS";
        int j = 0, pr = r, pc = c;
        for (; j < 4 && (pr >= 0 && pr < h && pc >= 0 && pc < w); j++) {
          if (grid[pr][pc] != look[j]) break;
          pr += dr;
          pc += dc;
        }
        if (j == 4) res++;
      }
    }
  }
  cout << res << endl;
}

