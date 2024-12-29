#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void get2(string s, int &a, int &b) {
  regex r(R"((\d+).*?(\d+))");
  smatch m;
  regex_search(s, m, r);
  a = stoll(m[1]);
  b = stoll(m[2]);
}

int solve(int xa, int ya, int xb, int yb, int xp, int yp) {
  int best = 1<<30;
  bool found = false;
  for (int a = 0; a <= 100; a++) {
    for (int b = 0; b <= 100; b++) {
      if (a*xa+b*xb == xp && a*ya+b*yb == yp) {
        found = true;
        best = min(best, 3*a+b);
      }
    }
  }
  return found ? best : 0;
}

int main(int argc, char *argv[])
{
  string line;
  int res = 0;
  do {
    int xa, ya, xb, yb, xp, yp;
    getline(cin, line); cout << line << endl;
    get2(line, xa, ya);
    getline(cin, line); cout << line << endl;
    get2(line, xb, yb);
    getline(cin, line); cout << line << endl;
    get2(line, xp, yp);
    res += solve(xa, ya, xb, yb, xp, yp);
  } while (getline(cin, line));
  
  cout << "Result: " << res << endl;
}

