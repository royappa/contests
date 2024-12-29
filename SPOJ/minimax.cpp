#include <bits/stdc++.h>

using namespace std;

int debug = 0;

int main()
{
	int tests;

	scanf("%d", &tests);

	while (tests-- > 0) {
		int n, m;
		scanf("%d%d", &n, &m);
		int best = n+1;
		map<int,int> len; // len[R] = L means "To reach R, meaning to sort 1..R, we need a sequence of length L". If R1>R2 then len[R1]>len[R2]. This is kept invariant.
		len[1] = 0;
		for (int i = 0; i < m; i++) { // this is O(m)
			int a, b;
			scanf("%d%d", &a, &b);
			auto f = len.lower_bound(a); // this makes it O(m*log(n))
			if (f == len.end()) {
				continue;
			}
			int R = f->first, L = f->second;
			if (b > R) {
				len[b] = L+1;
				// the above operation may ruin the invariant, so we have to remove the bad entries.
				auto g = len.find(b);
				auto h = prev(g);
				while (h->second >= L+1) { // each input interval can be hit a maximum of once by this loop so it amortizes to O(m) over the whole
					h = prev(h);
				}
				len.erase(next(h), g);
				if (b == n) {
					best = min(best, L+1);
				}
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
