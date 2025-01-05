#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

map<pair<string,int>,LL> memo;

LL say(string s, int k) {
  if (k == 0) {
    return s.size();
  }
  pair<string,int> key = {s,k};
  if (memo.count(key)) {
    return memo[key];
  }
  LL r = 0;
  string cur = string(1, s[0]);
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i-1]) {
      r += say(to_string(cur.size())+cur[0], k-1);
      cur = string(1, s[i]);
    }
    else {
      cur += s[i];
    }
  }
  r += say(to_string(cur.size())+cur[0], k-1);
  return memo[key] = r;
}

int main(int argc, char *argv[])
{
  if (argc != 4) { cout << "Usage" << endl; exit(1); }
  debug = atoi(argv[1]);
  string line = argv[2];
  int num = atoi(argv[3]);
  
  cout << say(line, num) << endl;
}
