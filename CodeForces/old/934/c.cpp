#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

int A(vector<int> &v, int p, int L, int R) {
	if (p < L || p > R) {
		return v[p];
	}
	int x = p-L;
	int y = R-x;
	return v[y];
}


int BinarySearch(vector<int> &v, int l, int r, int key) {
    while (l+1 != r) {
		int mid = (l+r)/2;
		if (v[mid] >= key)
			r = mid;
		else
			l = mid;
    }
    return r;
}


// Algorithm from: https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
int LIS(vector<int> &v, int L, int R) {

 	int n = v.size();
    vector<int> tail(n, 0);
    int len = 1; // always points empty slot in tail

    tail[0] = A(v, 0, L, R);
    for (int i = 1; i < n; i++) {
        if (A(v, i, L, R) < tail[0])
            tail[0] = A(v, i, L, R);
        else if (A(v, i, L, R) > tail[len-1])
            tail[len++] = A(v, i, L, R);
        else
            tail[BinarySearch(tail, -1, len-1, A(v, i, L, R))] = A(v, i, L, R);
    }
    return len;
}

bool possibleLIS(int len, vector<int> &v) {
	int n = v.size();
	int best = 0;
	for (int i = 0; i+len <= n; i++) {
		best = max(best, LIS(v, i, i+len-1));
	}
	return best;
}
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}


	int lo = 1, hi = n+1; // a LIS of "1" is always possible, n+1 is not possible
	while (lo+1 != hi) {
		int mid = (lo+hi)/2;
		if (possibleLIS(mid, v)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	cout << lo << endl;

	exit(0);
}
