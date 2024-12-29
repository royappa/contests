#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;



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

bool isSafeDiff(vector<int> &d) {
  int n = d.size();
  for (int i = 1; i < n; i++) {
    if (d[i-1]*d[i] <= 0 || max(abs(d[i]), abs(d[i-1])) > 3) return false;
  }
  return true;
}

vector<int> getDiffs(vector<int> v) {
  vector<int> diffs;
  for (int i = 1; i < v.size(); i++) {
    diffs.push_back(v[i] - v[i-1]);
  }
  return diffs;
}
bool isSafe(vector<int> v) {
  int n = v.size();
  if (n == 2) return true;
  vector<int> diffs = getDiffs(v);
  if (isSafeDiff(diffs)) return true;
  
  for (int i = 0; i < n; i++) {
    vector<int> w = v;
    w.erase(w.begin()+i);
    diffs = getDiffs(w);
    if (isSafeDiff(diffs)) return true;
  }
  return false;
}

int main(int argc, char *argv[])
{
  std::ifstream infile(argv[1]);

  string line;
  int res = 0;
  while (getline(infile, line)) {
      vector<string> vs = split_nonre(line, " ");
      int n = vs.size();
      vector<int> v(n);
      for (int i = 0; i < n; i++) {
        v[i] = atoi(vs[i].c_str());
      }
      if (isSafe(v)) {
        res++;
      }
  }
  cout << res << endl;
}

