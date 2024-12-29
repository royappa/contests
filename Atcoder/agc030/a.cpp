#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{

	LL a, b, c;
	cin >> a >> b >> c;  // nasty antidote, tasty antidote, tasty poison

	LL r = 0;

	LL x = min(a, c);
	c -= x;
	r += x;
	if (c == 0) {
		r += b;
	}
	else {
		x = min(b, c);
		r += 2*x;
		c -= x;
		b -= x;
		if (b == 0 && c > 0) {
			r++;
		}
		else if (c == 0 && b > 0) {
			r += b;
		}
	}

	cout << r << endl;
	exit(0);
}

