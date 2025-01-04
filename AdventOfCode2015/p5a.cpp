#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int debug = 0;


bool nice(string s) {
  if (count_if(line.begin(), line.end(), [](char c) { return string("aeiou").find(c) != -1; }) < 3)
    return false;
  bool ok = false;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i-1]) {
      ok = true;
      break;
    }
  }
  if (!ok) return false;
  for (int i = 1; i < s.size(); i++) {
    string t = s.substr(i-1, 2);
    if (t == "ab" || t == cd || t == "pq" || t == "xy") {
      return false;
    }
  }
  return true;
}
int main(int argc, char *argv[]) {
  if (argc > 1) debug = atoi(argv[1]); // 5 zeroes answer is 254575
  
  int num = 0;p
  string line;
  while (getline(cin, line)) {
    num += nice(line);
  }
  cout << num << endl;
}
