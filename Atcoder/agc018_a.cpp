#include <bits/stdc++.h>

//http://agc018.contest.atcoder.jp/tasks/agc018_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	unordered_set<int> s(v.begin(), v.end());

	if (s.count(K) != 0) {
		cout << "POSSIBLE" << endl;
		exit(0);
	}
	if (K > v[N-1]) {
		cout << "IMPOSSIBLE" << endl;
		exit(0);
	}
	for (int i = 1; i < N; i++) {
		if (v[i] == v[i-1]) continue;
		if (K%(v[i]-v[i-1]) == 0) {
			cout << "POSSIBLE" << endl;
			exit(0);
		}
	}
	cout << "IMPOSSIBLE" << endl;
	exit(0);
}
