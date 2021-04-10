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
		map<int,int> len, reach;
		reach[0] = 1;
		len[1] = 0;
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d%d", &a, &b);
			auto f = len.lower_bound(a);
			if (f == len.end()) {
				continue;
			}
			int R = f->first, L = f->second; // reach, length of what we found
			if (reach.count(L+1) == 0 || b > reach[L+1]) { // this new interval will cost us one more len, but will give us more reach than what is already at L+1 (and thus more reach for any lower L)
				if (b == n) {
					best = min(best, L+1);
				}
				reach[L+1] = b;
				// flatten at everything longer than L+1 which reaches <= b
				auto g = reach.find(L+1);
				auto h = g;
				while (++h != reach.end() && h->second <= b) {
				}
				for (auto q = g; ++q != h; ) {
					len.erase(q->second);
				}
				reach.erase(++g, h);
				len[b] = L+1;
			}
		}
		printf("%d\n", best);
	}
	return 0;
}
