//https://www.codechef.com/SNCKPB17/problems/SNELECT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		if (n <= 2) {
			for (int i = 1; i <= n; i++) {
				cout << i;
				if (i < n) cout << " ";
			}
			cout << endl;
			continue;
		}
		set<int> s, sums;
		s.insert(1);
		s.insert(2);
		for (int i = 3; i <= 500; i++) {
			bool bad = false;
			for (auto x : s) {
				for (auto y : s) {
					if (x == y) continue;
					if (x+y == i || x+i == y || y+i == x) {
						bad = true;
						goto out;
					}
				}
			}
			out: if (!bad)
				s.insert(i);
			if (s.size() == n) break;
		}
		for (auto x : s) {
			cout << x << " ";
		}
		cout << endl;
	}
	exit(0);
}

