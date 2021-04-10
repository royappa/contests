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
		vector<string> v(2);
		cin >> v[0] >> v[1];
		vector<int> cols;
		int t = 0, b = 0;
		for (int j = 0; j < n; j++) {
			int tt = v[0][j] == '*';
			int bb = v[1][j] == '*';
			if (t+tt == 2 || b+bb == 2) {
				cols.push_back(j);
				t = tt;
				b = bb;
			}
			else {
				t += tt;
				b += bb;
			}
		}
		cols.push_back(n);
		int hor = 0;
		int last = 0;
		for (int i = 0; i < cols.size(); i++) {
			int m = cols[i];
			int tot = 0;
			for (int j = last; j < m; j++) {
				tot += (v[0][j] == '*') + (v[1][j] == '*');
			}
			if (tot > 1) {
				hor = 1;
				break;
			}
			last = m;
		}
		cout << hor+cols.size()-1 << endl;
	}
	exit(0);
}

