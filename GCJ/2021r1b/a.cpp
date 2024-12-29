#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef long long LL;

bool valid(LL ht, LL mt, LL st, LL &hh, LL &mm, LL &ss, LL &nn) {
    // check if ht is a valid # of hours ticks
    // check if mt if a valid # of minutes ticks
    // check if st is a valid # of seconds ticks
    // hours rotates 1 tick every nanosecond
    // 1 tick = (1/12) * 10^-10 degree
    // 10^-10 degrees = 12 ticks
    // 1 degree = 12 * 10^10 ticks
    // 1 hour = 30 degrees
    LL ticksPerDegree = 12LL * 10e10;

    for (LL t = 0; t < 1000000000LL; t++) {
        
    }
    hh = mm = ss = nn = 1;
    return false;
}
void solve(LL a, LL b, LL c) {
    vector<LL> w = {a, b, c};
    vector<int> v = {0, 1, 2};
    sort(v.begin(), v.end());
    do {
        LL h, m, s, n;
        if (valid(w[v[0]], w[v[1]], w[v[2]], h, m, s, n)) {
            cout << h << " " << m << " " << s << " " << n;
            return;
        }
    } while (next_permutation(v.begin(), v.end()));
}

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
        LL a, b, c;
        cin >> a >> b >> c;

        cout << "Case #" << testCase+1 << ": ";
        solve(a, b, c);
        cout << endl;
	}
	return 0;
}
