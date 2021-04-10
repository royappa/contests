#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
typedef pair<int,int> pi;
int memo[6][6][6][6][6];

int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int R, C;
		cin >> R >> C;
		memset(memo, -1, sizeof(memo));
		if (f(0, 0, 0, 0, 0, 0)) {
			cout << "Case #" << testCase << ": " << "POSSIBLE" << endl;
			for (auto x : v) {
				cout << x.first << " " << x.second << endl;
			}
		}
		else {
			cout << "Case #" << testCase << ": " << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
