#include <bits/stdc++.h>
// GCJ 2017 R1B, problem B

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

void f(int N, vector<int> &col) {
	vector<int> v(N);

}
int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		printf("Case #%d: ", testCase);

		int N;
		vector<int> col(6);
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> col[i];
		}
		f(N, col);
	}
	return 0;
}
