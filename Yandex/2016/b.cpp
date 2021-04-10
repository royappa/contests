#include <bits/stdc++.h>
// Yandex 2016 warmup A

using namespace std;
typedef long long LL;

int main()
{
	int n;
	LL minx, maxx;
	cin >> n;
	cin >> minx;
	maxx = minx;
	for (int i = 1; i < n; i++)
	{
		LL x;
		cin >> x;
		minx = min(x, minx);
		maxx = max(x, maxx);
	}
	cout << (maxx-minx) << endl;
	return 0;
}
