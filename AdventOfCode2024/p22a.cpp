#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
 
  LL sum = 0;
  string line;
  while(getline(cin, line)) {
    LL secret = stoll(line);
    if (debug > 0) { cout << secret << ": " << endl; }
    for (int i = 0; i < 2000; i++) {
      secret ^= secret * 64;
      secret %= 16777216;

      secret ^= secret / 32;
      secret %= 16777216;

      secret ^= secret * 2048LL;
      secret %= 16777216;
      if (debug > 2 && i < 10) { cout << " " << secret << endl;}
    }
    if (debug > 0) cout << secret << endl;
    sum += secret;
  }
  cout << sum << endl;
}

