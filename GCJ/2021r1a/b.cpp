#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef long long LL;

LL best(vector<int> v) {
    int n = v.size();
    LL res = 0;
    for (int m = 1; m < (1<<n); m++) {
        LL sum = 0, prod = 1;
        for (int i = 0; i < n; i++) {
            if (m & (1 << i)) {
                sum += v[i];
            }
            else {
                prod *= v[i];
            }
        }
        if (sum == prod) {
            res = max(res, sum);
        }
    }
    return res;
}
int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		int M;
        cin >> M;
        vector<int> v;
        for (int i = 0; i < M; i++) {
            int P, N;
            cin >> P >> N;
            for (int i = 0; i < N; i++) {
                v.push_back(P);
            }
        }
		printf("Case #%d: %lld\n", testCase+1, best(v));
	}
	return 0;
}
