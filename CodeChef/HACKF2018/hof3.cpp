#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define SQR(x) ((x)*(x))

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		LL x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;
		LL d2 = SQR(x1-x2)+SQR(y1-y2);
		if (d2 < SQR(r1+r2)) {
			cout << "overlapping";
		}
		else if (d2 > SQR(r1+r2)) {
			cout << "not overlapping";
		}
		else {
			cout << "tangential";
		}
		cout << endl;
	}
}

