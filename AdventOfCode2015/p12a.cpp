#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

vector<int> getInts(string &input) {
  vector<int> v;

  regex intPat("-?\\d+");
  auto begin = sregex_iterator(input.begin(), input.end(), intPat);
  auto end = sregex_iterator();
    for (sregex_iterator it = begin; it != end; ++it) {
    smatch match = *it;
    v.push_back(stoi(match.str()));
  }
  return v;
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  string line;
  int res = 0;
  while (getline(cin, line)) {
    vector<int> v = getInts(line);
    res += accumulate(v.begin(), v.end(), 0);
  }

  cout << res << endl;
}
