#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int b, k, x, ans;
int main()
{
	cin >> b >> k;
	for (int i = 0; i < k-1; i++) cin >> x, ans ^= (x%2)*(b%2);
	cin >> x; ans ^= x%2; cout << (ans ? "odd" : "even");
	return 0;
}

