#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<int,int> pii;

void getnums(string s, int &a, int &b, int &c, int &d) {
  regex r(R"((-?\d+).*?(-?\d+).*?(-?\d+).*?(-?\d+))");
  smatch m;
  regex_search(s, m, r);
  a = stoi(m[1]);
  b = stoi(m[2]);
  c = stoi(m[3]);
  d = stoi(m[4]);
}

int main(int argc, char *argv[])
{

  string line;
  LL res = 0;
  int w = atoi(argv[1]), h = atoi(argv[2]);
  int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
  while (getline(cin, line)) {
    int px, py, vx, vy;
    getnums(line, px, py, vx, vy);
    cout << px << " " << py << " " << vx << " " << vy << endl;
    for (int i = 0; i < 100; i++) {
      px += vx;
      if (px < 0) px += w; else if (px >= w) px %= w;
      py += vy;
      if (py < 0) py += h; else if (py >= h) py %= h;
    }
    if (px < w/2 && py < h/2) q1++;
    else if (px > w/2 && py < h/2) q2++;
    else if (px < w/2 && py > h/2) q3++;
    else if (px > w/2 && py > h/2) q4++;
    else {
      cout << px << " " << py << endl;
    }
  } 
  cout << q1 << " " << q2 << " " << q3 << " " << q4 << endl;
  cout << "Result: " << q1*q2*q3*q4 << endl;
}

