#include <bits/stdc++.h>

//http://abc067.contest.atcoder.jp/tasks/abc067_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int N, K;
	cin >> N;
	vector<LL> v(N);

	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	LL sum = accumulate(v.begin(), v.end(), 0LL);
	LL m = 0;
	for (int i = 1; i < N; i++) {
		LL x = accumulate(v.begin(), v.begin()+i, 0LL);
		LL y = sum-x;
		m = max(m, llabs(x-y));
	}
	cout << m;
	exit(0);
}
