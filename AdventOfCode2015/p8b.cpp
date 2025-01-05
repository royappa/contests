#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
  string line;
  int codeLen = 0;
  while (getline(cin, line)) {
    codeLen += 2+count_if(line.begin(), line.end(), [](char c) {return c == '\\' || c == '"';});
  }
  cout << codeLen << endl;
}
