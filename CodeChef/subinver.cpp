//https://www.codechef.com/LTIME48/problems/SUBINVER

#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long LL;

int bit(LL x, int p) {
	return (x&(1LL<<p)) ? 1 : 0;
}

void stringify(vector<LL> &w, int N) {
	for (int i = 0; i < N; i++) {
		cout << bit(w[i/64], i%64);
	}
	cout << endl;
}

bool bigger(vector<LL> &a, vector<LL> &b, int N) {
	for (int i = 0; i < (N+63)/64; i += 64) {
		LL m = 1;
		if ((m-a[i/64]) > (m-b[i/64]))
			return true;
	}
	return false;
}
// rubbish solution
int main()
{
	int N, U;
	cin >> N >> U;
	vector<LL> v((N+63)/64, 0LL);
	vector<LL> best = v;

	for (int i = 0; i < U; i++) {
		int L, R;
		cin >> L >> R;
		L--; R--;
		int p = L;
		while (p <= R && (p == 0 || p%64 != 0)) {
			int q = p%64;
			v[p/64] ^= (1LL<<q);
			p++;
		}
		while (p < R) {
			v[p/64] = ~v[p/64];
			p += 64;
		}
		if (bigger(v, best, N)) {
			best = v;
		}
		//stringify(v, N);
	}
	stringify(best, N);
	exit(0);
}

