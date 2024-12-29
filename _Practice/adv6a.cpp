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
  vector<string> v;
  getInput(v);
  vector<string> s = split_nonre(v[0].substr(v[0].find(':')+2), " ");
  int n = s.size();
  vector<int> times(n), distances(n);
  transform(s.begin(), s.end(), times.begin(), [](const string &str) {return stoi(str);});
  s = split_nonre(v[1].substr(v[1].find(':')+2), " ");
  transform(s.begin(), s.end(), distances.begin(), [](const string &str) {return stoi(str);});

  LL res = 1LL;
  for (int i = 0; i < n; i++) {
    int wins = 0;
    for (int j = 0; j <= times[i]; j++) {
      int d = (times[i]-j)*j;
      if (d > distances[i]) {
        wins++;
      }
    }
    res *= wins;
  }
  cout << res << endl;
  exit(0);
}
