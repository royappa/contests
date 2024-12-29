#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int damage(string P) {
	int n = P.size();
	int d = 0;
	int power = 1;
	for (int i = 0; i < n; i++) {
		if (P[i] == 'C') {
			power *= 2;
		}
		else {
			d += power;
		}
	}
	return d;
}
int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int D;
		string P;
		cin >> D >> P;

		if (count(P.begin(), P.end(), 'S') > D) {
			cout << "Case #" << testCase << ": " << "IMPOSSIBLE" << endl;
			continue;
		}
		int turns = 0;
		int n = P.size();
		while (damage(P) > D) {
			// find the S after the last C and swap
			for (int i = n-1; i >= 1; i--) {
				if (P[i] == 'S' && P[i-1] == 'C') {
					swap(P[i], P[i-1]);
					break;
				}
			}
			turns++;
		}
		cout << "Case #" << testCase << ": " << turns << endl;
	}
	return 0;
}
