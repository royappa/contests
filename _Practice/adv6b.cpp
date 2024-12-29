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
  vector<string> s;
  s = split_nonre(v[0].substr(v[0].find(':')+2), " ");
  LL time = stoll(accumulate(s.begin(), s.end(), string(), [](string a, string b) {return a+b;}));
  s = split_nonre(v[1].substr(v[1].find(':')+2), " ");
  LL dist = stoll(accumulate(s.begin(), s.end(), string(), [](string a, string b) {return a+b;}));

  LL res = 0;
  for (LL i = 0; i <= time; i++) {
    if ((time-i)*i > dist) {
      res++;
    }
  }
  cout << res << endl;
  exit(0);
}
