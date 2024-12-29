#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int N;
	cin >> N;
	int t1 = 0, x1 = 0, y1 = 0;
	for (int i = 0; i < N; i++) {
		int t2, x2, y2;
		cin >> t2 >> x2 >> y2;
		int t = t2-t1, x = abs(x2-x1), y = abs(y2-y1);
		if (x+y > t) {
			cout << "No" << endl;
			exit(0);
		}
		if (x+y < t) {
			int d = t-(x+y);
			if (d%2 != 0) {
				cout << "No" << endl;
				exit(0);
			}
		}
	}
	cout << "Yes" << endl;
	exit(0);
}
