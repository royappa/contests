#include <bits/stdc++.h>

using namespace std;
typedef long long LL;


void bubble(vector<int> &v, int p) {
	int n = v.size();
	vector<int> w(n);
	int k = 0;
	for (int i = p; i < n; i += 2) {
		w[k++] = v[i];
	}
	sort(w.begin(), w.begin()+k);
	k = 0;
	for (int i = p; i < n; i += 2) {
		v[i] = w[k++];
	}
}
int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int n;
		scanf("%d", &n);
		vector<int> v(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		for (int i = 0; i < sqrt(n)+1; i++) {
			bubble(v, i);
		}

		bool ok = true;
		int bad = -1;
		for (int i = 0; i < n-1; i++) {
			if (v[i] > v[i+1]) {
				ok = false;
				bad = i;
				break;
			}
		}

		if (ok) {
			cout << "Case #" << testCase << ": " << "OK" << endl;
		}
		else {
			cout << "Case #" << testCase << ": " << bad << endl;
		}
	}
	return 0;
}



