#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main()
{
	int n;
	cin >> n;
	vector<LL> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.rbegin(), v.rend());
	LL a = v[0], b = v[1], c = 0;
	for (int i = 2; i < n; i++)
		c += v[i];
	vector<LL> t = {a,b,c};
	sort(t.begin(), t.end());
	cout << min(0, t[3]-t
	exit(0);
}
