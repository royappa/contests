#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;

void getnums(string s, int &a, int &b, int &c, int &d) {
  regex r(R"((-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+))");
  smatch m;
  regex_search(s, m, r);
  a = stoi(m[1]);
  b = stoi(m[2]);
  c = stoi(m[3]);
  d = stoi(m[4]);
}

bool solid(vector<string> &grid, int w, int h) {
  int num = 0;
  for (int r = 0; r < h; r++) {
    if (grid[r].find("*****") != -1) {
      num++;
    }
  }
  return num > 5;
}
int solve(vector<pii> &p, vector<pii> &v, int w, int h) {
  vector<string> oldGrid;
  for (int i = 0; i < h; i++) {
    oldGrid.push_back(string(w, '.'));
  }
  int sec = 1;
  do {
    vector<string> grid = oldGrid;
    for (int i = 0; i < v.size(); i++) {
      auto [px,py] = p[i];
      auto [vx,vy] = v[i];
      px += vx; if (px < 0) px += w; else if (px >= w) px -= w;
      py += vy; if (py < 0) py += h; else if (py >= h) py -= h;
      grid[py][px] = '*';
      p[i] = {px,py};
    }
    if (solid(grid, w, h)) {
      for (auto x : grid) cout << x << endl;
      return sec;
    }
    sec++;
  }
  while (1);
}

int main(int argc, char *argv[])
{

  string line;
  LL res = 0;
  int w = atoi(argv[1]), h = atoi(argv[2]);
  vector<pii> p, v;
  while (getline(cin, line)) {
    int px, py, vx, vy;
    getnums(line, px, py, vx, vy);
    // cout << px << " " << py << " " << vx << " " << vy << endl;
    p.push_back({px,py});
    v.push_back({vx,vy});
  }
  cout << solve(p, v, w, h) << endl;
  // cout << "Result: " << solve(p, v, w, h)  << endl;
}

