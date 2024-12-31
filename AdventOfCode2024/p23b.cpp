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

int maxClique;
string best;

void BronKerbosch(set<string> R, set<string> P, set<string> X, map<string,set<string>> &graph) {
  if (P.size() == 0 && X.size() == 0) {
    if (R.size() > maxClique) {
      maxClique = R.size();
      best = "";
      int num = 0;
      for (auto x : R) {
        best += x;
        num++;
        if (num != R.size()) 
          best += ",";
      }
    }
    return;
  }
  
  while (P.size() > 0) {
    string v = *(P.begin());
    set<string> NR = R;
    NR.insert(v);
    set<string> PV, XV;
    set_intersection(P.begin(), P.end(), graph[v].begin(), graph[v].end(), inserter(PV, PV.begin()));
    set_intersection(X.begin(), X.end(), graph[v].begin(), graph[v].end(), inserter(XV, XV.begin()));
    BronKerbosch(NR, PV, XV, graph);
    P.erase(v);
    X.insert(v);
  }
}

int main(int argc, char *argv[])
{
  if (argc > 1) debug = atoi(argv[1]);
 
  string line;
  map<string,set<string>> graph;
  set<string> nodes;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, "-");
    sort(w.begin(), w.end());
    nodes.insert(w.begin(), w.end());
    graph[w[0]].insert(w[1]);
    graph[w[1]].insert(w[0]);
  }
  
  maxClique = 0;
  BronKerbosch({}, nodes, {}, graph);
  cout << maxClique << " " << best << endl;
}

