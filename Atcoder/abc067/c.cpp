#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

LL llabs(LL x) { return x < 0 ? -x : x; }
int main()
{
	int N;
	cin >> N;
	vector<LL> v(N);
	vector<LL> a(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (i == 0) {
			a[i] = v[i];
		}
		else {
			a[i] = a[i-1]+v[i];
		}
	}
	LL m = 1LL<<60;
	for (int i = 0; i < N-1; i++) {
		LL x = a[i], y = a[N-1]-a[i];
		m = min(m, llabs(x-y));
	}
	cout << m;
	exit(0);
}
