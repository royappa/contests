#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int dice() {
    int N;

    scanf("%d", &N);
    
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    int best = 1;
    for (int i = 1; i < N; i++) {
      if (v[i] > best) {
        best++;
      }
    }
    return best;
}

int main() {
	int NT;
  scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %d\n", testCase+1, dice());
	}
	return 0;
}
