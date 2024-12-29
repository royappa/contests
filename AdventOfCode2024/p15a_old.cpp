#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;
#define GOOD(ar,ac,hh,ww) ((ar) >= 0 && (ar) < (hh) && (ac) >= 0 && (ac) < (ww))

void dump(vector<string> &grid) { for (auto x : grid) cout << x << endl;}
void sim(vector<string> &grid, string ops, int h, int w, int rr, int rc) {
  int dirs[] = {-1,0, 0,1, 1,0, 0,-1};
  cout << ops << endl;
  string s = "^>v<";
  for (int i = 0; i < ops.size(); i++) {
    char ch = ops[i];
    int d = s.find(ch);
    int dr = dirs[2*d], dc = dirs[2*d+1];
    cout << "After " << ch << " " << d << " : " << dr << " " << dc << endl;
    int nr = rr+dr, nc = rc+dc;
    int oc = 0, bc = 0;
    int steps = 1;
    if (grid[nr][nc] == '#') {
      ;
    }
    else if (grid[nr][nc] == '.') {
      grid[nr][nc] = '@';
      grid[rr][rc] = '.';
      rr = nr;
      rc = nc;
    }
    else {
        while (grid[nr][nc] == 'O') {
          nr += dr;
          nc += dc;
        }
        if (grid[nr][nc] == '.') {
          grid[rr][rc] = '.';
          rr += dr;
          rc += dc;
          grid[rr][dr] = '@';
          grid[nr][nc] = 'O';
        }
      }
    }
    dump(grid);
  }
}

int main(int argc, char *argv[])
{

  vector<string> grid;
  string line;
  int h = 0, w = 0;
  int rr, rc;
  while (getline(cin, line) && line != "") {
    w = line.size();
    if (line.find("@") != -1) {
      rr = h;
      rc = line.find("@");
    }
    h++;
    grid.push_back(line);
  }
  cout << h << " " << w << " : " << rr << " " << rc << endl;
  string ops = "";
  while (getline(cin, line)) {
    ops += line;
  }
  sim(grid, ops, h, w, rr, rc);
  cout << "final:" << endl;
  for (auto x : grid) {
    cout << x << endl;
  }
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] == 'O') {
        res += 100*r+c;
      }
    }
  }
  cout << res << endl;
}

