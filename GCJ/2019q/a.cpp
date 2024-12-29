#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool fourfree(int x) {
	while (x) {
		if (x%10 == 4) return false;
		x /= 10;
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string N;
		cin >> N;
		int len = N.size();
		string A, B;
		int num1 = 0;
		bool flag = true;
		for (int i = 0; i <= len; i++) {
			if (N[i] > '1') {
				flag = false;
				num1 = i;
				break;
			}
		}
		if (!flag) {
			A.resize(len);
			B.resize(len);
			for (int i = 0; i < len; i++) {
				if (N[i] == '0') {
					A[i] = B[i] = '0';
				}
				else if (N[i] == '5') {
					A[i] = '2';
					B[i] = '3';
				}
				else {
					A[i] = '1';
					B[i] = N[i]-1;
				}
			}
		}
		else {
			N = string("0")+N;
			len = N.size();
			B = string(len-1, '0')+"1";
			A = string(len, '0');
			for (int i = len-1; i >= 0; i--) {
				if (N[i] < B[i]) {
					A[i] = '9';
					N[i-1]--;
				}
				else {
					A[i] = '0'+N[i]-B[i];
				}

			}
		}
		cout << "Case #" << testCase << ": " << A << " " << B << endl;

	}
	return 0;
}
