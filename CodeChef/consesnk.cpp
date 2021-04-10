//https://www.codechef.com/SNCKPA17/problems/CONSESNK
#include <bits/stdc++.h>

using namespace std;

#define llabs(a) ((a)<0?-(a):(a))

typedef long long LL;
bool debug = false;

LL calc(vector<LL> &v, LL start, LL A, LL B, LL L) {
	LL d = 0;
	for (int i = 0; i < v.size(); i++) {
		d += llabs(v[i]-(start+i*L));
	}
	return d;
}
int main()
{
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
		/*
		if ((B-N*L)-A < 4) { // brute force
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
			exit(0);
		}
		*/
		LL tot = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] < A) {
				tot += A-v[i];
				v[i] = A;
			}
			else if (v[i]+L > B) {
				tot += (v[i]+L)-B;
				v[i] = B-L;
			}
		}
		if (debug) { for (int i = 0;i < N; i++) { cout << v[i] << " "; } cout << endl; }
		LL best = 1LL<<62;
		LL m = N/2;
		vector<int> p;
		p.push_back(m);
		if (m-1 >= 0) p.push_back(m-1);
		if (m+1 < N) p.push_back(m+1);
		for (int k = 0; k < p.size(); k++) {
			m = p[k];
			LL left = v[m]-L*m;
			if (debug) { cout << "trying left = " << left << endl; cout << "calc = " << calc(v, left, A, B, L) << endl;}
			best = min(best, calc(v, left, A, B, L));
		}
		cout << tot+best << endl;

	}
	exit(0);
}

