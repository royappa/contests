#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;

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

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
 
  string line;
  map<string,set<string>> graph;
  set<string> ts;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, "-");
    sort(w.begin(), w.end());
    copy_if(w.begin(), w.end(), inserter(ts, ts.end()), 
            [](string s) {return s[0] == 't';}
    );
    graph[w[0]].insert(w[1]);
    graph[w[1]].insert(w[0]);
  }
  int num = 0;
  set<set<string>> threes;
  for (auto t : ts) {
    for (auto x : graph[t]) {
      for (auto y : graph[t]) {
        if (graph[x].count(y)) {
          threes.insert({t,x,y});
        }
      }
    }
  }
  cout << threes.size() << endl;
}

