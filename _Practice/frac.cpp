#include <bits/stdc++.h>

using namespace std;

string itoa(int n) {
  char buf[100];
  sprintf(buf, "%d", n);
  return string(buf);
}

string stripLast(string s) {
  int len = s.size();
  return s.substr(0, len-1);
}

void printRes(int a, int b, string result, int n) {
  int p = result.find(')');
  if (p != -1) {
    int d = result.find('.');
    int num = p - d - 2; // number of digits
    if (num > 50) {
      result = stripLast(result);
      while (num-- > 50) {
        result = stripLast(result);
      }
      result += "...)";      
    }

  }
  printf("%d/%d = %s\n", a, b, result.c_str());
  printf("%d = number of digits in repeating cycle\n\n", n);
  return;
}
void genFrac(int a, int b) {
  int aa = a, bb = b;
  string result = itoa(a / b);
  if (a % b == 0) {
    result += ".(0)";
    printRes(aa, bb, result, 1);
    return;
  }
  a %= b;
  result += ".";
  vector<string> frac;
  vector<int> rems;
  rems.push_back(a);
  int rep;
  while (true) {
    int p = 0;
    int p10 = 1;
    while ((p10*a) < b) {
      p++;
      p10 *= 10;
    }
    int q = (p10*a) / b;
    int r = (p10*a) % b;
    frac.push_back(string(p-1, '0') + itoa(q));
    rems.push_back(r);
    rep = -1;
    auto pos = find(rems.begin(), rems.end(), r);
    if (pos != rems.end()) {
      rep = pos - rems.begin();
    }
    if (r == 0 || (rep != -1 && rep != (rems.size() - 1))) {
      break;
    }
    a = r;
  }
  for (int i = 0; i < frac.size(); i++) {
    if (i == rep && rems.back() != 0) {
      result += "(";
    }
    result += frac[i];
  }
  if (rep != -1 && rems.back() != 0) {
    result += ")";
    int len = result.find(')') - result.find('(') - 1;
    printRes(aa, bb, result, len);
  }
  else {
    result += "(0)";
    printRes(aa, bb, result, 1);
  }
  return;
}

main() {
  string line;
  while (getline(cin, line)) {
    int a, b;
    sscanf(line.c_str(), "%d%d", &a, &b);
    genFrac(a, b);
  }
  exit(0);
}
