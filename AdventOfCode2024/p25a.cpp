#include <bits/stdc++.h>
#include <fstream>

using namespace std;
typedef long long LL;
int debug = 0;

typedef vector<string> vs;
typedef vector<vs> vvs;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main(int argc, char *argv[])
{    
  if (argc > 1) debug = atoi(argv[1]);
 
  string line;
  vvi locks, keys;
  do {
    vvs cur;
    vi hts(5, 0);
    bool lock = true;
    for (int i = 0; i < 7; i++) {
      getline(cin, line);
      if (i == 0) lock = line == "#####";
      for (int j = 0; j < 5; j++) {
        hts[j] += line[j] == '#';
      }
    }
    for (int j = 0; j < 5; j++) {
      hts[j]--;
    }
    if (lock) {
      locks.push_back(hts);
    }
    else {
      keys.push_back(hts);
    }
  } while (getline(cin, line));
  cout << "Locks " << locks.size() << endl;
  for (auto v : locks) {
    for (auto h : v) { cout << h << ","; }
    cout << endl;
  }
  cout << "Keys " << keys.size() << endl;
  for (auto v : keys) {
    for (auto h : v) { cout << h << ","; }
    cout << endl;
  }
  int num = 0;
  for (auto lv : locks) {
    for (auto kv : keys) {
      bool can = true;
      for (int i = 0; i < 5; i++) {
        if (lv[i]+kv[i] > 5) can = false;
      }
      if (can) num++;
    }
  }
  cout << num << endl;
}

