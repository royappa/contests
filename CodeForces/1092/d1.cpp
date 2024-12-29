#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
		v[i] %= 2;
	}
	set<vector<int>> ints;
	set<vector<int>> evens;

	v.push_back(-1);
	vector<int> e = {0,v[0],1}; // left, which, len
	for (int i = 1; i < n+1; i++) {
		if (v[i] == v[i-1]) {
			e[2] = (e[2]+1)%2;
		}
		else {
			ints.insert(e);
			if (e[2]%2 == 0) {
				evens.insert(e);
			}
			e = {i, v[i], 1};
		}
	}

	while (evens.size() > 0 && ints.size() > 1) {

cout << "Evens:" <<endl;
for (auto z : evens) {
	cout << z[0] << " " << z[1] << " " << z[2] << endl;
}
		vector<int> x = *(evens.begin());
		evens.erase(evens.begin());
		auto px = ints.find(x);
		auto py = px;
		auto pw = px;
		vector<int> r = {x[0], 1-x[1], 0};
		if (px == ints.begin()) {
			r[2] = x[2];
		}
		else {
			pw--;
			r[2] = (r[2]+(*pw)[2])%2;
		}
		py++;
		if (py != ints.end()) {
			r[2] = (r[2]+(*py)[2])%2;
		}
		if (py != ints.end()) {
			ints.erase(py);
		}
		if (px == ints.begin()) {
			ints.erase(px);
		}
		else {
			ints.erase(px);
			ints.erase(pw);
		}
		cout << "r is " << r[0] << " " << r[1] << " " << r[2] << endl;
		ints.insert(r);
		if (r[2]%2 == 0) {
			evens.insert(r);
		}
	}
	cout << (ints.size() > 1 ? "NO" : "YES") << endl;
	exit(0);
}
