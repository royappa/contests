#include <bits/stdc++.h>

//http://codeforces.com/contest/787/problem/0

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

LL gcd(LL x, LL y) { return y == 0 ? x : gcd(y, x%y); }
LL lcm(LL x, LL y) { return x/gcd(x,y)*y; }


main()
{
	LL a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;

	//b+n*a = d+m*c
	//
	//x = b (mod a)
	//x = d (mod c)

	LL m = (1LL<<60LL);

	if (gcd(a, c) != 1) {
		cout << -1 << endl;
	}
	else {
		for (LL x = 0; x <= a*c; x++) {
			if (x%a == b%a && x%c == d%c) {
				cout << x << endl;
				exit(0);
			}
		}
	}



	exit(0);
}
