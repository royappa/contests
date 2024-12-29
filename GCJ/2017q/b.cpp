#include <bits/stdc++.h>
// GCJ 2017 Qual, problem A

using namespace std;
typedef long long LL;

typedef pair<int,int> pi;

LL f(LL N) {
	char buf[100];
	sprintf(buf, "%lld", N);
	string s(buf);
	int n = s.size();
	for (int i = 0; i < n-1; i++) {
		if (s[i] > s[i+1]) {
			int j = i;
			while (j >= 0 && s[j] == s[i])
				j--;
			j += 2;
			while(j < n) {
				s[j++] = '0';
			}
			LL x;
			sscanf(s.c_str(), "%lld", &x);
			return x-1;
		}
	}
	return N;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cout << "Case #" << testCase << ": ";

		LL N;
		cin >> N;
		LL res = f(N);
		cout << res;
		cout << endl;
	}
	return 0;
}
