#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef tuple<string,string> t2;
map<string,int> memo;
set<string> visited;
vector<string> rulesL, rulesR;
int numRules;
LL hits = 0;
int last;
int cacheHits = 0;

int f(string s, string goal, int cur) {
  if (debug) {
    int n = visited.size();
    if ((n-n%debug) != last) {
      last = n-n%debug;
      cout << s << " " << goal << " : " << cur << " " << n << " " << hits << " " << memo.size() << " " << cacheHits << endl;
    }
  }
  if (s == goal) {
    return 0;
  }
  if (memo.count(s)) {
    cacheHits++;
    return memo[s];
  }
  int res = INT_MAX;
  int len = s.size();
  for (int i = 0; i < numRules; i++) {
    string L = rulesL[i], R = rulesR[i];
    for (int j = 0; j < len; j++) {
      if (j+R.size() <= len && s.substr(j, R.size()) == R) {
        string z = s.substr(0, j) + L + s.substr(j+R.size());
        if (visited.count(z) == 0) {
          visited.insert(z);
          int t = f(z, goal, cur+1);
          if (t != INT_MAX) {
            res = min(res, t+1);
          }
        }
        else {
          hits++;
        }
      }
    }
  }
  return memo[s] = res;
}

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  string line;

  vector<string> ruleSet;
  while (getline(cin, line) && line != "") {
    ruleSet.push_back(line);
  }
  string mol;
  getline(cin, mol);

  for (auto rule : ruleSet) {
    string L = rule.substr(0, rule.find(' ')), R = rule.substr(rule.find('>')+2);
    rulesL.push_back(L);
    rulesR.push_back(R);
  }
  numRules = rulesL.size();
  visited.insert(mol);
  last = 0;
  cout << f(mol, "e", 0) << endl;
}
