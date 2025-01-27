#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int debug = 0;

vector<string> split_nonre(string s, string sep)  // sep is a list of possible sep characters, not a substring
{
  char* sC = new char[s.size() + 1];
  strcpy(sC, s.c_str());

	char *sepC = (char *) sep.c_str();

	char *word;
	vector<string> results;
	while ((word = strtok(sC, sepC)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}

vector<string> rulesL;
vector<vector<string>> rulesR;
int numRules;
int cacheHits = 0;
int nodes = 0, last = 0;
typedef tuple<string,string> keyType;
map<keyType,int> memo;
set<keyType> visited;
int f(string start, string end);

// number of steps for R[p..n) be expanded into s?
int f2(vector<string> &R, int p, string s) {
  if (debug) { 
    cout << "f2(): R = ";
    for (auto x : R) { cout << x << " ";} cout << " p = " << p << " s = " << s << endl;
  }
  int n = R.size();
  if (s == "") {
    return INT_MAX;
  }
  if (p == n-1) {
    if (s == R[p]) return 0;
    else {
      int t = f(R[p], s);
      if (t != INT_MAX) {
        return t++;
      }
      return t;
    }
  }
  int res = 0;
  int len = s.size();
  for (int i = 0; i < len; i++) {
    string x = s.substr(0, i+1);
    string y = s.substr(i+1);
    int t = INT_MAX;
    if (R[p] == x) {
      t = f2(R, p+1, y);
      if (t != INT_MAX) t++;
    }
    else {
      if (visited.count({R[p], x})) {
        continue;
      }
      t = f(R[p], x);
      if (t != INT_MAX) {
        int t2 = f2(R, p+1, y);
        if (t2 != INT_MAX) {
          t += t2;
        }
      }
    }
    if (t != INT_MAX) {
      res = min(res, 1+t);
    }
  }
  return res;
}

// number of steps to modify string s, which is always the left side of some rule(s), into e
int f(string start, string end) {
  visited.insert({start,end});
  if (debug < 0) { cout << "f(): " << start << " " << end << endl;}
  if (start == end) {
    return 0;
  }
  keyType key = {start, end};
  if (memo.count(key)) {
    return memo[key];
  }
  int res = INT_MAX;
  for (int i = 0; i < numRules; i++) {
    if (rulesL[i] != start) continue;
    // s => R1,R2,R3..
    int r = f2(rulesR[i], 0, end);
    if (r != INT_MAX) {
      res = min(res, 1+r);
    }
  }
  return memo[key] = res;
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

  numRules = 0;
  for (auto rule : ruleSet) {
    string L = rule.substr(0, rule.find(' ')), R = rule.substr(rule.find('>')+2);
    rulesL.push_back(L);
    rulesR.push_back(split_nonre(R, ","));
    numRules++;
  }
  if (debug < 0) {
    cout << numRules << endl;
    for (int i = 0; i < numRules; i++) {
      cout << rulesL[i] << " => ";
      for (auto x : rulesR[i]) {
        cout << x << " ";
      }
      cout << endl;
    }
  }
  cout << f("e", mol) << endl;
}
