#include <bits/stdc++.h>

//http://codeforces.com/contest/810/problem/C

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

#define MOD 1000000007

// stupid quadratic solution for practice
main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	vector<int> p2(n+1);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	p2[0] = 1;
	for (int i = 1; i <= n; i++) {
		p2[i] = 2*p2[i-1]%MOD;
	}
	sort(v.begin(), v.end());
	LL tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			tot += p2[j-i-1]*(v[j]-v[i])%MOD;
			tot %= MOD;
		}
	}
	cout << tot << endl;
	exit(0);
}
