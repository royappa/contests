#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;
vector<string> rulesL, rulesR;
int numRules;
string mol;
int n;

// min steps to parse mol[p,n) ensuring that the remaining letters of the last rule match
int f(int p, int lastRule, int k) {
  if (p == n) {
    if (lastRule == -1 || k == rulesR[lastRule].size()) {
      return 0;
    }
    else { // there is a last rule, and there are unmatched letters
      return INT_MAX;
    }
  }
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vector<string> ruleSet;
  while (getline(cin, line) && line != "") {
    ruleSet.push_back(line);
  }
  getline(cin, mol);
  n = mol.size();

  for (auto rule : ruleSet) {
    string L = rule.substr(0, rule.find(' ')), R = rule.substr(rule.find('>')+2);
    rulesL.push_back(L);
    rulesR.push_back(R);
  }
  numRules = rulesL.size();
  cout << f(0, -1, 0) << endl;
}
