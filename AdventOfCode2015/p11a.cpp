#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

bool valid(string s) {
  if (!all_of(s.begin(), s.end(), [](char c){return string("iol").find(c) == -1;})) {
    return false;
  }
  int n = s.size();
  bool ok = false;
  for (int i = 2; i < n; i++) {
    if (s[i-2]+1 == s[i-1] && s[i-1]+1 == s[i]) {
      ok = true;
      break;
    }
  }
  if (!ok) return false;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j) continue;
      string xx = string(2, char('a'+i)), yy = string(2, char('a'+j));
      if (s.find(xx) != -1 && s.find(yy) != -1) {
        return true;
      }
    }
  }
  return false;
}

string inc(string s) {
  int n = s.size();
  int i = n-1;
  while (s[i] == 'z') {
    s[i] = 'a';
    i--;
  }
  s[i]++;
  return s;
}

int main(int argc, char *argv[])
{
  if (argc != 3) { cout << "Usage" << endl; exit(1); }
  debug = atoi(argv[1]);
  string line = argv[2];
  
  if (debug) cout << line << endl;
  while (!valid(line)) {
    line = inc(line);
    if (debug) cout << line << endl;

  }
  cout << line << endl;
}
