#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int N, K;
	cin >> N >> K;
	int v[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
	}
	vector<LL> res;
	for (int L = 0; L < N; L++) {
		for (int R = L; R < N; R++) {
			int xmin = v[L];
			int xxor = v[L];
			//cout << L+1 << " " << R+1 << endl;
			for (int i = L+1; i <= R; i++) {
				xmin = min(xmin, v[i]);
				xxor = xxor^v[i];
			}
			res.push_back(xmin*xxor);
		}
	}
	sort(res.begin(), res.end());
	cout << res[K-1] << endl;
	exit(0);
}

