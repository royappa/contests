#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;


int main(int argc, char *argv[])
{    
  string line;
  getline(cin, line);
  cout << count(line.begin(), line.end(), '(') - count(line.begin(), line.end(), ')') << endl;
} 

