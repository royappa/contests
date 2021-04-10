//https://www.codechef.com/SNCKPB17/problems/XENRANK

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
int main()
{
	int T;
	cin >> T;
	while (T--) {
		LL u, v;
		cin >> u >> v;
		LL t = 0, d = u+v+1;
		if (d == 1) {
			cout << 1 << endl;
			continue;
		}
		t = (d-1)*d/2;
		cout << t+u+1 << endl;
	}
	exit(0);
}

