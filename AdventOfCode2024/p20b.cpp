#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

LL best = LLONG_MAX;

typedef pair<int,int> pii;

int main(int argc, char *argv[])
{
  string line;
  vector<string> grid;
  int Sr, Sc = -1, Er, Ec = -1;
  int h = 0, w;
  while (getline(cin, line)) {
    grid.push_back(line);
    w = line.size();
    if (Sc == -1 && (Sc = line.find('S')) != -1) {
      Sr = h;
    }
    if (Ec == -1 && (Ec = line.find('E')) != -1) {
      Er = h;
    }
    h++;
  }
  cout << h << " " << w << " " << Sr << " " << Sc << " " << Er << " " << Ec <<endl;
  int dir[] = {-1,0, 0,1, 1,0, 0,-1};
  int rr = Sr, rc = Sc;
  int A[h][w];
  memset(A, -1, sizeof(A));
  
  vector<pii> path;
  int dist = 0;
  A[rr][rc] = dist;
  path.push_back({rr,rc});
  do {
    for (int i = 0; i < 4; i++) {
      int nr = rr+dir[2*i], nc = rc+dir[2*i+1];
      if (grid[nr][nc] != '#' && A[nr][nc] == -1) {
        rr = nr;
        rc = nc;
        break;
      }
    }
    path.push_back({rr,rc});
    A[rr][rc] = ++dist;
    // cout << rr << " " << rc << " " << A[rr][rc] << endl;
  } while (rr != Er || rc != Ec);
  

  // second pass
  LL num = 0;
  int n = path.size();
  cout << "path len is " << n << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      auto [rr,rc] = path[i];
      auto [nr2,nc2] = path[j];
      int steps = abs(nr2-rr)+abs(nc2-rc);
      int saved = (A[nr2][nc2]-A[rr][rc])-steps;
      if (steps <= 20 && saved >= 100) {
        num++;
        // cout << "Cheat saving " << saved << " " << " from " << rr << " " << rc << " to " << nr2 << " " << nc2 << " # " << num << endl;
      }
    }
  }
  cout << num << endl;
}

