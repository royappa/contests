#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vi v;
  while (getline(cin, line)) {
    v.push_back(stol(line));
  }
  int n = v.size();
  int tot = 0;
  for (int m = 0; m < (1<<n); m++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (m & (1<<i)) {
        sum += v[i];
      }
    }
    if (sum == 150) {
      tot++;
    }
  }
 cout << tot << endl;
}
