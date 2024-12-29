#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int N;
	cin >> N;
	vector<int> v(N);
	map<int,int> c;
	for (int i = 0; i < N; i++) {
		scanf("%d", &v[i]);
		c[v[i]]++;
	}
	int m1 = -1, m2 = -1;
	for (auto z : c) {
		int len = z.first, cnt = z.second;
		if (cnt < 2) continue;
		if (cnt < 4) {
			if (len >= m2) {
				m1 = m2;
				m2 = len;
			}
			else if (len >= m1) {
				m1 = len;
			}
		}
		else {
			if (len >= m2) {
				m1 = len;
				m2 = len;
			}
			else if (len > m1) {
				m1 = len;
			}
		}
	}
	if (m1 == -1 || m2 == -1) {
		cout << 0 << endl;
	}
	else {
		LL area = LL(m1)*LL(m2);
		cout << area << endl;
	}
	exit(0);
}
