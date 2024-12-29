//https://www.codechef.com/LTIME48/problems/TELEPORT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


bool eq(int x1, int y1, int x2, int y2) {
	return x1 == x2 && y1 == y2;
}

bool overlap(int x1, int x2, int x3, int x4) {
	if (x1 > x2) swap(x1, x2);
	if (x3 > x4) swap(x3, x4);
	return x1 <= x4 && x3 <= x2;
}

bool same(int x1a, int y1a, int x2a, int y2a, int x1b, int y1b, int x2b, int y2b) {

	if (y1a == y2a && y1b == y2b)  { //both horizontal
		if (y1a != y1b) return false;
		return overlap(x1a, x2a, x1b, x2b);
	}
	else if (x1a == x2a && x1b == x2b) {
		if (x1a != x1b) return false;
		return overlap(y1a, y2a, y1b, y2b);
	}
	else {
		return eq(x1a, y1a, x1b, y1b) ||
			   eq(x1a, y1a, x2b, y2b) ||
			   eq(x2a, y2a, x1b, y1b) ||
			   eq(x2a, y2a, x2b ,y2b);
	}

}
int main()
{
	int T;
	cin >> T;
	while (T-- > 0) {
		int x1a, y1a, x2a, y2a;
		int x1b, y1b, x2b, y2b;
		cin >> x1a >> y1a >> x2a >> y2a;
		cin >> x1b >> y1b >> x2b >> y2b;
		cout << (same(x1a, y1a, x2a, y2a, x1b, y1b, x2b, y2b) ? "yes" : "no") << endl;
	}
}

