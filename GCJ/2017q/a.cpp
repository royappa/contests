#include <bits/stdc++.h>
// GCJ 2017 Qual, problem A

using namespace std;
typedef long long LL;

typedef pair<int,int> pi;

int f(string s, int K) {
	int n = s.size();
	int num = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-') {
			if (i+K > n) return -1;
			for (int j = 0; j < K; j++) {
				s[i+j] = s[i+j] == '-' ? '+' : '-';
			}
			num++;
		}
	}
	return num;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string S;
		int K;
		cin >> S >> K;
		cout << "Case #" << testCase << ": ";
		int res = f(S, K);
		if (res == -1) {
			cout << "IMPOSSIBLE";
		}
		else {
			cout << res;
		}
		cout << endl;
	}
	return 0;
}
