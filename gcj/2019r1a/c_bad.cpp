#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool can_pair(vector<string> &v) {
for (auto z : v) { cout << z << " "; } cout << endl;
	int n = v.size();
	int h = n/2;
	vector<set<string>> suffixes;
	for (int i = 0; i < n; i += 2) {
		set<string> s;
		int j = 1;
		int p = v[i].size(), q = v[i+1].size();
		string suff = "";
		while (j <= min(p,q) && v[i][p-j] == v[i+1][q-j]) {
			suff = string(1, v[i][p-j])+suff;
			s.insert(suff);
			j++;
		}
		if (s.size() == 0) return false;
		suffixes.push_back(s);
	}

cout << "for above pairs, here are suffix sets: " << endl;
for (auto x : suffixes) {
	for (auto suff : x) {
		cout << suff << " ";
	}
	cout << endl;
}
cout << "---" << endl;
cout << h << " " << suffixes.size() << endl;


	// is there a unique representative of each set in suffixes?
	vector<int> unq(h, 0);
	int k = 0;
	for (int i = 0; i < suffixes.size(); i++) {
		for (auto suff : suffixes[i]) {
			int c = 0;
			for (int j = 0; j < suffixes.size(); j++) {
				if (i == j) continue;
				c += suffixes[j].count(suff);
			}
			unq[i] = c == 0;
		}
	}
for (auto x : unq) {
	cout << x << " "; } cout << endl;

	return accumulate(unq.begin(), unq.end(), 0) == h;
}

int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;
		vector<string> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		int best = 0;
		for (int m = 0; m < (1<<N); m++) {
			int c = __builtin_popcount(m);
			if (c%2 != 0 || c < 2) continue;
			vector<string> w(c);
			int k = 0;
			for (int i = 0; i < N; i++) {
				if (m & (1<<i)) {
					w[k++] = v[i];
				}
			}
			sort(w.begin(), w.end());
			do {
				if (can_pair(w)) {
					best = max(best, k);
					break;
				}
			}
			while (next_permutation(w.begin(), w.end()));
		}
		cout << "Case #" << testCase << ": " << best << endl;
	}
	return 0;
}
