#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<LL> b(n/2);
	for (int i = 0; i < n/2; i++) {
		cin >> b[i];
	}
	vector<LL> a(n);
	a[0] = 0;
	a[n-1] = b[0];
	for (int i = 1; i < n/2; i++) {
		a[i] = a[i-1];
		a[n-i-1] = b[i]-a[i];
		if (a[n-i-1] > a[n-i]) {
			int d = a[n-i-1]-a[n-i];
			a[n-i-1] -= d;
			a[i] += d;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << (i > 0 ? " " : "") << a[i];
	}
	cout << endl;
	exit(0);
}
