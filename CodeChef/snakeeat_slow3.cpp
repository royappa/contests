//https://www.codechef.com/SNCKQL17/problems/SNAKEEAT
#include <bits/stdc++.h>

using namespace std;


void process(vector<int> &v, unordered_map<int,int>& u, int Q) {
	int n = v.size();
	int num = 0;
	auto good = lower_bound(v.begin(), v.end(), Q);
	if (good != v.end()) {
		num += v.end()-good;
		n = good-v.begin();
	}
	int p = 0;
	while (n > 0) {
		int req = Q-v[n-1];
		if (n-p-1 < req)
			break;
 		int t = u[v[n-1]];
		int k = n-t;
		int r = min((n-p)/(req+1), k);
		num += r;
		p += r*req;
		n -= r;
		if (r < k)
			break;
	}
	cout << num << endl;
}

// best version so far.. O(NQ*sqrt(N)) (for all NQ test cases)
int main()
{
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, NQ;
		cin >> N >> NQ;
		vector<int> L(N);
		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}
		sort(L.begin(), L.end());
		unordered_map<int,int> U;
		U[L[0]] = 0;
		for (int i = 1; i < N; i++) {
			if (L[i] != L[i-1]) {
				U[L[i]] = i;
			}
		}
		for (int i = 0; i < NQ; i++) {
			int Q;
			cin >> Q;
			process(L, U, Q);
		}
	}
}

