#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef tuple<int,int,int> t3;
const int INF = 1<<30;

#define GOOD(ar,ac,hh,ww) ((ar) >= 0 && (ar) < (hh) && (ac) >= 0 && (ac) < (ww))

vector<string> last;
int dir[] = {-1,0, 0,1, 1,0, 0,-1}; // NESW

void dump(vector<string> &grid) { 
  int w = grid[0].size();
  for (int i = 0; i < w; i++) {
    cout << char('0'+(i%10));
  }
  cout << endl;
  int r = 0;
  for (auto x : grid) {
      cout << x << char('0'+(r++%10)) << endl;
  }
  for (int i = 0; i < w; i++) {
    cout << char('0'+(i%10));
  }
  cout << endl;  
}

string t3out(t3 t) { auto [r,c,i] = t; char buf[100]; sprintf(buf, "(%d,%d,%d)", r, c, i); return string(buf); }

int solve(vector<string> &grid, int sr, int sc, int er, int ec) {
  map<t3,int> dist;
  map<pair<t3,t3>,int> edgeCost;
  map<t3,set<t3>> edges;
  set<t3> unvisited;
  map<t3,set<t3>> prev;

  int h = grid.size(), w = grid[0].size();
  for (int r = 0; r < h; r++) {
    for (int c = 0; c < w; c++) {
      if (grid[r][c] == '.') {
        for (int i = 0; i < 4; i++) {
          dist[{r,c,i}] = INF;
          t3 n = {r,c,i}, n1 = {r,c,(i+1)%4}, n2 =  {r,c,((i-1)%4+4)%4};
          edgeCost[{n,n1}] = 1000; edgeCost[{n1,n}] = 1000;
          edges[n].insert(n1); edges[n1].insert(n);
          edgeCost[{n,n2}] = 1000; edgeCost[{n1,n}] = 1000;
          edges[n].insert(n2); edges[n2].insert(n);
          int nr = r+dir[2*i], nc = c+dir[2*i+1];
          unvisited.insert(n); unvisited.insert(n1); unvisited.insert(n2);
          t3 n3 = {nr,nc,i};
          if (grid[nr][nc] == '.') {
            edgeCost[{n,n3}] = 1;
            edgeCost[{n3,n}] = 1;
            edges[n].insert(n3); edges[n3].insert(n);
            unvisited.insert(n3);
          }
        }
      }
    }
  }
  cout << edgeCost[{{1,1,0},{2,1,0}}] << "*" << endl;
  dist[{sr,sc,1}] = 0;

  do {
    int minCost = INF;
    t3 s;
    bool found = false;
    for (auto n : unvisited) {
      if (dist[n] < minCost) {
        minCost = dist[n];
        s = n;
        found= true;
      }
    }
    if (found) {
      // cout << "next is " << t3out(s) << endl;
      unvisited.erase(s);
      if (unvisited.size()%100 == 0)
        cout << unvisited.size() << endl;
      for (auto it = edges[s].begin(); it != edges[s].end(); it++) {
        auto t = *it; if (unvisited.count(t) == 0) continue;
        // cout << "   nbr " << t3out(t) << " with dist " << (dist[t]==INF?-1:dist[t]) << " at cost " << edgeCost[{s,t}] << endl;
        if (dist[s]+edgeCost[{s,t}] <= dist[t]) {
          dist[t] = dist[s]+edgeCost[{s,t}];
          prev[t].insert(s);
          // cout << "      can reach " << t3out(t) << " with distance " << (dist[t]==INF?-1:dist[t]) << endl;
        }
      }
    }
    else {
      cout << " not found " << endl;
      break; // only unreachable nodes left
    }
  } while (true);
  int best = INF;
  for (int i = 0; i < 4; i++) {
    if (dist[{er,ec,i}] < best) {
      best = dist[{er,ec,i}];
    }
  }
  return best;
}

int main(int argc, char *argv[])
{
  vector<string> grid;
  string line;
  int sr, sc = -1, er, ec = -1;
  int h = 0, w = 0;
  while (getline(cin, line)) {
    grid.push_back(line);
    if (sc == -1 && (sc = line.find('S')) != -1) {sr = h; }
    if (ec == -1 && (ec = line.find('E')) != -1) {er = h; }
    h++;
  }
  dump(grid);
  cout << "Start: " << sr << " " << sc << " End: " << er << " " << ec << endl;
  grid[sr][sc] = grid[er][ec] = '.';
  w = grid[0].size();

  int res = solve(grid, sr, sc, er, ec);
  cout << res << endl;
}

