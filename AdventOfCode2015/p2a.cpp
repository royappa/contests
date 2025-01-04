#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;


int main(int argc, char *argv[])
{    
  if (argc > 1) debug = atoi(argv[1]);
  string line;
  LL sum = 0;
  while (getline(cin, line)) {
    LL h, w, d;
    sscanf(line.c_str(), "%lldx%lldx%lld", &h, &w, &d);
    if (debug) cout << h << " " << w << " " << d << endl;
    sum += (h*w+h*d+d*w)*2 + min(h*w, min(h*d, d*w));
    if (debug) cout << (h*w+h*d+d*w)*2 + min(h*w, min(h*d, d*w))<< endl;
  }
  cout << sum << endl;
} 

