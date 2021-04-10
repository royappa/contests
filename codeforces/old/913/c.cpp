#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pLL;
bool lessThan(pLL a, pLL b) {
	if ((a.second*b.first) != (b.second*a.first))
		return (a.second*b.first) <(b.second*a.first);
	else
		return a.first < b.first;
}

vector<pLL> c;
int n;

bool canBuy(LL L, LL r) { // can we buy L liters for r rubles
	while (r > 0) {
		bool bought = false;
		for (int i = 0; i < n; i++) {
			if (r >= c[i].second) {
				bought = true;
				LL bottles = r/LL(c[i].second);
				L -= bottles*LL(c[i].first);
				r -= LL(c[i].second)*bottles;
			}
		}
		if (L <= 0) break;
		if (!bought) break;
	}
	return L <= 0;
}

int main()
{
	int L;
	cin >> n >> L;
	c.resize(n);

	for (int i = 0; i < n; i++) {
		LL cost;
		cin >> cost;
		c[i] = make_pair(1LL<<i, cost);
	}
	sort(c.rbegin(), c.rend(), lessThan); // sort by roubles/liter
	LL lo = 0, hi=1LL<<62; // we cannot buy for lo rubles, can buy for hi rubles
	while (hi != lo+1) {
		LL mid = lo+(hi-lo)/2LL;
		if (canBuy(L, mid)) {
			hi = mid;
		}
		else {
			lo = mid;
		}
	}
	cout << hi << endl;
	exit(0);
}
