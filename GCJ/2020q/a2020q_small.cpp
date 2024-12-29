#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int A[100][100];

int main() {
	int NT;
	scanf("%d", &NT); 
	for (int testCase = 0; testCase < NT; testCase++) {
		int N;
		scanf("%d", &N);
		int tr = 0;
		int nr = 0, nc = 0;
		for (int i = 0; i < N; i++) {
			set<int> z;
			for (int j = 0; j < N; j++) {
				scanf("%d", &A[i][j]);
				if (i == j) tr += A[i][j];
				z.insert(A[i][j]);
			}
			nr += z.size() < N;
		}
		for (int j = 0; j < N; j++) {
			set<int> z;
			for (int i = 0; i < N; i++) {
				z.insert(A[i][j]);
			}
			nc += z.size() < N;
		}

		printf("Case #%d: %d %d %d\n", testCase+1, tr, nr, nc);
	}
	return 0;
}
