#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		LL n;
		cin >> n;
		LL len = 1;
		while (n > 1LL<<len) {
			n -= 1LL<<len;
			len++;
		}
		string s = "";
		n--;
		while (len > 0) {
			LL half = 1LL<<(len-1);
			if (n >= half) {
				s += '8';
				n -= half;
			}
			else {
				s += '5';
			}
			len--;
		}
		cout << s << endl;
	}
}

