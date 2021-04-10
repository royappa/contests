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
		LL n;
		cin >> n;
		LL tot = 0;
		tot = n*(n+1)*(2*n+1)/6;

		double x = 0;
		for (LL i = 1; i <= n; i++) {
			x += double(i)*SQR(n-i+1)/tot;
		}
		cout << LL(x) << endl;
	}
}

