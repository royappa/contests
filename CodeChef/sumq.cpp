#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
const int MOD = 1000000007;

int x[100000], xs[100000], y[100000], z[100000], zs[100000];

void sum(int x[], int xs[], int n) {
	xs[0] = x[0];
	for (int i = 1; i < n; i++) {
		xs[i] = (x[i] + xs[i-1])%MOD;
	}
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int p, q, r;
		scanf("%d%d%d", &p, &q, &r);

		for (int i = 0; i < p; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < q; i++) {
			scanf("%d", &y[i]);
		}
		for (int i = 0; i < r; i++) {
			scanf("%d", &z[i]);
		}
		sort(x, x+p);
		sort(y, y+q);
		sort(z, z+r);
		sum(x, xs, p);
		sum(z, zs, r);
		int tot = 0;

		int i = 0;
		int pp = 0, rr = 0;
		while (i < q) {
			int yy = y[i++];
			while (pp < p && x[pp] <= yy) pp++;
			while (rr < r && z[rr] <= yy) rr++;
			if (pp == 0 || rr == 0) {
				continue;
			}
			LL xsp = xs[pp-1];
			LL zsr = zs[rr-1];
			//tot = (tot + yy*xsp*rr)%MOD;
			LL u = LL(yy)*xsp%MOD; u *= rr; u %= MOD;
			tot += u; tot %= MOD;

			//tot = (tot + yy*yy*(pp*rr))%MOD;
			u = LL(yy)*yy%MOD; u *= pp; u %= MOD; u *= rr; u %= MOD;
			tot += u; tot %= MOD;

			//tot = (tot + yy*zsr*pp)%MOD;
			u = LL(yy)*zsr%MOD; u *= pp; u %= MOD;
			tot += u; tot %= MOD;

			//tot = (tot + xsp*zsr)%MOD;
			u = LL(xsp)*zsr%MOD;
			tot += u; tot %= MOD;
		}
		cout << tot << endl;
	}
	exit(0);
}

