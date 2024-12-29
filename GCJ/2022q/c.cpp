#include <bits/stdc++.h>

using namespace std;
int debug = 0;


void ink() {
  const int MIL = 1000000;
  vector<vector<int>> v(3, vector<int>(4, 0));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      scanf("%d", &v[i][j]);
    }
  }
  vector<int> w(4, MIL+1);
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 3; j++) {
      w[i] = min(w[i], v[j][i]);
    }
  }
  int sum = accumulate(w.begin(), w.end(), 0);
  if (sum < MIL) {
    printf("IMPOSSIBLE\n");
    return;
  }
  int tot = 0;
  int p;
  for (p = 0; p < 4; p++) {
    if (tot + w[p] >= MIL) {
      w[p] = MIL - tot;
      break;
    }
    else {
      tot += w[p];
    }
  }
  for (int i = 0; i < 4; i++) {
    printf("%d ", i <= p ? w[i] : 0);
  }
  printf("\n");

}

int main() {
	int NT;
  scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: ", testCase+1);
    ink();
	}
	return 0;
}
