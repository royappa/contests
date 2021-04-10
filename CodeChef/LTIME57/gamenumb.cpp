#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		int N, K;
		cin >> N >> K;

		vector<int> A(N), D(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &D[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d", &B[i]);
		}
		map<int,int> m;
		for (int i = 0; i < N; i++) {
			m[A[i]] += D[i];
		}
		for (int i = 0; i < K; i++) {
			if (i%2 == 0) {
				// remove B[i] smallest numbers
			}
			else { // remove B[i] biggest numbers
			}
		}
		LL sum = 0;
		for (auto x : m) {
			sum += x.first*x.second;
		}
		cout << sum << endl;
	}
}

