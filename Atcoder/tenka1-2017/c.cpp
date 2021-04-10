#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define MOD 1000000007
#define MaxN 100000
int A[MaxN+10], B[MaxN+10];
int N, K;
int NK;
LL memo[MaxN+10][31][2];

// return best value of numbers [p..n) possible, based on r
// if r=0, the set of numbers chosen must OR less than the rightmost q bits of K
// if r=1, the set of numbers chosen must OR less than q ones strung together) = 2^q-1
LL f(int p, int q, int r) {
	if (p == N || q == 0) {
		return 0;
	}
	LL &res = memo[p][q][r];
	if (res != -1LL) {
		return res;
	}
	res = 0;
	int x = A[p];
	if (r == 0) {
		int y = K&((1<<q)-1);
		if (x <= y) {
			res = B[p]+f(p+1, q, 0);
		}
		else {
			res = max(f(p, q-1, 1), f(p+1, q, 0));
		}
	}
	else {// r == 1
		int y = (1<<q)-1;
		if (x <= y) {
			res = B[p]+f(p+1, q, 0);
		}
		else {
			res = f(p+1, q-1, 0);
		}
	}
	return res;
}

int main()
{
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		scanf("%d%d", &A[i], &B[i]);
	}
	NK = __builtin_popcount(K);

	memset(memo, -1LL, sizeof(memo));

	cout << f(0, NK, 0) << endl;
	exit(0);
}
