#include <bits/stdc++.h>

using namespace std;
int debug = 0;
int n;
vector<int> v;
vector<int> lm, rm;

int best() {
    scanf("%d", &n);
    v.resize(n);
    lm.resize(n);
    rm.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    lm[0] = v[0];
    for (int i = 1; i < n; i++) {
      lm[i] = max(lm[i-1], v[i]);
    }
    rm[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
      rm[i] = max(rm[i+1], v[i]);
    }
    int num = n;
    for (int i = 0; i < n; i++) {
      if (v[i] < lm[i] && v[i] < rm[i]) {
        num--;
      }
    }
    return num; 
}
int main() {
	int NT;
    scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %d\n", testCase+1, best());
	}
	return 0;
}
