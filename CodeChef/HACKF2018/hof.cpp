#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int N;
		cin >> N;
		LL tot = 0;
		LL boxes = N/7;
		tot = (boxes*(boxes+1))/2*7;
		cout << tot << endl;
	}
}

