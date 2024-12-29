#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	LL p, y;
	cin >> p >> y;

	for (LL q = p+1; q <= y; q++) {
		LL d = 2;
		bool isPrime = true;
		while (d*d <= q) {
			if (q%d == 0) {
				isPrime = false;
				break;
			}
			d++;
		}
		if (isPrime) {
			cout << q << endl;
		}
	}
	cout << -1 << endl;

	exit(0);
}
