#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;
const int MOD = 1000000007;

int main()
{
	int T = 10;
	cout << T << endl;
	while (T--) {
		cout << 100000 << " " << 100000 << " " << 100000 << endl;
		for (int i = 0; i < 100000; i++) {
			cout << MOD-7-rand()%100 << " ";
		}
		cout << endl;
		for (int i = 0; i < 100000; i++) {
			cout << MOD-7-rand()%10 << " ";
		}
		cout << endl;
		for (int i = 0; i < 100000; i++) {
			cout << MOD-7-rand()%100-100 << " ";
		}
		cout << endl;
	}
	exit(0);
}

