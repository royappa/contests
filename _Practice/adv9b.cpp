#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
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

// handle blasted c++ on cygwin returning a \r on the end of line!!!
void getInput(vector<string> &v) {
  string line;
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}


main() {
  vector<string> v;
  getInput(v);

  LL sum = 0;
  for (auto line : v) {
    vector<string> s = split_nonre(line, " ");
    int n = s.size();
    vector<LL> nums(n);
    transform(s.begin(), s.end(), nums.begin(), [](string s) {return stoll(s);});
    vector<vector<LL>> tab;
    tab.push_back(nums);
    vector<LL> next;
    do {
      vector<LL> cur = tab[tab.size()-1];
      next.clear();
      for (int i = 1; i < cur.size(); i++) {
        next.push_back(cur[i]-cur[i-1]);
      }
      tab.push_back(next);
    } while (!all_of(next.begin(), next.end(), [](LL x) { return x == 0;}));
    int p = tab.size()-1;
    tab[p].insert(tab[p].begin(), 0);
    for (int i = p-2; i >= 0; i--) {
      tab[i].insert(tab[i].begin(), tab[i][0]-tab[i+1][0]);
    }
    sum += tab[0][0];
  }
  cout << sum << endl;
  exit(0);
}
