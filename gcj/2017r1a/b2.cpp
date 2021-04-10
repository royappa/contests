#include <bits/stdc++.h>
// GCJ 2017 R1A, problem B

using namespace std;
typedef long long LL;

typedef pair<LL,LL> pp;

bool isValid1(int qa, int ra) { // we can make more than 1 valid servings

	most servings = qa/(.9*ra)
	least         = qa/(1.1*ra)
}


bool isValid2(int qa, int ra, int qb, int rb) {

	int loa = ceil(0.9*qa/ra);
	int hia = floor(1.1*qa/ra);
	if (loa == 0 || hia < loa) return false;

	int lob = ceil(0.9*qb/rb);
	int hib = floor(1.1*qb/rb);
	if (lob == 0 || hib < lob) return false;

	return hia >= lob && hib >= loa;

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
