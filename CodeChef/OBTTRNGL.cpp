//https://www.codechef.com/COOK85/problems/OBTTRNGL
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		int k, A, B;
		cin >> k >> A >> B;
		if (A > B) {
			swap(A, B);
		}
		B -= A;  // e.g. for K=6, A=1,B=3 goes to A=0, B=2 and midpoint is 6/2 = 3
		if (k%2 == 0) {
			if (B == k/2) {
				cout << 0;
			}
			else if (B < k/2) {
				cout << B-1;
			}
			else {
				cout << (k-1)-B;
			}
		}
		else {
			if (2*B < k) {
				cout << B-1;
			}
			else {
				cout << (k-1)-B;
			}
		}
		cout << endl;
	}
	exit(0);
}

