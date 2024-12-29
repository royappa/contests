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
      vector<int> diffs(n-1);
      bool adiff = true;
      for (int i = 1; i < n; i++) {
        diffs[i-1] = v[i] - v[i-1];
        if (abs(diffs[i-1]) < 1 || abs(diffs[i-1]) > 3) {
          adiff = false;
          break;
        }
      }
      //for (int i = 0; i < n-1; i++) cout << diffs[i] << ";"; cout << endl;
      if (!adiff) continue;
      bool incdec = true; 
      for (int i = 1; i < n-1; i++) {
        if ((diffs[i-1] < 0 && diffs[i] > 0) || (diffs[i-1] > 0 && diffs[i] < 0)) {
          incdec = false;
          break;
        }
      }
      res += incdec;
      if (incdec) {
      //  / cout << "Safe: " << line << endl;
      }
  }
  cout << res << endl;
}

