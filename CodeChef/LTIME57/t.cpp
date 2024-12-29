#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		int N, U, D;
		cin >> N >> U >> D;
		vector<int> h(N);
		for (int i = 0; i < N; i++) {
			cin >> h[i];
		}
		int p = 0;
		bool used = false;
		while (p < N) {
			if (h[p] <= h[p+1]) {
				if (h[p+1]-h[p] > U) {
					break;
				}
			}
			else {
				if (h[p]-h[p+1] > D && !used) {
					break;
				}
				else if (h[p]-h[p+1] > D) {
					used = false;
				}
			}
			p++;
		}
		cout << p << endl;
	}
}

