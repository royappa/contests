#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) s.c_str();
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

int main()
{

  string line;
  
  map<string,set<string>> before, after;

  while (getline(cin, line)) {
    if (line == "") break;
    vector<string> x = split_nonre(line, "|");
    before[x[1]].insert(x[0]);
    after[x[0]].insert(x[1]); 
  }
  int res = 0;
  while (getline(cin, line)) {
    vector<string> pages = split_nonre(line, ",");
    int n = pages.size();
    bool good = true;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        auto ruleSet = after[pages[i]];
        if (ruleSet.find(pages[j]) != ruleSet.end()) {
          good = false;
          cout << "violation aft " << i << " " << pages[i] << " " << pages[j] << endl;
        }
      }
      for (int j = i+1; j < n; j++) {
        auto ruleSet = before[pages[i]];
        if (ruleSet.find(pages[j]) != ruleSet.end()) {
                    cout << "violation bef " << i << " " << pages[i] << " " << pages[j] << endl;

          good = false;
        }
      }
    }
    if (good) {
      res += atoi(pages[n/2].c_str());
    }    
  }
  cout << res << endl;
}

