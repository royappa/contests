#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

typedef map<string,set<string>> mss;

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

bool check(vector<string> &pages, mss before, mss after, bool fix)
{
    int n = pages.size();
    bool good = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        auto ruleSet = after[pages[i]];
        if (ruleSet.find(pages[j]) != ruleSet.end()) {
          good = false;
          if (fix) {
            swap(pages[i], pages[j]);
            return false;
          }
        }
      }
      for (int j = i+1; j < n; j++) {
        auto ruleSet = before[pages[i]];
        if (ruleSet.find(pages[j]) != ruleSet.end()) {
          good = false;
          if (fix) {
            swap(pages[i], pages[j]);
            return false;
          }          
        }
      }
    }
    return good;
}
int main()
{

  string line;
  
  mss before, after;
  set<string> violators;

  while (getline(cin, line)) {
    if (line == "") break;
    vector<string> x = split_nonre(line, "|");
    before[x[1]].insert(x[0]);
    after[x[0]].insert(x[1]); 
  }
  int res = 0;
  while (getline(cin, line)) {
    vector<string> pages = split_nonre(line, ",");
    if (check(pages, before, after, false)) continue;
    while (!check(pages, before, after, true)) {
      ;
    }
    res += atoi(pages[pages.size()/2].c_str());
  }
  cout << res << endl;
}

