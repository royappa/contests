#include <bits/stdc++.h>

using namespace std;

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

main() {
  string line;
  int sum = 0;
  while (getline(cin, line)) { 
    char buf[1000];
    int id;
    sscanf(line.c_str(), "Game %d", &id);
    int p = line.find(':');
    string rest = line.substr(p+2);
    for (int i = rest.size()-1; i >= 0; i--) {
      if (rest[i] == ' ' && i > 0 && (rest[i-1] == ',' || rest[i-1] == ';')) {
        rest.erase(rest.begin()+i);
      }
    }
    vector<string> a = split_nonre(rest, ";");
    int rmax = 0, gmax = 0, bmax = 0;
    for (auto turn: a) {
      vector<string> rgb = split_nonre(turn, ",");
      for (auto col: rgb) {
        int k;
        char c;
        sscanf(col.c_str(), "%d %c", &k, &c);
        if (c == 'r') rmax = max(rmax, k);
        else if (c == 'g') gmax = max(gmax, k);
        else if (c == 'b') bmax = max(bmax, k);
      }
    }
    sum += rmax * gmax * bmax;
  }
  printf("%d\n", sum);
  exit(0);
}
