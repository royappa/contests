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
typedef pair<string,string> pss;
vector<pss> rules;

bool lessThan(pss A, pss B) {
  return A.second.size() < B.second.size();
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
    rules.push_back({L,R});
  }
  sort(rules.rbegin(), rules.rend(), lessThan);

  int numSteps = 0;
  while (mol != "e") {
    bool match = false;
    for (auto [L,R]: rules) {
      int len = mol.size(), rlen = R.size();
      int pos = -1;
      if (len >= rlen && (pos = mol.find(R)) != -1) {
        mol = mol.substr(0, pos)+L+mol.substr(rlen+pos);
        if (debug) cout << "reduce " << L << " => " << R << endl;
        numSteps++;
        match = true;
        break;
      }
    }
    if (!match) { cout << "fail" << endl; exit(1); }
  }
  cout << numSteps << endl;
}
