#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define MOD 1000000007


string S;
string T;


bool isSubstring() {
	int n = T.size(), m = S.size();
	int p = 0, q = 0;
	while (p < n) {
		while (q < m && S[q] != T[p]) {
			q++;
		}
		if (S[q] == T[p]) {
			p++;
			q++;
		}
		if (q >= m) break;
	}
	return p == n;
}
int main()
{
	cin >> S;
	T = "a";
	while (isSubstring()) {
		int n = T.size();
		for (int p = n-1; p >= 0; p--) {
			if (T[p] < 'z') {
				T[p]++;
				for (int i = p+1; i < n; i++) {
					T[i] = 'a';
				}
				break;
			}
		}
		if (T == string(n, 'z')) {
			T = string(n+1, 'a');
		}
	}
	cout << T << endl;
	exit(0);
}
