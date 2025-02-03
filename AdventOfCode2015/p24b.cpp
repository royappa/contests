#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  vector<int> v;
  string line;
  while (getline(cin, line)) {
    v.push_back(stoi(line));
  }
  int n = v.size();
  int set = (1 << 4) - 1;
  int limit = (1 << n);
  int tot = accumulate(v.begin(), v.end(), 0);
  cout << n << " " << tot << " " << tot/3 << endl;
  while (set < limit)
  {
    int sum = 0;
    LL prod = 1LL;
    for (int i = 0; i < n; i++) {
      if (set & (1<<i)) {
        sum += v[i];
        prod *= v[i];
      }
    }
    if (sum == tot/4) {
      cout << prod << endl; // pipe into sort -n, turns out the smallest works..
    }
    // Gosper's hack:
    int c = set & - set;
    int r = set + c;
    set = (((r ^ set) >> 2) / c) | r;
  }
}
