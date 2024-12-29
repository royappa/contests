#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool square(LL n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}


int main(int argc, char *argv[])
{
	LL n = atoi(argv[1]), m = atoi(argv[2]);

	while (n <= m) {
		set<vector<LL>> v;
		for (LL i = 1; i*i <= n; i++) {
			for (LL j = 1; j*j <= n; j++) {
				LL kk = n-i*i-j*j;
				if (square(kk)) {
					LL k = round(sqrt(kk));
					if (k > 0 && i*i+j*j+k*k == n) {
						vector<LL> t = {i,j,k};
						sort(t.begin(), t.end());
						v.insert(t);
					}
				}
			}
		}
		if (v.size() > 1) {
			cout << n << ": " << v.size() << " degeneracies" << endl;
			for (auto x : v) {
				for (auto u : x) {
					cout << u << " ";
				}
				cout << endl;
			}
			cout << endl;
		}
		n++;
	}
	exit(0);
}

