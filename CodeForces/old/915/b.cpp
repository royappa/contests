#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, pos, L, R;
	cin >> n >> pos >> L >> R;

	if (pos < L) {
		int t = L-pos;
		t++;
		if (R < n) {
			t += R-L;
			t++;
		}
		cout << t << endl;
	}
	else if (pos > R) {
		int t = pos-R;
		t++;
		if (L > 1) {
			t += R-L;
			t++;
		}
		cout << t << endl;
	}
	else {
		int t = 0;
		if (L > 1) {
			t += pos-L;
			t++;
			pos = L;
		}
		if (R < n) {
			t += R-pos;
			t++;
		}
		cout << t << endL;
	}
	exit(0);
}
