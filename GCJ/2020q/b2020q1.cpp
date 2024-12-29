#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int A[100][100];

vector<string> split(string s) {
    vector<string> r;
    string cur = s[0];
    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i-1]) {
            r.push_back(cur);
            cur = s[i];
        }
    }
    r.push_back(cur);
    return r;
}
int main() {
	int NT;
	cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
        string s;
        cin >> s;
        string res = "";
        vector<string> v = split(s);

		printf("Case #%d: %s\n", testCase+1, res.c_str());
	}
	return 0;
}
