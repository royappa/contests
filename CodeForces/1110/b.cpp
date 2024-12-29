#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MAXLEN=1000000000+7;

bool can(vector<int> &v, int a, int b, int k, int L) { // can we use no more than k sticks of total length L?
	if (a == b) {
		return L >= 1;
	}
	if (k == 1) {
		return v[b]-v[a]+1 <= L; // use one long tape
	}
	if (v[b]-v[a]+1 <= L) {
		return true;
	}
	if (L <= 0) {
		return false;
	}
	// k > 1, b-a+1 > 1, and we need to use more than one tape
	int best = MAXLEN;
	for (int i = a; i <= b; i++) {

	}
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++ {
		cin >> v[i];
	}
	int lo = 0, hi = MAXLEN;
	while (lo+1 != hi) {
		int mid = lo+(hi-lo)/2;
		if (can(v, 0, n-1, k, mid)) {
			mid = hi;
		}
		else {
			mid = lo;
		}
	}
	cout << hi << endl;
	exit(0);
}

