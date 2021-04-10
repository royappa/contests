#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v(2*n);
		LL sum = 0, mx = -1e9;
		bool allNeg = true, allPos = true;
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
			v[n+i] = v[i];
			sum += v[i];
			mx = max(mx, v[i]);
			if (v[i] < 0) {
				allPos = false;
			}
		}
		if (allPos) {
			cout << LL(sum*k) << endl;
			exit(0);
		}
		if (mx <= 0) {
			cout << mx << endl;
			exit(0);
		}
		// all are not positive and all are not negative
		LL bestAll = mx, bestCur = 0;
		for (int i = 0; i < 2*n; i++) {
			bestCur += v[i];
			if (bestCur > bestAll) {
				bestAll = bestCur;
			}
			if (bestCur < 0) {
				bestCur = 0;
			}
		}


	}
}

