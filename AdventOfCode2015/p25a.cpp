#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  int row = 1, col = 1;
  int endRow = stoi(argv[2]), endCol = stoi(argv[3]);
  LL val = 20151125, mul = 252533, mod = 33554393;
  int diag = 1;
  while (true) {
    if (row == 1 && col == diag) {
      diag++;
      row = diag;
      col = 1;
    }
    else {
      row--;
      col++;
    }
    val = (val * mul) % mod;
    if (debug) {
      cout << row << " " << col << " " << val << endl;
    }
    if (row == endRow && col == endCol) {
      cout << "val = " << val << endl;
      exit(1);
    }
  }
}
