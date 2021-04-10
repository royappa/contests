#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = true;

#define MOD 1000000007LL
int v[100000+1];

int p[100000+1];

int main()
{
	p[0] = 1;
	for (int i = 1; i <= 100000; i++) {
		p[i] = 2*p[i-1]%MOD;
	}
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (n == 1) {
			cout << v[0] << endl;
			continue;
		}
		LL tot = 0;
		for (int i = 0; i < n; i++) {
			LL prd = 1, sum = 0;
			for (int len = 1; i+len <= n; len++) {
				sum = (sum+v[i+len-1])%MOD;
				prd = (prd*v[i+len-1])%MOD;
				int ops = len-1;
				int otherOps = (n-1)-ops;
				tot = (tot + (p[otherOps]*sum)%MOD)%MOD;
				tot = (tot + (p[otherOps]*prd)%MOD)%MOD;
			}
		}
		cout << tot << endl;
	}
	exit(0);
}

