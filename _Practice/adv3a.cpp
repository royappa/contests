#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int check(vector<string> &v, int r, int c) {
  string symbols = "+%*$#/=@-&";
  int n = v.size(), m = v[0].size();
  int d[] = {-1, -1, -1, 0, -1, 1, 0, -1, 0, 1, 1, -1, 1, 0, 1, 1};
  for (int i = 0; i < 8; i++) {
    int rr = r+d[2*i];
    int cc = c+d[2*i+1];
    if (rr < n && cc < m && rr >= 0 && cc >= 0 && !isdigit(v[rr][cc]) && v[rr][cc] != '.') {
      cout << "true for:" << rr << " " << cc << endl;
      return true;
    }
  }
  return false;
}

main() {
  string line;
  LL sum = 0;
  vector<string> v;
  // goddamn c++ returns a \r on the end of line!!!
  while (getline(cin, line)) {
    if (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  int n = v.size(), m = v[0].size();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (isdigit(v[i][j])) {
        int val = 0;
        bool ok = false;
        while (j < m && isdigit(v[i][j])) {
          val = val*10+(v[i][j]-'0');
          ok = ok || check(v, i, j);
          cout << i << " " << j << " " << check(v, i, j) << endl;
          j++;
        }
        if (ok) {
          cout << val << " ok" << endl;
          sum += val;
        } 
        else {
          cout << val << " not ok" << endl;
        }
      }
    }
  }
  printf("%lld\n", sum);
  exit(0);
}
