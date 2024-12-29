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
        if (r == 0 || r == h-1 || c == 0 || c == w-1) continue;
        string a = string("")+grid[r-1][c-1]+grid[r][c]+grid[r+1][c+1];
        string b = string("")+grid[r-1][c+1]+grid[r][c]+grid[r+1][c-1];
        if ((a == "MAS" && b == "MAS") || (a == "MAS" && b == "SAM") ||
            (a == "SAM" && b == "MAS") || (a == "SAM" && b == "SAM"))
            res++;
    }
  }
  cout << res << endl;
}

