#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

// Algorithm
// S = a*b^2*c*d^2
// P = a^2*b*c^2*d
// S*P = (a*b*c*d)^3

main()
{
	unordered_set<LL> cubes;

	for (LL i = 0; i <= 1000002LL; i++) {
		cubes.insert(i*i*i);
	}

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		LL S, P;
		cin >> S >> P;
		if (S == 1 && P == 1) {
			cout << "Yes";
		}
		else if (cubes.count(S*P) > 0) {
			if (S != 1 && P != 1) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
		}
		else {
			cout << "No";
		}
		cout << endl;
	}

	exit(0);
}

