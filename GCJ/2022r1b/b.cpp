#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef long long LL;
int numC, numP;
vector<vector<int>> v;
LL best;

void f(int k, int last, LL total) {
  if (k == numC) {
    best = min(best, total);
    return;
  }
  do {
    LL p = last;
    LL ops = 0;
    for (int i = 0; i < numP; i++) {
      ops += abs(p - v[k][i]);
      p = v[k][i];
    }
    f(k+1, p, total + ops);
  } while (next_permutation(v[k].begin(), v[k].end()));
}

LL run() {
  scanf("%d%d", &numC, &numP);
  v.clear();
  best = 1LL << 60;
  for (int i = 0; i < numC; i++) {
    vector<int> prod(numP);
    for (int j = 0; j < numP; j++) {
      scanf("%d", &prod[j]);
    }
    sort(prod.begin(), prod.end());
    v.push_back(prod);
  }
  f(0, 0, 0);
  return best;
}
int main() {
	int NT;
  scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %lld\n", testCase+1, run());
	}
	return 0;
}
