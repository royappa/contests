#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n, k;
	cin >> n >> k;
    cout << ((k <= n/2+n%2) ? "YES" : "NO");
    cout << endl;
    exit(0);
}

