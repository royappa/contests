#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;

LL best = LLONG_MAX;

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

LL memo[100];

LL poss(int p, string &s, vector<string> w) {
  int n = s.size();
  if (p == n) {
    return 1;
  }
  LL &r = memo[p];
  if (r != -1LL) {
    return r;
  }
  r = 0;
  for (int i = 0; i < w.size(); i++) {
    int wlen = w[i].size();
    if (p+wlen <= n && s.substr(p, wlen) == w[i]) {
      r += poss(p+wlen, s, w);
    }
  }
  return r;
}

int main(int argc, char *argv[])
{
  string line;
  getline(cin, line);
  vector<string> w = split_nonre(line, ", ");

  getline(cin, line);
  LL res = 0;
  while (getline(cin, line)) {
    memset(memo, -1, sizeof(memo));
    res += poss(0, line, w);
  }
  cout << res << endl;
}

