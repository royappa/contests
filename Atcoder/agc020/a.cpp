#include <bits/stdc++.h>


using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

int visited[101][101][2];
int N;

int f(int A, int B, int p) {
	visited[A][B][p] = 1;
	if (p == 0) {
		if (A != N && A+1 != B) {
			if (!visited[A+1][B][1-p] && !f(A+1, B, 1-p)) {
				return 1;
			}
		}
		if (A != 1 && A-1 != B) {
			if (!visited[A-1][B][1-p] && !f(A-1, B, 1-p)) {
				return 1;
			}
		}
	}
	else {
		if (B != N && B+1 != A) {
			if (!visited[A][B+1][1-p] && !f(A, B+1, 1-p)) {
				return 1;
			}
		}
		if (B != 1 && B-1 != A) {
			if (!visited[A][B-1][1-p] && !f(A, B-1, 1-p)) {
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int A, B;
	cin >> N >> A >> B;

	memset(visited, 0, sizeof(visited));
	cout << (f(A, B, 0) ? "Alice" : "Borys") << endl;
	exit(0);
}
