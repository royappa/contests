//https://www.codechef.com/SNCKPA17/problems/TEAMFORM

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
		}
		cout << ((n-2*m)%2 == 0 ? "yes" : "no") << endl;
	}
	exit(0);
}

