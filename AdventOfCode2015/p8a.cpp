#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

bool isHex(char c) { return isdigit(c) || (c >= 'a' && c <= 'f'); }
int mem(string s) {
  char slash = '\\';
  int n = s.size();
  int len = 0;
  int i = 0;
 while (i < n) {
    char c = s[i];
    len++;
    if (c != slash) { i++; continue; }
    if (i+1 < n && (s[i+1] == slash || s[i+1] == '"')) { i += 2; continue; }
    if (i+1 < n && s[i+1] == 'x') {
      if (i+3 < n && isHex(s[i+2]) && isHex(s[i+3])) {
        i += 4;
        continue;
      }
    }
    i++;
  }
  return len;
}
int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
  string line;
  int codeLen = 0, memLen = 0;
  while (getline(cin, line)) {
    codeLen += line.size();
    line = line.substr(1, (int)line.size()-2);
    memLen += mem(line);
    cout << line << endl;
  }
  cout << codeLen-memLen << endl;
}
