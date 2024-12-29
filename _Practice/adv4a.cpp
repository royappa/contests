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

void getInput(vector<string> &v) {
  string line;
  // goddamn c++ returns a \r on the end of line!!!
  while (getline(cin, line)) {
    while (line[line.size()-1] == '\n' || line[line.size()-1] == '\r') 
      line = line.substr(0, line.size()-1);
    v.push_back(line);
  }
  return;
}

main() {
  LL sum = 0;
  vector<string> v;
  getInput(v);
  int n = v.size(), m = v[0].size();
  vector<LL> cards(n, 1LL);

  for (int i = 0; i < n; i++) {
    string line = v[i];
    int id;
    sscanf(line.c_str(), "Card %d", &id);
    vector<string> p = split_nonre(line.substr(line.find(':')+2), "|");
    vector<string> left = split_nonre(p[0], " "), right = split_nonre(p[1], " ");
    unordered_set<string>leftSet(left.begin(), left.end());
    int matches = count_if(right.begin(), right.end(), 
                           [&leftSet](const string &s) { return leftSet.find(s) != leftSet.end(); });
    matches *= cards[i];
    for (int j = 0; j < matches; j++) {
      v[i+j+1]++;
    }
    sum += 1LL << (matches-1);
  }
  
  sum = accumulate(cards.begin(), cards.end(), 0LL);
  printf("%lld\n", sum);
  exit(0);
}
