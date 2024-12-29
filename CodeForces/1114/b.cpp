#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, m, k;
	vector<LL> v(n);
	for (int i = 0; i < n; i++ {
		cin >> v[i];
	}
	vector<LL> w = v;
	sort(w.rbegin(), w.rend());
	LL sum = accumulate(w.begin(), w.begin()+m, 0LL);

	exit(0);
}

