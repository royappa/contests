#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;


int main(int argc, char *argv[])
{    
  string line;
  getline(cin, line);
  int floor = 0;
  for (int i = 1; i <= line.size(); i++) {
    floor += line[i-1] == '(' ? 1 : -1;
    if (floor < 0) { cout << i << endl; exit(0); }
  }
} 

