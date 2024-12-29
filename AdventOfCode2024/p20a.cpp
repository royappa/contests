#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

LL best = LLONG_MAX;



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
  
  int dist = 0;
  A[rr][rc] = dist;
  do {
    for (int i = 0; i < 4; i++) {
      int nr = rr+dir[2*i], nc = rc+dir[2*i+1];
      if (grid[nr][nc] != '#' && A[nr][nc] == -1) {
        rr = nr;
        rc = nc;
        break;
      }
    }
    A[rr][rc] = ++dist;
    cout << rr << " " << rc << " " << A[rr][rc] << endl;
  } while (rr != Er || rc != Ec);
  
  /*
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (A[r][c] < 100)
       printf("%3d", A[r][c]);
      else
       printf("   ");
    }
    cout << endl;
  }
  */

  // second pass
  rr = Sr;
  rc = Sc;
  int num = 0;
  do {
    for (int i = 0; i < 4; i++) {
      int nr = rr+dir[2*i], nc = rc+dir[2*i+1];
      if (grid[nr][nc] == '#') {
        int nr2 = rr+2*dir[2*i], nc2 = rc+2*dir[2*i+1];
        if (nr2 >= 0 && nr2 < h && nc2 >= 0 && nc2 < w && A[nr2][nc2] > A[rr][rc]) {
          int saved = (A[nr2][nc2]-A[rr][rc])-2;
          if (saved >= 100) {
            num++;
          }
          cout << "Cheat saving " << saved << " " << " from " << rr << " " << rc << " to " << nr2 << " " << nc2 << " # " << num << endl;
        }
      }
    }
    for (int i = 0; i < 4; i++) {
      int nr = rr+dir[2*i], nc = rc+dir[2*i+1];
      if (grid[nr][nc] != '#' && A[nr][nc] > A[rr][rc]) {
        rr = nr;
        rc = nc;
        break;
      }
    }
  } while (rr != Er || rc != Ec);  

  cout << num << endl;
}

