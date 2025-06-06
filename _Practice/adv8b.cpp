#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

// handle blasted c++ on cygwin returning a \r on the end of line!!!
void getInput(vector<string> &v) {
  string line;
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}


main() {
  vector<string> v;
  getInput(v);
  int n = v.size();
  string seq = v[0];
  map<string,string> left, right;
  set<string> cur;
  for (int i = 2; i < n; i++) {
    char buf1[4], buf2[4], buf3[4];
    sscanf(v[i].c_str(), "%[A-Z0-9] = (%[A-Z0-9], %[A-Z0-9])", buf1, buf2, buf3);
    string node1(buf1), node2(buf2), node3(buf3);
    left[node1] = node2;
    right[node1] = node3;
    for (auto node : {node1, node2, node3}) {
      if (node[2] == 'A') {
        cur.insert(node);
      }
    }
  }


  LL total = 1;
  for (auto node : cur) {
    LL steps = 0;
    int m = seq.size();
    string here = node;
    for (int i = 0; i < m; i = (i+1)%m) {
      here = seq[i] == 'L' ? left[here] : right[here];
      steps++;
      if (here[2] == 'Z') break;
    }
    total = (total*steps)/gcd(total, steps);
  } 
  cout << total << endl;
  exit(0);
}
