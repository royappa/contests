#include <bits/stdc++.h>
// GCJ 2017 Qual, problem C

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

pp f(LL L, LL R, LL K) {
	LL N = R-L-1;
	if (K == 1) {
		N--;
		LL h = N/2;
		return make_pair(max(h, N-h), min(h, N-h));
	}
	if (N%2 == 1) {
		// put one in middle spot
		if (K%2 == 1) {
			// (K-1) is even, so we have two groups of (K-1)/2 left and two identical ranges to place them. The next will go on the left, so last will be right.
			return f(L+N/2+1, R, (K-1)/2);
		}
		else {
			// (K-1) is odd, so the last will end up on the left
			return f(L, L+N/2+1, (K-1)/2+1);
		}
	}
	else {
		// put one in left-middle spot
		if (K%2 == 1) {
			// two equal of (K-1)/2 left. Starts with right, so will end with left
			return f(L, L+N/2, (K-1)/2);
		}
		else {
			// (K-1) is odd, so the last will end up on the right
			return f(L+N/2, R, (K-1)/2+1);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cout << "Case #" << testCase << ": ";

		LL N, K;
		cin >> N >> K;
		pp res = f(0, N+1, K);
		cout << res.first << " " << res.second;
		cout << endl;
	}
	return 0;
}
