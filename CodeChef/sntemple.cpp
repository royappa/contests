//https://www.codechef.com/SNCKPA17/problems/ISSNAKE

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
		LL tot = 0;
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			cin >> v[i];
			tot += LL(v[i]);
		}
		if (debug) { for (int i = 0; i < n; i++) { cout << v[i] << " "; } cout << endl; }
		vector<int> inc(n), rev(n);
		inc[0] = 1;
		int cur = 1;
		for (int i = 1; i < n; i++) {
			if (v[i] > cur) {
				cur++;
				inc[i] = cur;
			}
			else if (v[i] == cur) {
				inc[i] = cur;
			}
			else {
				inc[i] = v[i];
				cur = v[i];
			}
		}
		rev[n-1] = 1;
		cur = 1;
		for (int i = n-2; i >= 0; i--) {
			if (v[i] > cur) {
				cur++;
				rev[i] = cur;
			}
			else if (v[i] == cur) {
				rev[i] = cur;
			}
			else {
				rev[i] = v[i];
				cur = v[i];
			}
		}
		if (debug) { for (int i = 0; i < n; i++) { cout << inc[i] << " "; } cout << endl; }
		if (debug) { for (int i = 0; i < n; i++) { cout << rev[i] << " "; } cout << endl; }

		LL x = 1;
		for (int i = 0; i < n; i++) {
			x = max(x, LL(min(rev[i],inc[i])));
		}
		x--;
		cout << tot-(x+1)*(x+1) << endl;
	}
	exit(0);
}

