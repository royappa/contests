#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define MaxN 100000
int A[MaxN+10], B[MaxN+10];
int N, K;

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	int NK = 32-__builtin_clz(K);
	vector<int> v;
	for (int b = NK-1; b >= 0; b--) {
		if (K & (1<<b)) {
			int x = (K&~(1<<b))|((1<<b)-1);
			v.push_back(x);
		}
	}
	int q = v.size();
	vector<LL> sums(q, 0LL);
	LL sum = 0;
	for (int i = 0; i < N; i++) {
		for (int p = q-1; p >= 0; p--) {
			if (A[i] <= v[p]) {
				sums[p] += B[i];
				break;
			}
		}
	}
	cout << *max_element(sums.begin(), sums.end()) << endl;
	exit(0);
}
