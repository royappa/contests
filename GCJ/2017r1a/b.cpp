#include <bits/stdc++.h>
// GCJ 2017 R1A, problem B

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

bool good(LL qty, LL g, LL servings) {
	return qty*10LL >= 9LL*(g*servings) && qty*10LL <= 11LL*(g*servings);
}

bool isValid1(int a, int ra) { // we can make more than 0 valid servings with these two ingredients
	for (int s = (.9*a/ra)-1; s <= (1.1*a/ra)+1; s++) {
		if (good(a, ra, s)) {
			return true;
		}
	}
	return false;
}


bool isValid2(int a, int ra, int b, int rb) {
	// use at least 90% of a, so,  s >= .9*a/ra;
	for (int s = (.9*a/ra)-1; s <= (1.1*a/ra)+1; s++) {
		if (good(a, ra, s) && good(b, rb, s)) {
			return true;
		}
	}
	for (int s = (.9*b/rb)-1; s <= (1.1*b/rb)+1; s++) {
		if (good(a, ra, s) && good(b, rb, s)) {
			return true;
		}
	}
	return false;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		cout << "Case #" << testCase << ": ";

		int N, P; // N = number of ingredients, P = number of packages
		cin >> N >> P;
		vector<int> R(N); // required number of grams for each of N ingredients
		for (int i = 0; i < N; i++) {
			cin >> R[i];
		}
		vector<vector<int>> Q(N, vector<int>(P)); // package quantities, Q[i][j] = number of grams that package i has of ingredient j
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < P; j++) {
				cin >> Q[i][j];
			}
			sort(Q[i].begin(), Q[i].end());
		}
		// maximum 2 rows
		if (N <= 1) {
			int num = 0;
			for (int j = 0; j < P; j++) {
				if (isValid1(Q[0][j], R[0])) {
					num++;
				}
			}
			cout << num << endl;
		}
		else if (N == 2) {
			int best = 0;
			do {
				int num = 0;
				for (int j = 0; j < P; j++) {
					if (isValid2(Q[0][j], R[0], Q[1][j], R[1])) {
						num++;
					}
				}
				best = max(best, num);
			} while (next_permutation(Q[0].begin(), Q[0].end()));
			cout << best << endl;
		}
		else {
			cout << endl;
		}
	}
	return 0;
}
