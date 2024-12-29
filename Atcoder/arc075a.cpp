#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

int N, v[101];
int poss[10000];

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	int tot = accumulate(v, v+N, 0);
	memset(poss, 0, sizeof(poss));
	poss[0] = 1;
	for (int i = 0; i < N; i++) {
		for (int s = tot; s >= 0; s--) {
			if (s-v[i] >= 0 && poss[s-v[i]]) {
				poss[s] = 1;
			}
		}
	}
	int m = 0;
	for (int s = 0; s <= tot; s++) {
		if (poss[s] && s%10 > 0) {
			m = max(m, s);
		}
	}
	cout << m << endl;
	exit(0);
}

