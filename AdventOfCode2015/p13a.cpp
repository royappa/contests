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
  if (argc > 1) { debug = atoi(argv[1]); }
  
  string line;
  map<string,map<string,int>> gain, loss;
  set<string> guests;
  while (getline(cin, line)) {
    line = line.substr(0, (int)line.size()-1);
    vector<string> w = split_nonre(line, " ");
    guests.insert(w[0]);
    if (w[2] == "lose") {
      loss[w[0]][w[10]] = stoi(w[3]);
    }
    else {
      gain[w[0]][w[10]] = stoi(w[3]);
    }
  }
  for (auto a : loss) { for (auto b : loss[a.first]) {cout << a.first << " " << b.first << " " << loss[a.first][b.first] << endl; }}
  vector<string> v(guests.begin(), guests.end());
  int n = v.size();
  int best = -(1<<30);
  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      string leftg = v[(((i-1)%n)+n)%n], rightg = v[(i+1)%n];
      string cur = v[i];
      if (loss.count(cur) && loss[cur].count(leftg)) sum -= loss[cur][leftg];
      if (gain.count(cur) && gain[cur].count(leftg)) sum += gain[cur][leftg];
      if (loss.count(cur) && loss[cur].count(rightg)) sum -= loss[cur][rightg];
      if (gain.count(cur) && gain[cur].count(rightg)) sum += gain[cur][rightg];
    }
    best = max(best, sum);
  } while (next_permutation(v.begin(), v.end()));
  cout << best << endl;
}
