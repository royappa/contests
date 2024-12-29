#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int L;
		cin >> L;
		string A, B;
		cin >> A >> B;
		set<string> s;
		for (int i = 0; i < L; i++) {
			for (int j = i; j < L; j++) {
				string t = B.substr(i, j-i+1);
				sort(t.begin(), t.end());
				s.insert(t);
			}
		}
		int res = 0;
		for (int i = 0; i < L; i++) {
			for (int j = i; j < L; j++) {
				string t = A.substr(i, j-i+1);
				sort(t.begin(), t.end());
				if (s.count(t)) {
					res++;
				}
			}
		}
		printf("Case #%d: %d\n", testCase, res);
	}
	return 0;
}
