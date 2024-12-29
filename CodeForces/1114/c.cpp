#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<LL,LL> pLL;
// prime factorization based on: https://www.geeksforgeeks.org/print-all-prime-factors-of-a-given-number/
vector<pLL> primeFactors(LL n)
{
    LL p = 0;
    while (n%2 == 0)
    {
        p++;
        n /= 2;
    }
  	vector<pLL> res;
  	if (p) res.push_back({2, p});

    for (LL i = 3; i*i <= n; i += 2) {
        p = 0;
        while (n%i == 0) {
			p++;
            n /= i;
        }
        if (p) {
			res.push_back({i, p});
		}
    }

    if (n > 2) {
		res.push_back({n, 1});
	}
	return res;
}

LL f(LL b, vector<pLL> &v, LL n) {
	LL best = 1LL<<60;
	for (int i = 0; i < v.size(); i++) {
		pLL x = v[i];
		LL p = x.first, e = x.second;
		LL t = 0;
		LL d = p;
		LL N = n;
		while (N > 0) {
			t += N/p;
			N /= p;
		}
		t /= e;
		best = min(best, t);
	}
	return best;
}

int main()
{
	LL n, b;
	cin >> n >> b;
	vector<pLL> v = primeFactors(b);
	cout << f(b, v, n) << endl;
	exit(0);
}

