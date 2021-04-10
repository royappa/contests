#include <bits/stdc++.h>

//https://www.codechef.com/ALKH2017/problems/XORPRO

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

#define MAXINT (1LL<<60)
#define llabs(a) ((a)<0?-(a):(a))

main()
{
	LL T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		vector<LL> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		LL z = v[0];
		for (int i = 1; i < N; i++) {
			z ^= v[i];
		}
		// what is the min cost to make z=0?
		LL best = MAXINT;
		for (int i = 0; i < N; i++) {
			LL x = v[i];
			LL y = z ^ x; // y is z without x
			best = min(best, llabs(x-y));
		}
		cout << best << endl;
	}

	exit(0);
}
