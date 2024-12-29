#include <bits/stdc++.h>

using namespace std;
int debug = 0;

typedef pair<int,int> pii;

int chain() {
  int N;
  scanf("%d", &N);
  vector<int> fun(N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &fun[i]);
  }
  vector<int> next(N);
  vector<bool> noPrev(N, true);
  for (int i = 0; i < N; i++) {
    scanf("%d", &next[i]);
    next[i]--;
    if (next[i] != -1) {
      noPrev[next[i]] = false;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << i << " " << next[i] << " " << fun[i] << " " << noPrev[i] << endl;
  }
  set<pii> initiators;
  for (int i = 0; i < N; i++) {
    if (noPrev[i]) {
      initiators.insert({fun[i], i});
    }
  }
  int tot = 0;
  vector<bool> active(N, true);
  for (auto p : initiators) {
    int i = p.second; 
    int best = 0;
    cout << "starting at " << p.second+1 << endl;
    while (i != -1 && active[i]) {
      best = max(best, fun[i]);
      // cout << i << " " << fun[i] << " " << best << endl;
      active[i] = false;
      i = next[i];
    }
    tot += best;
  }
  return tot;
}

int main() {
	int NT;
  scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %d\n", testCase+1, chain());
	}
	return 0;
}
