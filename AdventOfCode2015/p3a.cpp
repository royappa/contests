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
  int num = 0, x = 0, y = 0;
  visited.insert({x,y});
  num++;
  for (int i = 0; i < line.size(); i++) {
    int dirs[] = {-1,0, 0,-1, 1,0, 0,1};
    string keys = "<^>v";
    int d = keys.find(line[i]);
    x += dirs[2*d];
    y += dirs[2*d+1];
    if (visited.count({x,y}) == 0) num++;
    visited.insert({x,y});
  }
  cout << num << endl;
} 

