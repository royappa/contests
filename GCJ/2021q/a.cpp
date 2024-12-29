#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int cost() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
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
		int c = cost();
		printf("Case #%d: %d\n", testCase+1, c);
	}
	return 0;
}
