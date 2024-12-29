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

bool check(LL target, vector<LL> eq) {
  int n = eq.size();
  int ops = n - 1;
  for (int m = 0; m < (1<<ops); m++) {
    LL tot = eq[0];
    for (int j = 0; j < ops; j++) {
      if (m&(1<<j)) {
        tot *= eq[j+1];
      }
      else {
        tot += eq[j+1];
      }
    }
    if (tot == target) {
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
    if (check(t[i], eqs[i])) {
      res += t[i];
    }
  }
  cout << res << endl;
}

