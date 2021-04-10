#include <bits/stdc++.h>

using namespace std;

// Reference: https://en.wikipedia.org/wiki/Digital_root
// dr(a*b) = dr(dr(a)*dr(b))

// dr(a^n) = dr(a^n/2*a^n/2) = dr(dr(a^n/2)*dr(a^n/2))
// dr2(a,n) = dr(dr2(a,n/2)*dr2(a,n/2))


typedef long long LL;

int dr(LL x) {
	if (x < 10) {
		return x;
	}
	int sum = 0;
	while (x > 0) {
		sum += x%10;
		x /= 10;
	}
	return dr(sum);
}

int dr2(LL a, LL n) {
	if (n == 1) {
		return dr(a);
	}
	if (n%2 == 0) {
		return dr(dr2(a, n/2)*dr2(a, n/2));
	}
	else {
		return dr(dr2(a, n/2)*dr2(a, n/2)*dr(a));
	}
}

int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		LL a, n;
		cin >> a >> n;
		cout << dr2(a, n) << endl;
	}
}

