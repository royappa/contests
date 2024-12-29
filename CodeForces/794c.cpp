#include <bits/stdc++.h>

//http://codeforces.com/contest/794/problem/C

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pLL;

// Algorithm
// Each player will check if the opponent's best letter is better for him, than his own best letter
// If that is the case then the player will force the opponent to place in the next spot from the front,
// and the player will instead place his best letter in the next spot from the back.
// Otherwise, the player will grab the best spot from the front.

main()
{
	string x, y;
	cin >> x >> y;

	sort(x.begin(), x.end());
	sort(y.rbegin(), y.rend());
	int n = x.size();
	string res(n, '?');
	int a = 0, b = 0;
	int turn = 0;
	int first = 0, second = 0;
	while (n-- > 0) {
		while (res[first] != '?')
			first++;
		if (n > 0) {
			second = first+1;
			while (res[second] != '?')
				second++;
		}
		if (turn == 0) {// Oleg wants smaller
			if (n == 0) {
				res[first] = x[a];
			}
			else {
				if (y[b] < x[a]) {
					res[second] = x[a++];
				}
				else {
					res[first++] = x[a++];
				}
			}
		}
		else {// Igor wants biggest
			if (n == 0) {
				res[first] = y[b];
			}
			else {
				if (x[a] > y[b]) {
					res[second] = y[b++];
				}
				else {
					res[first++] = y[b++];
				}
			}
		}
		turn = 1-turn;
	}
	cout << res << endl;
	exit(0);
}
