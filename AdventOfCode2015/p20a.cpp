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

    if (accumulate(divs.begin(), divs.end(), 0)*10 >= num) {
      cout << house << endl;
      exit(1);
    }
    else {
      if (debug) cout << house << " " << accumulate(divs.begin(), divs.end(), 0)*10 << endl;
    }
  }
  
}
