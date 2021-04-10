#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
// ACKNOWLEDGEMENT: segment tree code is from http://codeforces.com/blog/entry/18051

const int N = 100000+10;  // limit for array size
int n;  // array size
LL t[2 * N];
LL a[N];
LL t2[N];

LL maxll(LL x, LL y) { return x > y ? x : y; }


void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = maxll(t[i<<1], t[i<<1|1]);
}

LL query(int l, int r) {  // sum on interval [l, r)
  LL res = -(1LL<<62);
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = maxll(res, t[l++]);
    if (r&1) res = maxll(res, t[--r]);
  }
  return res;
}

int main()
{
	LL p, q, r;

	cin >> n >> p >> q >> r;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
		t[n+i] = p*a[i];
	}
	build(); // segtree of all the p*ai values

	for (int i = 0; i < n; i++) {
		LL m = query(0, i+1);
		t2[i] = m+q*a[i];
	}
	for (int i = 0; i < n; i++) {
		t[n+i] = t2[i];
	}
	build(); // segtree of all the p*ai+q*aj values

	for (int i = 0; i < n; i++) {
		LL m = query(0, i+1);
		t2[i] = m+r*a[i];
	}
	for (int i = 0; i < n; i++) {
		t[n+i] = t2[i];
	}
	build(); // segtree of all the p*ai+q*aj+r*ak values
	cout << query(0, n) << endl;
	exit(0);
}
