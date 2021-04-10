#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef long long LL;

int best(vector<string> v) {
    int ops = 0;
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int L1 = v[i-1].size();
        int L2 = v[i].size();
        if (L1 < L2 || (L1 == L2 && v[i-1] < v[i])) {
            continue;
        }
        if (L1 == L2) {
            v[i] += '0';
            ops++;
            continue;
        }
        string pre = v[i-1].substr(0, L2);
        if (pre > v[i]) {
            v[i] += string(L1 - L2 + 1, '0');
            ops += L1 - L2 + 1;
            continue;
        }
        if (pre < v[i]) {
            v[i] += string(L1 - L2, '0');
            ops += L1 - L2;
            continue;
        }
        // v[i] is a proper prefix of v[i-1], so check the rest of v[i-1]
        string suff = v[i-1].substr(L2);
        bool allNines = true;
        for (int j = 0; j < suff.size(); j++) {
            if (suff[j] != '9') {
                allNines = false;
                break;
            }
        }
        if (allNines) {
            v[i] += string(L1 - L2 + 1, '0');
            ops += L1 - L2 + 1;
            continue;
        }
        ops += L1 - L2;
        v[i] = v[i-1];
        for (int j = L1-1; j >= L2; j--) {
            if (v[i-1][j] < '9') {
                v[i][j] = char(v[i-1][j] + 1);
                break;
            }
            else {
                v[i][j] = '0';
            }
        }
    }
//for (auto s: v) cout << s << endl; cout << "---" << endl;
    return ops;
}
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
        int res = best(v);
        cout << "Case #" << testCase+1 << ": " << res << endl;
	}
	return 0;
}
