#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int L, n;
int v[2001];
LL memo[2001][2001][3];

LL f(int f, int b, int cur) {
	if (f == b) {
		return 0;
	}

	LL &r = memo[f][b][cur];

	if (cur == 2) {

	}
	else if (cur == 0) {

	}
	else if (cur == 1) {
	}
	return r;
}

int main()
{

	cin >> L >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	if (n == 1) {
		cout << max(v[0], L-v[0]) << endl;
		exit(0);
	}
	memset(memo, -1, sizeof(memo));

	cout << f(0, n-1, 2) << endl;

	int f = 0, b = n-1, p = 0;
	LL d = 0;

	for (int i = 0; i < n; i++) {
		// walk to the next furthest tree from current position
		int df = p < v[f] ? v[f]-p : L-p+v[f];
		int db = p < v[b] ? p+L-v[b] : p-v[b];
		if (df > db) {
			d += df;
			p = v[f];
			f = (f+1)%n;
		}
		else {
			d += db;
			p = v[b];
			b = ((b-1)%n+n)%n;
		}
	}
	cout << d << endl;
	exit(0);
}

