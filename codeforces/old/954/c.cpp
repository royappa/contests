#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int d[] = {-1,0, 0,1, 1,0, 0,-1};
bool canMove(int a, int b, int x, int y) {
	int ax = a/y, ay = a%y;
	int bx = b/y, by = b%y;
	ax++; ay++; bx++; by++;
	for (int i = 0; i < 4; i++) {
		int cx = ax+d[2*i];
		int cy = ay+d[2*i+1];
		if (cx < 1 || cx > x || cy < 1 || cy > x) continue;
		if (cx == bx && cy == by) {
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}

	for (int x = 1; x <= n; x++) {
		if (n%x != 0) continue;
		int y = n/x;
		for (int i = 0; i < n-1; i++) {
			if (canMove(v[i], v[i+1], x, y)) {
				cout << "YES" << endl;
				cout << x << " " << y << endl;
				exit(0);
			}
		}
	}
	cout << "NO" << endl;
	exit(0);
}
