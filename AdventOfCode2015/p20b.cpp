#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;
  int num;
  scanf("%d", &num);
  for (int house = 1; ; house++) {
    set<int> divs;
    for (int d = 1; d*d <= house; d++) {
      if (house%d == 0) {
        divs.insert(d);
        divs.insert(house/d);
      }
    }

    int tot = 0;
    for (auto x : divs) {
      int del = house/x;
      if (del <= 50) {
        tot += x*11;
      }
      if (tot >= num) {
        cout << house << " " << tot << endl;
        exit(1);
      }
    }
    if (debug) cout << house << " " << tot << endl;
  }
  
}
