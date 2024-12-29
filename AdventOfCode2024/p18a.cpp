#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

LL best = LLONG_MAX;

typedef pair<int,int> pii;

int main(int argc, char *argv[])
{
  if (argc != 4) { cout << "Usage" << endl; exit(1); }
  int num = atoi(argv[1]), h = atoi(argv[2]), w = atoi(argv[3]);

  int A[h][w];
  vector<pii> bytes;
  string line;
  while (getline(cin, line)) {
    int r, c;
    sscanf(line.c_str(), "%d,%d", &c, &r);
    bytes.push_back({r,c});
  }

  memset(A, 0, sizeof(A));
  int cur = 0;
  do {
    A[bytes[cur].first][bytes[cur].second] = 1;
    reachable = false;
    queue<pii> q;
    map<pii,int> visited, dist;
    q.push({0,0});
    visited[{0,0}] = 1;
    dist[{0,0}] = 0;
    while (!q.empty()) {
      pii head = q.front();
      q.pop();
      int dir[] = {-1,0, 0,1, 1,0, 0,-1};
      auto [rr, rc] = head;
      for (int i = 0; i < 4; i++) {
        int nr = rr+dir[2*i], nc = rc+dir[2*i+1];
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && visited.count({nr,nc}) == 0 && A[nr][nc] != 1) {
          visited[{nr,nc}] = 1;
          dist[{nr,nc}] = dist[head] + 1;
          q.push({nr,nc});
        }
      }
    }
    if (dist.count({h-1,w-1}) == 0) {
      break;
    }
  } while (true);
  cout << bytes[cur].second << "," << bytes[cur].first << endl;
}

