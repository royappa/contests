#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;


int main(int argc, char *argv[])
{    
  if (argc > 1) debug = atoi(argv[1]);
  string line;
  getline(cin, line);
  set<pair<int,int>> visited;
  visited.insert({0, 0});
  visited.insert({0, 0});
  vector<int> x(2, 0), y(2, 0);
  int p = 0;
  for (int i = 0; i < line.size(); i++) {
    int dirs[] = {-1,0, 0,1, 1,0, 0,-1};
    string keys = "<^>v";
    int d = keys.find(line[i]);
    x[p] += dirs[2*d];
    y[p] += dirs[2*d+1];
    visited.insert({x[p],y[p]});
    p = (p+1)%2;
  }
  cout << visited.size() << endl;
} 

