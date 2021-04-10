#include <bits/stdc++.h>

//http://codeforces.com/contest/787/problem/B
using namespace std;

main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		bool match = false;
		unordered_set<int> q;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			q.insert(t);
		}
		for (auto z : q) {
			if (q.find(-z) != q.end()) {
				match = true;
				break;
			}
		}
		if (!match) {
			cout << "YES" << endl;
			exit(0);
		}
	}

	cout << "NO" << endl;

	exit(0);
}
