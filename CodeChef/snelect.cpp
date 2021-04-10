//https://www.codechef.com/SNCKPB17/problems/SNELECT

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
bool debug = false;

int main()
{
	int T;
	cin >> T;
	while (T--) {
		string e;
		cin >> e;
		int n = e.size();
		for (int i = 0; i < n; i++) {
			if (e[i] == 'm') {
				if (i > 0 && e[i-1] == 's') {
					e[i-1] = '.';
				}
				else if (i+1 < n && e[i+1] == 's') {
					e[i+1] = '.';
				}
			}
		}
		int mo = count(e.begin(), e.end(), 'm');
		int sn = count(e.begin(), e.end(), 's');
		if (mo < sn)
			cout << "snakes";
		else if (sn < mo)
			cout << "mongooses";
		else
			cout << "tie";
		cout << endl;
	}
	exit(0);
}

