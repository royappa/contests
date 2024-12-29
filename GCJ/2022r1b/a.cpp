#include <bits/stdc++.h>

using namespace std;
int debug = 0;
int n;
vector<int> v(101);
int memo[101][101];

int f(int left, int right) {
    int m = 0;
    if (left > 0) {
         m = *max_element(v.begin(), v.begin()+left);
    }
    if (right < n-1) {
        m = max(m, *max_element(v.begin()+(right+1), v.end()));
    }
    
    if (left == right) {
        if (debug) printf("f(%d,%d), m = %d, result = %d\n", left, right, m, v[left] >= m ? 1 : 0);

        return v[left] >= m ? 1 : 0;
    }
    int& r = memo[left][right];
    if (r != -1) {
        return r;
    }
    int ifLeft = (v[left] >= m ? 1 : 0) + f(left+1, right);
    int ifRight = (v[right] >= m ? 1 : 0) + f(left, right-1);
    r = max(ifLeft, ifRight);
    if (debug) printf("f(%d,%d): ifLeft = %d, ifRight = %d, m = %d, result = %d\n", left, right, ifLeft, ifRight, m, r);
    return r;
}

int best() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    if (n == 1) {
        return 1;
    }
    memset(memo, -1, sizeof(memo));
    return f(0, n-1);
}
int main() {
	int NT;
    scanf("%d", &NT);
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %d\n", testCase+1, best());
	}
	return 0;
}
