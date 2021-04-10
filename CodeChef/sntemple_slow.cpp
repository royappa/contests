//https://www.codechef.com/SNCKPA17/problems/ISSNAKE

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

bool canBuild(vector<int> &v, int len) {
	int n = v.size();
	for (int i = 0; i+(2*len+1) <= n; i++) {
		bool ok = true;
		int p = i;
		for (int j = 1; j <= len+1; j++) {
			if (v[p++] < j) { ok = false; break; }
		}
		if (ok) {
			p = i+len;
			for (int j = len+1; j >= 1; j--) {
				if (v[p++] < j) { ok = false; break; }
			}
		}
		if (ok) return true;
	}
	return false;
}

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
		int lo = 0, hi = n+1;
		while (hi != lo+1) {
			int len = (lo+hi)/2;
			LL req = LL(len+1)*LL(len+1);
			if (2*len+1 <= n && req <= tot && canBuild(v, len)) {
				lo = len;
			}
			else {
				hi = len;
			}
		}
		LL x = lo;
		cout << tot-(x+1)*(x+1) << endl;
	}
	exit(0);
}

