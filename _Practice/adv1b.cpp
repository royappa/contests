#include <bits/stdc++.h>

using namespace std;



main() {
  string line;
  int sum = 0;
  while (getline(cin, line)) {
    vector<int> v;
    int n = line.size();
    for (int i = 0; i < n; i++) {
      if (isdigit(line[i])) {
        v.push_back(line[i]-'0');
        continue;
      }
      int p = 1;
      for (string w : {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}) {
        if (line.substr(i, w.size()) == w) {
          v.push_back(p);
          break;
        }
        p++;
      }
    }
    sum += 10*v[0] + v.back();
  }
  printf("%d\n", sum);
  exit(0);
}
