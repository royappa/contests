#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
#define MOD 1000000007

int N;
vector<string> v(2);

int memo[60][4][4];

// number of ways to color [p..N) given that two colors describe the rows to the left of p, that we cannot use.
int f(int p, int tcol, int bcol) {
	if (p == N) {
		return 1;
	}
	int &res = memo[p][tcol][bcol];
	if (res != -1) {
		return res;
	}
	// two possibilities, we either have to place a vertical domino next or two horizontal dominos

	res = 0;
	if (v[0][p] == v[1][p]) {
		for (int color = 1; color <= 3; color++) {
			if (color == tcol || color == bcol) continue;
			res = (res + f(p+1, color, color))%MOD;
		}
	}
	else {
		for (int tcol2 = 1; tcol2 <= 3; tcol2++) {
			for (int bcol2 = 1; bcol2 <= 3; bcol2++) {
				if (tcol2 == tcol || bcol2 == bcol || tcol2 == bcol2) continue;
				res = (res + f(p+2, tcol2, bcol2))%MOD;
			}
		}
	}
	return res;
}

int main()
{

	cin >> N;
	cin >> v[0] >> v[1];
	memset(memo, -1, sizeof(memo));
	cout << f(0, 0, 0) << endl;
	exit(0);
}
