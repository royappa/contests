#include <bits/stdc++.h>

using namespace std;
int debug = 0;
typedef unsigned long long LL;
typedef pair<LL,LL> pLL;

// Pi < 500
// Sum(Ni) <= 100
// So Sum of left <= 500*100 = 50000
// for each prod = 50000

vector<pLL> uniquePrimeFactorization(LL n)  
{
	LL s = LL(ceil(sqrt(double(n))))+1;
	vector<LL> sieve(s, 1);
	for (LL i = 2; i < s; i++)
	{
		if (sieve[i])
		{
			LL q = i*i;
			while (q < s && sieve[q])
			{
				q += i;
			}
		}
	}
	// now "sieve" will tell us all primes up to sqrt(n)
	vector<pLL> res;
	for (LL p = 2; p < s; p++)
	{
		if (sieve[p] && n % p == 0) // p is prime divisor of n
		{
			int pe = 0;
			while (n % p == 0)
			{
				n /= p;
				pe++;
			}
			res.push_back(make_pair(p, pe));
		}
	}
	if (n > 1) // there could be one prime left that is larger than sqrt(n)
	{
		res.push_back(make_pair(n, 1));
	}
	return res;
}

LL best(map<LL, LL> v) {
    map<LL, LL> vcopy = v;
    for (LL prod = 50000; prod >= 2; prod--) {
        v = vcopy;
        bool ok = true;
        vector<pLL> pes = uniquePrimeFactorization(prod);
        for (auto pe: pes) {
            if (v[pe.first] < pe.second) {
                ok = false;
                break;
            }
            v[pe.first] -= pe.second;
        }
        if (!ok) continue;
        LL sum = 0;
        for (auto p: v) {
            sum += p.first * p.second;
        }
        if (sum == prod) {
            return sum;
        }
    }
    return 0;
}
int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		int M;
        cin >> M;
        map<LL, LL> v;
        for (int i = 0; i < M; i++) {
            LL P, N;
            cin >> P >> N;
            v[P] = N;
        }
        LL res = best(v);
        cout << "Case #" << testCase+1 << ": " << res << endl;
	}
	return 0;
}
