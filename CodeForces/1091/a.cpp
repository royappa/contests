#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{

	int a, b, c;
	cin >> a >> b >> c;
	b--;
	c -= 2;
	cout << min(a,min(b,c))*3+3 << endl;
	exit(0);
}

