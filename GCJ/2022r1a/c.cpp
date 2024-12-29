#include <bits/stdc++.h>

using namespace std;
int debug = 0;

string high() {
  int NE, NW;
  cin >> NE >> NW;
  vector<vector<int>> w(NE, vector<int>(NW));
  for (int i = 0; i < NE; i++) {
    for (int j = 0; j < NW; j++) {
      cin >> v[i][j];
    }
  }
  
}

int main() {
	int NT;
  cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d: %d\n", testCase+1, weights());
	}
	return 0;
}
