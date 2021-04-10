#include <bits/stdc++.h>

//http://codeforces.com/contest/811/problem/B

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

main()
{
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<int> orig = p;
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		sort(p.begin()+l-1, p.begin()+r);
		cout << (p[x] == orig[x] ? "Yes" : "No") << endl;
		p = orig;
	}
	exit(0);
}
