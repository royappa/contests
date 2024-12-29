#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;

	int MaxP = 1000000;
	vector<int> v(MaxP+1, 0);
	v[0] = 1;
	v[1] = 1;
	for (int i = 0; i <= MaxP; i++) {
		if (v[i] == 1) continue;
		for (int j = i+i; j <= MaxP; j += i) {
			v[j] = 1;
		}
	}

	vector<int> cum(MaxP+1, 0);
	cum[0] = 0;
	for (int i = 1; i <= MaxP; i++) {
		cum[i] = cum[i-1]+(v[i] == 0);
	}
	while (T-- > 0)
	{
		int L, R;
		cin >> L >> R;
		int num = cum[R]-cum[L-1];
		printf("%.6lf\n", double(num)/(R-L+1));
	}
}

