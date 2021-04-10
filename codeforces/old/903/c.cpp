#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int vis = n;
	bool changed;
	vector<int> w = v;
	do {
		v = w;
		n = v.size();
		vector<int> w;
		for (int i = 0; i < n; i++) {
			if (i+1 < n && v[i] < v[i+1]) {
				continue;
			}
			w.push_back(v[i]);
		}
	}
	while (v != w);
	cout << v.size() << endl;

	exit(0);
}
