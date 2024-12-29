#include <bits/stdc++.h>

using namespace std;



main() {
  string line;
  int sum = 0;
  while (getline(cin, line)) {
    int d1, d2;
    for (int i = 0; i < line.size(); i++) {
      if (isdigit(line[i])) {
        d1 = line[i] - '0';
        break;
      }
    }
    for (int i = line.size()-1; i >=0; i--) {
      if (isdigit(line[i])) {
        d2 = line[i] - '0';
        break;
      }
    }    
    sum += d1*10+d2;
  }
  printf("%d\n", sum);
  exit(0);
}
