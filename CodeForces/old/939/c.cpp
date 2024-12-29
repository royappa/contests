#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	int start, finish;
	cin >> start >> finish;
	vector<string> t = {"Greenwich", "Ukraine", "Afghan", "India"};
	for (int i = 0; i < n; i++) { // offset of each timezone. GMT has offset 0
		// what is GMT range of timezone i?
		cout << "Times of " << t[i] << " in GMT: ";
		for (int j = 1; j <= n; j++) {
			int x = j-i;
			if (x <= 0) x += n;
			cout << x  << " ";
		}
		cout << endl;
	}

	exit(0);
}
