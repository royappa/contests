//https://www.codechef.com/SNCKPA17/problems/CONSESNK
#include <bits/stdc++.h>

using namespace std;

#define llabs(a) ((a)<0?-(a):(a))

typedef long long LL;
bool debug = false;

int main(int argc, char *argv[0])
{
	if (argc > 1) {
		debug = true;
	}
	int T;
	cin >> T;
	while (T--) {
		LL N, L, A, B;
		cin >> N >> L >> A >> B;
		vector<LL> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		sort(v.begin(), v.end());
		LL best = 1LL<<62;
		for (LL left = A; left <= B-N*L; left++) {
			LL tot = 0;
			for (int i = 0; i < N; i++) {
				tot += llabs(v[i]-(left+i*L));
			}
			if (tot < best) {
				best = tot;
				if (debug) { cout << "next best = " << best << " at left = " << left << endl; }
			}
		}
		cout << best << endl;
	}
	exit(0);
}

