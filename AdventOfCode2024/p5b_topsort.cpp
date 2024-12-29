#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef pair<string,string> pss;

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

bool lessThan(pss a, pss b) {
  return a.second == b.first;
}
int main()
{

  string line;
  
  vector<pss> rules;

  set<string> all;
  while (getline(cin, line)) {
    if (line == "") break;
    vector<string> x = split_nonre(line, "|");
    rules.push_back({x[0], x[1]});
    all.insert(x[0]);
    all.insert(x[1]);
  }
  vector<string> sorted;
  set<string> noinc;
  for (auto x : all) {
    int c = 0;
    for (int i = 0; i < rules.size(); i++) {
      c += rules[i].second == x;
    }
    if (c == 0) noinc.insert(x);
  }

  while (noinc.size() > 0) {
    auto it = noinc.begin();
    string x = *it;
    sorted.push_back(x);
    noinc.erase(it);
    vector<int> remove;
    for (int i = 0; i < rules.size(); i++) {
      if (rules[i].first == x) {
        remove.push_back(i);
      }
    }
    set<string> targets;
    for (int i = int(remove.size()) -1; i >= 0; i--) {
      targets.push_back(rules[i].second);
      rules.erase(rules.begin()+i);
    }
    for (auto x : targets) {
      int c = 0;
      for (int i = 0; i < rules.size(); i++) {
        if (rules[i].second == x) {
          c++;
        }
      }
      if (c == 0) {
        noinc.insert(x);
      }
    }
  }
  for (auto z : sorted) {
    cout << z << " ";
  }
  cout << endl;

  int res = 0;
  while (getline(cin, line)) {
    vector<string> pages = split_nonre(line, ",");

    set<string> used;
    for (int i = 0; i < rules.size(); i++) {
      auto [a,b] = rules[i];
      auto pa = find(pages.begin(), pages.end(), a), pb = find(pages.begin(), pages.end(), b);
      if (pa != pages.end() && pb != pages.end()) {
        pages[pa-pages.begin()] = "";
        pages[pb-pages.begin()] = "";
        used.insert(a);
        used.insert(b);
      }
    }

    if (!good) {
      res += atoi(pages[pages.size()/2].c_str());
    }
  }
  cout << res << endl;
}

