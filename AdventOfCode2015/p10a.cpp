#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;


string say(string s) {
  string r = "";
  string cur = string(1, s[0]);
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i-1]) {
      r += to_string(cur.size())+cur[0];
      cur = string(1, s[i]);
    }
    else {
      cur += s[i];
    }
  }
  r += to_string(cur.size())+cur[0];
  return r;
}

int main(int argc, char *argv[])
{
  if (argc != 4) { cout << "Usage" << endl; exit(1); }
  debug = atoi(argv[1]);
  string line = argv[2];
  int num = atoi(argv[3]);
  string res = "";
  if (debug) cout << line << endl;
  for (int i = 0; i < num; i++) {
    line = say(line);
    if (debug) cout << line << endl;
  }
  cout << line.size() << endl;
}
