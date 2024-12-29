#include <bits/stdc++.h>
// GCJ 2017 R1A, problem A

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

void dump(vector<string> &v) {
	int R = v.size(), C = v[0].size();
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << v[i][j];
		}
		cout << endl;
	}
}

bool empty(string s) {
	return count(s.begin(), s.end(), '?') == s.size();
}

bool full(string s) {
	return count(s.begin(), s.end(), '?') == 0;
}

void complete(string &s) {
	int n = s.size();
	char last = '?';
	for (int j = 0; j < n; j++) {
		if (s[j] == '?') continue;
		last = s[j];
		break;
	}

	for (int j = 0; j < n; j++) {
		if (s[j] == '?') s[j] = last;
		else last = s[j];
	}
}

void f(vector<string> &v) {
	int R = v.size(), C = v[0].size();
	int k = 0;
	while (k < R && empty(v[k])) {
		k++;
	}

	if (k == 0) {// first is not empty
		for (int i = 0; i < R; i++) {
			if (empty(v[i]))
				v[i] = v[i-1];
			else
				complete(v[i]);
		}
	}
	else {//first non-empty is k
		complete(v[k]);
		for (int i = 0; i < k; i++) {
			v[i] = v[k];
		}
		for (int i = k+1; i < R; i++) {
			if (empty(v[i]))
				v[i] = v[i-1];
			else
				complete(v[i]);
		}
	}
	dump(v);
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cout << "Case #" << testCase << ":" << endl;

		int R, C;
		cin >> R >> C;
		vector<string> v;
		for (int i = 0; i < R; i++) {
			string s;
			cin >> s;
			v.push_back(s);
		}
		f(v);
	}
	return 0;
}
