#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	vector<LL> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i];
	}
	LL N;
	cin >> N;

	LL M = (N/2)*2;

	LL cost = 1LL<<60;
	vector<double> d = {4,2,1,0.5};
	for (int i = 0; i < 4; i++) {
		LL c = LL(M*d[i])*v[i];
		cost = min(cost, c);
	}
	N -= M;
	if (N > 0) {
		LL cost2 = 1LL<<60;
		for (int i = 0; i < 3; i++) {
			LL c = 1*d[i]*v[i];
			cost2 = min(cost2, c);
		}
		cost += cost2;
	}
	cout << cost << endl;
	exit(0);
}
