#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int debug = 0;


bool nice(string s) {
  bool ok = false;
  for (int i = 1; i < s.size(); i++) {
    string t = s.substr(i-1, 2);
    if (s.substr(i+1).find(t) != -1) {
      ok = true;
      break;
    }
  }
  if (!ok) return false;
  for (int i = 0; i < (int)s.size()-2; i++) {
    if (s[i] == s[i+2]) {
      return true;
    }
  }
  return false;
}
int main(int argc, char *argv[]) {
  if (argc > 1) debug = atoi(argv[1]); // 5 zeroes answer is 254575
  
  int num = 0;
  string line;
  while (getline(cin, line)) {
    num += nice(line);
  }
  cout << num << endl;
}
