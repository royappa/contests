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
set<string> visited;
int cacheHits = 0;
int nodes = 0, last = 0;
// min steps to parse mol[p,n) ensuring that the remaining letters of the last rule match
int f(string s, int depth) {
  if (s == "e") {
    return 0;
  }
  nodes++;
  if (debug && s.size() < 25) { cout << s << depth << endl;}
  if (debug && (nodes/debug != last)) { cout << s << " nodes = " << nodes << " hits = " << cacheHits << " depth = " << depth << endl; last = nodes/debug; }
  int len = s.size();
  for (int j = 0; j < len; j++) {
    for (int i = 0; i < numRules; i++) {
      string L = rulesL[i], R = rulesR[i];
      if (j+R.size() <= len && s.substr(j, R.size()) == R) {
        string x = s.substr(0, j), y = s.substr(j+R.size());
        string z = x+L+y;
        if (visited.count(z)) {
          cacheHits++;
          continue;
        }
        int res;
        visited.insert(z);
        if ((res = f(z, depth+1)) != INT_MAX) {
          return 1+res;
        }
      }
    }
  }
  return INT_MAX;
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
  for (int i = 0; i < numRules; i++) {
    int maxP = i;
    for (int j = i+1; j < numRules; j++) {
      if (rulesR[j].size() > rulesR[maxP].size()) {
        maxP = j;
      }
    }
    swap(rulesL[i], rulesL[maxP]);
    swap(rulesR[i], rulesR[maxP]);
  }
  cout << f(mol, 0) << endl;
}
