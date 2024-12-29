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
	cin >> T;
	while (T--) {
		int p, q, r;
		cin >> p >> q >> r;

		for (int i = 0; i < p; i++) {
			cin >> x[i];
		}
		for (int i = 0; i < q; i++) {
			cin >> y[i];
		}
		for (int i = 0; i < r; i++) {
			cin >> z[i];
		}
		sort(x, x+p);
		sort
		sort(z, z+r);
		sum(x, xs, p);
		sum(z, zs, r);
		int tot = 0;
		int lx = 0, lz = 0;
		for (int i = 0; i < q; i++) {
			int yy = y[i];
			int pp = upper_bound(x+lx, x+p, yy)-x;
			int rr = upper_bound(z+lz, z+r, yy)-z;
			if (pp == 0 || rr == 0) continue;
			lx = pp;
			lz = rr;
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

			/*
			LL tot1 = 0;
			for (int i = 0; i < pp; i++) {
				for (int j = 0; j < rr; j++) {
					printf("(%d+%d)*(%d+%d) = %d\n", x[i], yy, yy, z[j], (x[i]+yy)*(yy+z[j]));
					tot1 += (x[i]+yy)*(yy+z[j]);
				}
			}
			cout << " sub = " << tot1 << endl;
			tot += tot1;
			*/
		}
		cout << tot << endl;
	}
	exit(0);
}

