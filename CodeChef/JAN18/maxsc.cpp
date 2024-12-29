#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		vector<vector<int>> v;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			vector<int> r(n);
			for (int j = 0; j < n; j++) {
				cin >> r[j];
			}
			sort(r.begin(), r.end());
			v.push_back(r);
		}

		int last = v[n-1][n-1];
		LL sum = last;
		bool can = true;
		for (int i = n-2; i >= 0; i--) {
			int j;
			for (j = n-1; j >= 0; j--) {
				if (v[i][j] < last) {
					last = v[i][j];
					sum += last;
					break;
				}
			}
			if (j == -1) {
				can = false;
				break;
			}
		}
		cout << (can ? sum : -1) << endl;
	}
}

