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

LL runMap(LL x, vector<vector<LL>> &mp) {
  for (auto range : mp) {
    LL d = range[0], s = range[1], len = range[2];
    if (x >= s && x < s+len) {
      return d+(x-s);
    }
  }
  return x;
}

main() {
  vector<string> v;
  getInput(v);
  int n = v.size();

  vector<string> s = split_nonre(v[0].substr(v[0].find(':')+2), " ");
  vector<LL> seeds(s.size());
  transform(s.begin(), s.end(), seeds.begin(), [](const string &str) { return stoll(str); });

  //for (auto z : seeds) { cout << z << " "; }; cout << endl;

  v.push_back("");
  vector<vector<vector<LL>>> maps(7);
  int p = 3;
  for (int i = 0; i < 7; i++) {
      while (v[p] != "") {
        LL a, b, c;
        vector<LL> range(3);
        cout << "Processing " << v[p] << endl;
        s = split_nonre(v[p], " ");
        transform(s.begin(), s.end(), range.begin(), [](const string &str) { return stoll(str); });
        maps[i].push_back(range);
        p++;
      }
      p += 2;
  }
  /*
  for (int i = 0; i < 7; i++) {
    printf("map %d\n", i+1);
    for (int j = 0; j < maps[i].size(); j++) {
      printf("%lld %lld %lld\n", maps[i][j][0], maps[i][j][1], maps[i][j][2]);
    }
  }
  */
  vector<LL> loc(seeds.size());
  for (int i = 0; i < seeds.size(); i++) {
    // get loc of seeds[i]
    LL cur = seeds[i];
    for (int j = 0; j < 7; j++) {
      cur = runMap(cur, maps[j]);
    }
    loc[i] = cur;
  }
  cout << *min_element(loc.begin(), loc.end());
  exit(0);
}
