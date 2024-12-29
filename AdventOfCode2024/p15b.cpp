#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;
typedef tuple<int,int,int,int> tuple4;

#define GOOD(ar,ac,hh,ww) ((ar) >= 0 && (ar) < (hh) && (ac) >= 0 && (ac) < (ww))

void tupout(tuple4 t) {
  auto [a,b,c,d] = t;
  printf("(%d,%d) (%d,%d)", a, b, c, d);
}

vector<string> last;

bool fail(vector<string> &grid) {
  for (auto x : grid) {
    if (x.find("[.") != -1 || x.find("[@") != -1 || x.find("@]") != -1) return true;
  }
  return false;
}
void dump(vector<string> &grid) { for (auto x : grid) cout << x << endl;}

void sim(vector<string> &grid, string ops, int h, int w, int rr, int rc) {
  int dirs[] = {-1,0, 0,1, 1,0, 0,-1};
  // cout << ops << endl;
  string s = "^>v<";
  for (int i = 0; i < ops.size(); i++) {
    char ch = ops[i];
    int d = s.find(ch);
    int dr = dirs[2*d], dc = dirs[2*d+1];  
    // cout << "After: " << ch << " " << d << " : " << dr << " " << dc << endl;
    if (ch == '<' || ch == '>') {
      int nr = rr+dr, nc = rc+dc;
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
        int k = 0;
        while (grid[nr][nc] == '[' || grid[nr][nc] == ']') {
          nr += dr;
          nc += dc;
          k++;
        }
        if (grid[nr][nc] == '.') {
          while (!(nr == rr & nc == rc)) {
            int pr = nr-dr, pc = nc-dc;
            swap(grid[nr][nc], grid[pr][pc]);
            nr = pr;
            nc = pc;
          }
          rr += dr;
          rc += dc;
        }
      }
    }
    else {  // v or ^
      int nr = rr+dr, nc = rc+dc;
      if (grid[nr][nc] == '#') {
        ;
      }
      else if (grid[nr][nc] == '.') {
        grid[nr][nc] = '@';
        grid[rr][rc] = '.';
        rr = nr;
        rc = nc;
      }
      else { // '[]'
        char x = grid[nr][nc];
        int xr = nr, xc = nc;
        if (x == '[') xc++; else xc--;
        // (nr,nc) and (xr,xc) are the two parts of the root box
        vector<set<tuple4>> rows;
        set<tuple4> firstRow;
        firstRow.insert({nr,min(xc,nc),xr,max(nc,xc)});
        rows.push_back(firstRow);
        bool mustStop = false, nextRowEmpty = true; // stop when reach obstacle or when nextrow is empty
        do {
          // check if the next row is the last row
          // it is the last row if either everything can move, or something can't move due to '#'
          /*
          cout << "@ is at " << rr << " " << rc << endl;
          cout << "rows: " << rows.size() << endl;
          for (auto v : rows) {
            for (auto t : v) {
              tupout(t); cout << " ";
            }
            cout << endl;
          }
          cout << "endrows" << endl;
          */
          set<tuple4> cur = rows.back();
          set<tuple4> next;
          nextRowEmpty = true;
          for (auto t : cur) {
            auto [br1,bc1,br2,bc2] = t; // one of the boxes on current row
            if (bc1 > bc2) swap(bc1, bc2);
            string box = grid[br1+dr].substr(bc1, 2);
            // tupout({br1+dr,bc1,br2+dr,bc2}); cout << "|" << box << "|" << endl;
            if (box[0] == '#' || box[1] == '#') {
              mustStop = true;
            }
            else if (box != "..") {
              nextRowEmpty = false;
              int sign = d == 0 ? 1 : -1;
              if (box == "[]") {
                next.insert({br1+dr,bc1,br2+dr,bc2});
              }
              else if (box == ".[" && d == 0) {
                next.insert({br1+dr,bc2,br2+dr,bc2+1});
              }
              else if (box == ".[" && d == 2) {
                next.insert({br1+dr,bc2,br2+dr,bc2+1});
              }
              else if (box == "]." && d == 0) {
                next.insert({br1+dr,bc1-1,br2+dr,bc1});
              }
              else if (box == "]." && d == 2) {
                next.insert({br1+dr,bc1-1,br2+dr,bc1});
              }              
              else if (box == "][" && d == 0) {
                next.insert({br1+dr,bc2,br2+dr,bc2+1});
                next.insert({br1+dr,bc1-1,br2+dr,bc1});
              }
              else if (box == "][" && d == 2) {
                next.insert({br1+dr,bc2,br2+dr,bc2+1});
                next.insert({br1+dr,bc1-1,br2+dr,bc1});
              }              
            }
          }
          // cout << "done with row" << endl;
          // cout << mustStop << " / " << nextRowEmpty << " " << rows.size() << endl;
          if (!nextRowEmpty) {
            // cout << "pushing row of size " << next.size() << endl;
            rows.push_back(next);
          }
        } while (!mustStop && !nextRowEmpty);
        if (!mustStop) { // next row is empty
          // move all rows
          for (auto it = rows.rbegin(); it != rows.rend(); it++) {
            auto row = *it;
            for (auto box : row) {
              auto [br1,bc1,br2,bc2] = box; 
              // tupout({br1,bc1,br2,bc2}); cout << endl;
              // tupout({br1+dr,bc1,br2+dr,bc2}); cout << endl;
              // cout << "swap " << grid[br1].substr(bc1, 2) << " " << grid[br1+dr].substr(bc1, 2) << endl;
              swap(grid[br1][bc1], grid[br1+dr][bc1]);
              swap(grid[br2][bc2], grid[br2+dr][bc2]);
            }
          }
          grid[nr][nc] = '@';
          grid[rr][rc] = '.';
          rr = nr;
          rc = nc;
        }
      }
    }
    if (fail(grid)) {
      cout << "Old" << endl;
      dump(last);
      cout << "Fail (" << ch << ")" << endl;
      dump(grid);
      exit(1);
    } else {
      last = grid;
    }
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
    string scaled = "";
    for (int c = 0; c < w; c++) {
      if (line[c] == '@') {
        scaled += "@.";
        rr = h;
        rc = 2*c;
      }
      else if (line[c] != 'O') {
        scaled += line[c];
        scaled += line[c];
      }
      else {
        scaled += "[]";
      }
    }
    h++;
    grid.push_back(scaled);
  }
  cout << h << " " << w << " : " << rr << " " << rc << endl;
  string ops = "";
  while (getline(cin, line)) {
    ops += line;
  }
  cout << "Begin: " << endl; dump(grid);
  last = grid;
  sim(grid, ops, h, w, rr, rc);
  dump(grid);
  cout << "final: " << h << " " << w << endl;
  int res = 0;
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < 2*w; c++) {
      if (grid[r][c] == '[') {
        res += 100*r+c;
      }
    }
  }
  cout << res << endl;
}

