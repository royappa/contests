#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
string s;
int n;
LL memo[50][2][3][5][7];


#define MODULUS  1000000007

/*******************************************/
// FENWICK TREE CODE FROM ALGORITHMIST.COM
// DO NOT USE FOR TOPCODER WITHOUT MODIFYING OR REWRITING MYSELF

// In this implementation, the tree is represented by a vector<int>.
// Elements are numbered by 0, 1, ..., n-1.
// tree[i] is sum of elements with indexes i&(i+1)..i, inclusive.
// (this is a bit different from what is proposed in Fenwick's article.)

// Creates a zero-initialized Fenwick tree for n elements.
vector<int> create(int n) { return vector<int>(n, 0); }

// Returns sum of elements with indexes a..b, inclusive
int query(const vector<int> &tree, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
          sum = (tree[b] + sum) % MODULUS;
        return sum;
    } else {
        return ((query(tree, 0, b) - query(tree, 0, a-1))%MODULUS+MODULUS)%MODULUS;
    }
}

// Increases value of k-th element by inc.
void increase(vector<int> &tree, int k, int inc) {
    for (; k < (int)tree.size(); k |= k + 1) tree[k] = (tree[k] + inc) % MODULUS;
}
/**************************************/


int main()
{
	int N;
	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int n, m, X, Y, Z;
		cin >> n >> m >> X >> Y >> Z;
		vector<LL> A(m,0);
		for (int i = 0; i < m; i++)
		{
			int x;
			cin >> x;
			A[i] = x;
		}
		vector<int> S(n,0);
		vector<int> T(n,0);
		for (int i = 0; i <= n-1; i++)
		{
			T[i] = S[i] = A[i%m];
			A[i%m] = (X*A[i%m]+LL(Y)*LL(i+1))%Z;
		}
		sort(T.begin(), T.end());

		map<int,int> ind;
		for (int i = 0; i < n; i++)
		{
			ind[T[i]] = i;
		}
		vector<int> tree;
		tree = create(n); // create fenwick tree of size n
		for (int i = 0; i < n; i++)
		{
			if (ind[S[i]] == 0)
				increase(tree, 0, 1);
			else
				increase(tree, ind[S[i]], 1+query(tree, 0, ind[S[i]]-1));
		}
		int t = 0;
		vector<int> done(n, 0);
		for (int i = 0; i < n; i++)
		{
			if (!done[ind[S[i]]])
			{
				done[ind[S[i]]] = 1;
				t = (t + query(tree, ind[S[i]], ind[S[i]])) % MODULUS;
			}
		}

		printf("Case #%d: %d\n", testCase+1, t);
	}
	return 0;
}
