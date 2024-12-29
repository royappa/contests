#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;


int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);

  int a, b;
  vector<int> c1;
  map<int,int> c2;
  while (infile >> a >> b) {
    c1.push_back(a);
    c2[b]++;
  }

  int sum = 0;
  for (int i = 0; i < c1.size(); i++) {
    sum += c1[i] * c2[c1[i]];
  }
  cout << sum << endl;
}

