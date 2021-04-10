#include <bits/stdc++.h>

using namespace std;

double memo[1<<12];
int done[1<<12];
int D, T;

double f(int m) {
	if (m == 0) return 0;	
	if (done[m]) return memo[m];
	int left = 0;
	for (int p = 0; p < T; p++) {
		if (m & (1<<p)) {
			left += p+1;
		}
	}
	double e = 0.0;
	map<int,int> sums;
	for (int i = 1; i <= D; i++) {
		for (int j = 1; j <= D; j++) {
			sums[i+j]++;
		}
	}
	for (auto z : sums) {
		int sumd = z.first;
		int sumcnt = z.second;
		double ek = -1;
		for (int k = 0; k < (1<<T); k++) {
			if ((m & k) != k) continue; // make sure the set of tokens "k" is available
			int sumk = 0;
			for (int p = 0; p < T; p++) {
				if (k & (1<<p)) {
					sumk += p+1;
				}
			}
			if (sumk == sumd) {
				if (ek == -1) ek = f(m & ~k);
				else ek = min(ek, f(m & ~k));	
			}
		}
		if (ek == -1) e += sumcnt*(1.0/(2*D))*left;
		else e += sumcnt*(1.0/(2*D))*ek;
	}
	memo[m] = e;
	done[m] = 1;
	return e;
}
class EmptyTheBox {
public:
double minExpectedPenalty(int D_, int T_) {
	D = D_;
	T = T_;
	double left = 0;
	while (T > 2*D) {
		left += T;
		T--;
	}
	
	memset(done, 0, sizeof(done));
	
	return f((1<<T)-1)+left;
}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!