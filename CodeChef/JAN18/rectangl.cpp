#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		map<int,int> s;
		for (int i = 0; i < 4; i++) {
			int x;
			cin >> x;
			s[x]++;
		}
		auto it = s.begin();
		cout << (s.size() <= 2 && (it->second == 2 || it->second == 4) ? "YES" : "NO") << endl;
	}
}

