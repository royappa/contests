#include <bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T-- > 0)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			scanf("%d", &v[i]);
		}
		bool cont = true;
		while (cont) {
			cont = false;
			int p = -1, q = -1;
			for (int i = 0; i < N; i++) {
				for (int j = i+1; j < N; j++) {
					if ((v[i]+v[j])%2 == 0) {
						cont = true;
						p = i;
						q = j;
						goto out;
					}
				}
			}
			out:
			if (cont) {
				int sum = v[p]+v[q];
				v.erase(v.begin()+q);
				v.erase(v.begin()+p);
				v.push_back(sum);
				N = v.size();
			}
		}
		cout << v.size() << endl;
	}
	exit(0);
}

