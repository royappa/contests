#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
  char* sC = new char[s.size() + 1];
  std::strcpy(sC, s.c_str());

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

bool check(LL target, vector<LL> &eq, vector<int> ops, int p) {
  int n = ops.size();
  if (p == n) {
    LL tot = eq[0];
    for (int i = 0; i < n; i++) {
      int op = ops[i];
      if (op == 0) {
        tot += eq[i+1];
      }
      else if (op == 1) {
        tot *= eq[i+1];
      }
      else {
        char buf[100];
        sprintf(buf, "%lld%lld", tot, eq[i+1]);
        tot = atoll(buf);
      }
    }
    return tot == target;
  }
  for (int op = 0; op < 3; op++) {
    ops[p] = op;
    if (check(target, eq, ops, p+1)) {
      return true;
    }
  } 
  return false;
}

int main()
{
  string line;
  vector<LL> t;
  vector<vector<LL>> eqs;

  while (getline(cin, line)) {
      string a, b;
      vector<string> w = split_nonre(line, ":");
      t.push_back(atoll(w[0].c_str()));
      w = split_nonre(w[1].substr(1), " ");
      vector<LL> v;
      for (auto x : w) {
        v.push_back(atoll(x.c_str()));
      }
      eqs.push_back(v);
  }

  LL res = 0;
  for (int i = 0; i < t.size(); i++) {
    vector<int> ops((eqs[i].size())-1);
    if (check(t[i], eqs[i], ops, 0)) {
      res += t[i];
    }
  }
  cout << res << endl;
}

