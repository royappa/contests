#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int debug = 0;

int A[1000][1000];


int main(int argc, char *argv[]) {
  if (argc > 1) debug = atoi(argv[1]); 
  
  string line;
  memset(A, 0, sizeof(A));
  while (getline(cin, line)) {
    if (debug > 0) cout << line << endl;
    int r1, c1, r2, c2;
    int op;
    if (line.find("on") != -1) {
      sscanf(line.c_str(), "turn on %d,%d through %d,%d", &r1, &c1, &r2, &c2);
      op = 1;
    }
    else if (line.find("off") != -1) {
      sscanf(line.c_str(), "turn off %d,%d through %d,%d", &r1, &c1, &r2, &c2);
      op = 0;
    }
    else {
      sscanf(line.c_str(), "toggle %d,%d through %d,%d", &r1, &c1, &r2, &c2);
      op = 2;
    }
    if (debug > 0) {cout << line << endl; cout << "op = " << op << "; " << r1 << "," << c1 << "," << r2 << "," << c2 << endl; }
    for (int r = r1; r <= r2; r++) {
      for (int c = c1; c <= c2; c++) {
        if (op == 0) A[r][c] = max(0, A[r][c]-1);
        else if (op == 1) A[r][c]++;
        else A[r][c] += 2;
      }
    }
  }
  int sum = 0;
  for (int r = 0; r < 1000; r++) {
    for (int c = 0; c < 1000; c++) {
      sum += A[r][c];
    }
  }
  cout << sum << endl;
}
