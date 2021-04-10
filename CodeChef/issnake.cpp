//https://www.codechef.com/SNCKPA17/problems/ISSNAKE

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

bool snake(vector<string> v, int r, int c, int n) {
	if (debug) { cout << "START:" << r << " " << c << " " << endl; cout << v[0] << endl << v[1] << endl; }

	bool ok = true;
	while (ok) {
		v[r][c] = 'X';
		if (debug) { cout << v[0] << endl << v[1] << endl; }
		if (c+1 == n) {
			break;
		}
		int other = 1-r;
		if (v[other][c] == '#') {
			r = other;
			continue;
		}
		// check right
		if (v[r][c+1] == '#') {
			c = c+1;
			continue;
		}
		else {
			for (int j = c+1; j < n; j++) {
				if (v[0][j] == '#' || v[1][j] == '#') {
					ok = false;
					break;
				}
			}
			break;
		}
	}
	return ok;
}
int main()
{
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		vector<string> v(2);
		cin >> v[0];
		cin >> v[1];
		int c = 0;
		for (int j = 0; j < n; j++) {
			if (v[0][j] == '#' || v[1][j] == '#') {
				c = j;
				break;
			}
		}
		bool good = false;
		if (v[0][c] == '#') {
			good = good || snake(v, 0, c, n);
		}
		if (v[1][c] == '#') {
			good = good || snake(v, 1, c, n);
		}
		cout << (good ? "yes" : "no") << endl;
	}
	exit(0);
}

