#include <bits/stdc++.h>
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
  set<string> cities;
  map<string,map<string,int>> graph;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    string a = w[0], b = w[2];
    graph[a][b] = graph[b][a] = stoi(w[4]);
    cities.insert(a);
    cities.insert(b);
  }
  int best = 1<<30;
  vector<string> v(cities.begin(), cities.end());
  for (auto x : v) cout << x << " "; cout << endl;
  do {
    int dist = 0;
    for (int i = 1; i < v.size(); i++) {
      dist += graph[v[i-1]][v[i]];
    }
    if (debug) {
      for (int i = 1; i < v.size(); i++) {
        cout << v[i-1] << " to " << v[i] << " " << graph[v[i-1]][v[i]] << endl;
      }
      cout << "best from " << v[0] << " to " << v[(int)v.size()-1] << " = " << dist << endl;
    }
    best = min(dist, best);
  } while (next_permutation(v.begin(), v.end()));
  cout << best << endl;
}
