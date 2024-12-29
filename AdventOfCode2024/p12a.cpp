#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

vector<string> origGrid;

void flood(vector<string> &grid, int sr, int sc, int h, int w, char ch, int& area, int &perimeter, set<pii> &lines) {
  int dir[] = {-1,0, 0,1, 1,0, 0,-1};
  queue<pii> q;
  q.push({sr,sc});
  grid[sr][sc] = '.';
  while (!q.empty()) {
    pii head = q.front();
    q.pop();
    area++;
    auto [r,c] = head;
    for (int d = 0; d < 4; d++) {
      int dr = r+dir[2*d], dc = c+dir[2*d+1];
      if (dr < 0 || dr >= h || dc < 0 || dc >= w) {
        if (d == 0 || d == 2) {
          lines.insert({dr, d});
        }
        else {
          lines.insert({dc, d});
        }
        perimeter++;
        continue;
      }
      if (origGrid[dr][dc] != ch) {
        if (d == 0 || d == 2) {
          lines.insert({dr, d});
        }
        else {
          lines.insert({dc, d});
        }
        perimeter++;
      }
      if (grid[dr][dc] == ch) {
        q.push({dr,dc});
        grid[dr][dc] = '.';
      }
    }
  }
  return;
}

int main(int argc, char *argv[])
{
  vector<string> grid;
  string line;
  while (getline(cin, line)) {
    grid.push_back(line);
  }
  origGrid = grid;

  LL res = 0;
  int h = grid.size(), w = grid[0].size();
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] != '.') {
        int area = 0, perimeter = 0;
        char ch = grid[r][c];
        set<pii> lines;
        flood(grid, r, c, h, w, ch, area, perimeter, lines);
        int sides = lines.size();
        cout << r << " " << c << " " << ch << " : area = " << area << " sides = " << sides << endl;
        res += (LL)area*sides; 
      }
    }
  }
  cout << res << endl;
}

