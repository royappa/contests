#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

void solve(int testCase, int N, string P) {
	string R;
	int L = P.size();
	char a = P[0], b = P[L-1];
	if (a == 'S' && b == 'E') {
		R = string(N-1, 'E')+string(N-1, 'S');
	}
	else if (a == 'E' && b == 'S') {
		R = string(N-1, 'S')+string(N-1, 'E');
	}
	else if (a == 'S' && b == 'S') {
		vector<int> v(N, 0);
		int p = 0;
		v[0] = 1;
		for (int i = 0; i < L; i++) {
			if (P[i] == 'E') p++;
			else v[p] = 1;
		}
		R = "E";
		for (int i = 1; i < N-1; i++) {
			if (v[i]) {
				R += "E";
			}
			else {
				R += string(N-1, 'S');
				R += string(2*N-2-R.size(), 'E');
				break;
			}
		}
	}
	else if (a == 'E' && b == 'E') {
		vector<int> v(N, 0);
		int p = 0;
		for (int i = 0; i < L; i++) {
			if (P[i] == 'S') p++;
			else v[p] = 1;
		}
		R = "S";
		for (int i = 1; i < N-1; i++) {
			if (v[i]) {
				R += "S";
			}
			else {
				R += string(N-1, 'E');
				int k = R.size();
				R += string(2*N-2-k, 'S');
				break;
			}
		}
	}
	cout << "Case #" << testCase << ": " << R << endl;

}
int main() {
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{

		int N;
		string P;
		cin >> N >> P;
		solve(testCase, N, P);
	}
	return 0;
}
