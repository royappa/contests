#include <bits/stdc++.h>

using namespace std;
int debug = 0;

bool some_patterns_left(vector<string> &v, vector<int> &p) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        int k = v[i].size();
        if (p[i] < k && (p[i] < k-1 || p[i] != '*') {
            return true;
        }
    }
    return false;
}

void compress(vector<string> &v) {
    int n = v.size();
    for (int i = 0; i < n; i++) {
        string s = v[i];
        int k = s.size();
        for (int j = k-1; j >= 1; j--) {
            if (s[j] == '*' && s[j-1] == '*') {
                s.erase(s.begin()+j);
            }
        }
        v[i] = s;
    }
}
string f(vector<string> v) {
    int n = v.size();
    string res = "";
    vector<int> p(n, 0);
    compress(v);
    while (some_patterns_left(v, p)) {
        char c = 
    }
    if (res.size() > 10000) return "*";
    return res;
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

		printf("Case #%d: %s\n", testCase+1, f(v).c_str());
	}
	return 0;
}
