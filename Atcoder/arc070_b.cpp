#include <bits/stdc++.h>

//http://agc010.contest.atcoder.jp/tasks/agc010_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main() {
	int N, K;
	cin >> N >> K;
	int A[200000];
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int r = 0;
	for (int i = 0; i < N; i++) {
		vector<int> w(N-1);
		int n = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			w[n++] = v[i];
		}
		// find all possible values made by subsets of w
		// if there are any >= K, then this is unnecessary
		memset(A, 0, sizeof(A));
		A[0] = 1;
		for (int k = 0; k < n; k++) {
			for (int t = 1; t <= N*K; t++) {
				if (A[t] == 0 && t-w[k] >= 0 && A[t-w[k]]) {
					A[t] = 1;
				}
			}
		}
		for (int t = K; t <= N*K; t++) {
			if (A[t]) {
				r++;
				break;
			}
		}
	}
	cout << r << endl;
}
