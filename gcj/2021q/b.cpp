#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int cost(vector<int> v) {
    int n = v.size();
    int c = 0;
    for (int i = 0; i < n-1; i++) {
        int mp = i;
        for (int j = i; j < n; j++) {
            if (v[j] < v[mp]) {
                mp = j;
            }
        }
        reverse(v.begin()+i, v.begin()+(mp+1));
        c += mp - i + 1;
    }
    return c;
}
int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
        int N, C;
        cin >> N >> C;
        vector<int> v(N);
        for (int i = 0; i < N; i++) {
            v[i] = i+1;
        }
        bool can = false;
        do {
            if (cost(v) == C) {
                can = true;
                break;
            }
        } while (next_permutation(v.begin(), v.end()));
        if (can) {
		    printf("Case #%d:", testCase+1);
            for (int i = 0; i < N; i++) {
                printf(" %d", v[i]);
            }
            printf("\n");
        }
        else {
            printf("Case #%d: IMPOSSIBLE\n", testCase+1);
        }
	}
	return 0;
}
