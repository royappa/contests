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
  
  string line;

  int best = 0;
  vvi all;
  while (getline(cin, line)) {
    vector<string> w = split_nonre(line, " ");
    int speed = stoi(w[3]);
    int flyTime = stoi(w[6]);
    int restTime = stoi(w[13]);
    all.push_back({1, 0, flyTime, restTime, speed, flyTime, restTime});
  }
  int n = all.size();
  vi points(n, 0);

  for (int sec = 1; sec <= 2503; sec++) {
    int bestDist = 0;
    for (int d = 0; d < n; d++) {
      vi deer = all[d];
      if (deer[0]) { // flying
        deer[1] += deer[4];
        deer[2]--;
        if (deer[2] == 0) {
          deer[0] = 0; 
          deer[2] = deer[5];
          deer[3] = deer[6];
        }
      }
      else { // resting
        deer[3]--;
        if (deer[3] == 0) {
          deer[0] = 1;
          deer[2] = deer[5];
          deer[3] = deer[6];          
        }
      }
      bestDist = max(bestDist, deer[1]);
      all[d] = deer;
    }
    for (int d = 0; d < n; d++) {
      if (all[d][1] == bestDist) {
        points[d]++;
      }
    }
  }
  cout << *max_element(points.begin(), points.end()) << endl;
}
