#include <bits/stdc++.h>

using namespace std;
int debug = 0;

int X, Y;
string S;
int n;
map<pair<int,char>,int> memo;

int val(char a, char b) { return a == 'C' && b == 'J' ? X :
                                 a == 'J' && b == 'C' ? Y : 0; }

int cost(int p, int prev) {
    if (p == n) {
        return 0;
    }
    if (memo.count({p, prev}) > 0) {
        return memo[{p, prev}];
    }
    int res = 0;
    if (S[p] != '?') {
        res = cost(p+1, S[p]) + val(prev, S[p]);
    }
    else {
        res = min(
                cost(p+1, 'C') + val(prev, 'C'),
                cost(p+1, 'J') + val(prev, 'J')
        );
    } 
    return memo[{p,prev}] = res;
}

int main() {
	int NT;
    cin >> NT;
	for (int testCase = 0; testCase < NT; testCase++) {
        cin >> X >> Y >> S;
        n = S.size();
        memo.clear();
        int res;
        if (S[0] == '?') {
            res = min(cost(1, 'C'), cost(1, 'J'));
        }
        else {
            res = cost(1, S[0]);
        }
		printf("Case #%d: %d\n", testCase+1, res);
	}
	return 0;
}
