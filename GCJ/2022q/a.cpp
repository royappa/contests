#include <bits/stdc++.h>

using namespace std;
int debug = 0;

void card() {
    int R, C;
    
    cin >> R >> C;
    vector<string> v;
    for (int i = 0; i < 2*R+1; i++) {
        string row = "";
        for (int j = 0; j < C; j++) {
            row += i%2 ? "|." : "+-";
        }
        row += i%2 ? "|" : "+";
        v.push_back(row);
    }
    v[0][0] = v[0][1] = v[1][0] = '.';
    for (auto row : v) {
        cout << row << endl;
    }
}

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
		printf("Case #%d:\n", testCase+1);
        card();
	}
	return 0;
}
