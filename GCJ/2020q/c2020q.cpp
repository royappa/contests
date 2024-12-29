#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int main() {
	int NT;
	cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
        int N;
        vector<pair<pair<int,int>,int>> v;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int s, e;
            cin >> s >> e;
            v.push_back({{s,e},i});
        }
        sort(v.begin(), v.end());
        vector<int> r(N);
        vector<int> f(2);
        f[0] = 0;
        f[1] = 0;
        bool can = true;
        for (int i = 0; i < N; i++) {
            int s = v[i].first.first, e = v[i].first.second;
            int p = v[i].second;
            if (f[0] > s && f[1] > s) {
                can = false;
                break;
            }
            else if (f[0] <= s && f[1] <= s) {
                r[p] = 0;
                f[0] = e;
            }
            else if (f[0] > s) {
                r[p] = 1;
                f[1] = e;
            }
            else {
                r[p] = 0;
                f[0] = e;
            }
        }
        if (can) {
            string res = "";
            for (int i = 0; i < N; i++) {
                res += "CJ"[r[i]];
            }
            printf("Case #%d: %s\n", testCase+1, res.c_str());
        }
        else {
            printf("Case #%d: IMPOSSIBLE\n", testCase+1);
        }
	}
	return 0;
}
