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

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(int argc, char *argv[])
{
  if (argc > 1) { debug = atoi(argv[1]); }
  
  vvi all(4);
  for (int i = 0; i < 4; i++) {
    string line;
    getline(cin, line);
    vector<string> w = split_nonre(line, " ");
    all[i] = {stoi(w[2]), stoi(w[4]), stoi(w[6]), stoi(w[8]), stoi(w[10])};
  }
  LL best = 0;
  for (LL a = 0; a <= 100; a++) {
    for (LL b = 0; b <= 100-a; b++) {
      for (LL c = 0; c <= 100-a-b; c++) {
        for (LL d = 0; d <= 100-a-b-c; d++) {
          LL cur = 1;
          for (int i = 0; i < 4; i++) {
            LL prop = a*all[0][i]+b*all[1][i]+c*all[2][i]+d*all[3][i];
            prop = max(prop, 0LL);
            cur *= prop;
          }
          LL cal = a*all[0][4]+b*all[1][4]+c*all[2][4]+c*all[3][4];
          if (cal == 500)
            best = max(cur, best);
        }
      }
    }
  }
  cout << best << endl;
}
