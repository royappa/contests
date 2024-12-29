#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
	int N;
	cin >> N;
	LL x;
	cin >> x;
	for (int i = 1; i < N; i++) {
		LL y;
		cin >> y;
		x = gcd(x, y);
	}
	cout << x << endl;
	exit(0);
}
