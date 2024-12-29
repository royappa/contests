#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int k;
	cin >> k;
	if (k > 38) {
		cout << -1 << endl;
		exit(0);
	}
	string s = "";
	while (k >= 2) {
		s += '8';
		k -= 2;
	}
	if (k > 0) {
		s += '4';
	}
	cout << s << endl;
	exit(0);
}
