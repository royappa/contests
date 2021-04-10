#include <bits/stdc++.h>
// GCJ 2017 R1C, problem A

using namespace std;
typedef long long LL;
int N;
int r[1001], h[1001];
int done[1001][1001][2];
double memo[1001][1001][2];

double f(int p, int K, int first) {

}

double calc(int N_, int K) {
	N = N_;
	memset(done, 0, sizeof(done));
	return f(0, K, 0);
}

int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N_, K_;
		cin >> N_ >> K_;
		for (int i = 0; i < N_; i++) {
			cin >> r[i] >> h[i];
		}
		printf("Case #%d: %lf\n", calc(N_, K_));
	}
	return 0;
}
