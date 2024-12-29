#include <bits/stdc++.h>

using namespace std;
int debug = 0;

string high() {
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) return s;
    string r = "";
    r += s[n-1];
    for (int i = n-2; i >= 0; i--) {
        string rr = string("") + s[i] + s[i] + r;
        if (rr < r) {
            r = rr;
        }
        else {
            r = string("") + s[i] + r;
        }
    }
    return r;
}

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %s\n", testCase+1, high().c_str());
	}
	return 0;
}
