#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;

void dump(vector<string> &grid, int h, int w) {
  cout << "\033[H";
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      cout << grid[r][c];
    }
    cout << endl;
  }
  cout.flush();
  this_thread::sleep_for(chrono::milliseconds(100));
}
int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  int cur = 0;
  vector<string> grids[2];
  while (getline(cin, line)) {
    grids[cur].push_back(line);
    grids[1-cur].push_back(string(line.size(), '.'));
  }
  int h = grids[cur].size(), w = grids[cur][0].size();
  if (debug) system("clear");
  int numOn;
  for (int step = 1; step <= 100; step++) {
    numOn = 0;
    int opp = 1-cur;
    for (int r = 0; r < h; r++) {
      for (int c = 0; c < w; c++) {
        int num = 0;
        for (int dr = r-1; dr <= r+1; dr++) {
          for (int dc = c-1; dc <= c+1; dc++) {
            if (dr == r && dc == c) continue;
            if (dr < 0 || dr >= h || dc < 0 || dc >= w) continue;
            num += grids[cur][dr][dc] == '#';
          }
        }
        if (grids[cur][r][c] == '#') {
          grids[opp][r][c] = (num == 2 || num == 3) ? '#' : '.';
        }
        else {
          grids[opp][r][c] = num == 3 ? '#' : '.';
        }
        numOn += grids[opp][r][c] == '#';
      }
    }
    if (debug) dump(grids[opp], h, w);
    cur = opp;
  }
  cout << numOn << endl;
}
