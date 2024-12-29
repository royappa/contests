//https://www.codechef.com/SNCKQL17/problems/SNAKEEAT
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

void process(vector<LL> &v, vector<LL>& u, LL Q) {
	int n = v.size();
	int num = 0;
	auto good = lower_bound(v.begin(), v.end(), Q);
	if (good != v.end()) {
		num += v.end()-good;
		n = good-v.begin();
	}
	if (n > 1) {
		// find the leftmost p such that:
		// let k = n-p  (the number of snakes from p..n-1)
		// let req = Q*k-SUM(v[p..n-1])
		// Then we want   req <= p
		int lo = 0, hi = n; // neither satisfy the requirement
		bool found = false;
		while (hi != lo+1) {
			int p = (lo+hi)/2;
			LL k = n-p;
			LL req = Q*k-(u[p]-u[n]);
			if (req <= p) {
				found = true;
				hi = p;
			}
			else {
				lo = p;
			}
		}
		if (found) {
			int p = hi;
			num += n-p;
		}
	}
	cout << num << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, NQ;
		cin >> N >> NQ;
		vector<LL> L(N);
		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}
		sort(L.begin(), L.end());
		vector<LL> U(N, 0);
		U[N-1] = L[N-1];
		for (int i = N-2; i >= 0; i--) {
			U[i] = U[i+1]+L[i];
		}
		U.push_back(0);
		for (int i = 0; i < NQ; i++) {
			LL Q;
			cin >> Q;
			process(L, U, Q);
		}
	}
}

