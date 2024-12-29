#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tiii;

vector<string> origGrid;

void flood(vector<string> &grid, int sr, int sc, int h, int w, char ch, int& area, int &perimeter, set<tiii> &lines) {
  int dir[] = {-1,0, 0,1, 1,0, 0,-1}; // U,R,D,L
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
        lines.insert({r, c, d});
        perimeter++;
        continue;
      }
      if (origGrid[dr][dc] != ch) {
        lines.insert({r, c, d});
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

int countSegs(set<int> v) {
  int cur = -100;
  int num = 0;
  // for (auto x : v) { cout << x << " "; } cout << endl;
  for (auto x : v) {
    if (x != cur+1) {
      num++;
    }
    cur = x;
  }
  // cout << "count = " << num << endl;
  return num;
}

int calcSides(set<tiii> lines, int h, int w) {
  int sides = 0;
  set<int> v;
  // U,R,D,L
  for (int r = 0; r < h; r++) {
    v.clear();
    for (int c = 0; c < w; c++) {
      if (lines.count({r,c,0}) > 0) v.insert(c);
    }
    sides += countSegs(v);
    v.clear();
    for (int c = 0; c < w; c++) {
      if (lines.count({r,c,2}) > 0) v.insert(c);
    }
    sides += countSegs(v);
  }
  for (int c = 0; c < w; c++) {
    v.clear();
    for (int r = 0; r < h; r++) {
      if (lines.count({r,c,1}) > 0) v.insert(r);
    }
    sides += countSegs(v);
    v.clear();
    for (int r = 0; r < h; r++) {
      if (lines.count({r,c,3}) > 0) v.insert(r);
    }
    sides += countSegs(v);
  }
  return sides;
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
        set<tiii> lines;
        flood(grid, r, c, h, w, ch, area, perimeter, lines);
        int sides = calcSides(lines, h, w);
        // cout << r << " " << c << " " << ch << " : area = " << area << " sides = " << sides << endl;
        for (auto z : lines) {
          auto [a,b,c] = z;
          // cout << a << " " << b << " " << (c == 0 ? "U" : c == 1 ? "R" : c == 2 ? "D" : "L") << endl;
        }
        res += (LL)area*sides; 
      }
    }
  }
  cout << res << endl;
}

