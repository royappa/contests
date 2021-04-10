#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
	int N;
	cin >> N;
	LL p = 1;
	for (int i = 0; i < N; i++) {
		LL x;
		cin >> x;
		p = p/gcd(p, x)*x;
	}
	cout << p << endl;
	exit(0);
}
