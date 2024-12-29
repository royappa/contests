#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		int N;
		cin >> N;
        vector<string> v(N);
        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

		printf("Case #%d: %s\n", testCase+1, f(v).c_str());
	}
	return 0;
}
