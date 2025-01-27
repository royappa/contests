#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vector<string> rules;
  while (getline(cin, line) && line != "") {
    rules.push_back(line);
  }
  string mol;
  getline(cin, mol);
  int len = mol.size();

  set<string> all;
  for (auto rule : rules) {
    string L = rule.substr(0, rule.find(' ')), R = rule.substr(rule.find('>')+2);
    if (debug) cout << L << " " << R << endl;
    for (int i = 0; i+L.size() <= len; i++) {
      if (mol.substr(i, L.size()) == L) {
        string x = mol.substr(0, i), y = mol.substr(i+L.size());
        all.insert(x+R+y);
      }
    }
  }
  cout << all.size() << endl;
}
