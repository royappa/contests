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

  int best = 0;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    int speed = stoi(w[3]);
    int flyTime = stoi(w[6]);
    int restTime = stoi(w[13]);
    bool flying = true;
    int dist = 0;
    int fly = flyTime, rest = restTime;
    for (int sec = 1; sec <= 2503; sec++) {
      if (flying) {
        dist += speed;
        fly--;
        if (fly == 0) {
          flying = false;
          rest = restTime;
          fly = flyTime;
        }
      }
      else {
        rest--;
        if (rest == 0) {
          flying = true;
          rest = restTime;
          fly = flyTime;
        }
      }
    }
    best = max(best, dist);
  }
  cout << best << endl;
}
