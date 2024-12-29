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
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))


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

		/*****
		** Basic idea: sort the original array S into an array T
		** Then assign each element an index in its sorted order
		** We're basically renumbering the items in sorted order
		** Now the Fenwick tree's indexes run over this uniform range of indexes 0,1,2,3.. instead of the nasty values themselves
		** And it offers two operations:
		**  	increase(tree, I, X). This will increase the value at index I, by X.
		** Note that all duplicate values fall into the same index. So if you need to increase those separately,
		** then you probably need to multiply by the dup-count or something like that (not sure)
		** 		query(tree, A, B)   This returns the sum of items from index [A..B], inclusive
		**
		** So for the LIS algorithm needed below, what we do is
		**
			For i := 0 to n-1 do
				increase(tree, index[S[i]], 1+query(tree, 0, index[S[i]]-1))
		**
		**	The index[S[i]]-1 is the index of the item smaller than S[i].
		** Note that initially the whole tree is init'ed to zero. (How does this work for negative numbers?)
		**
		** We scan the original array S from left to right, so at any time we only store results of whatever has been processed so far.
		** Note that item to the RIGHT of S[i] in the S array, may be to the left of S[i] in the sorted array (if they're smaller than S[i]).
		** And this would technically add their values into the sum for S[i], however, they were initialized to 0 and we haven't processed them yet,
		** so adding 0 doesn't matter.
		*/
		sort(T.begin(), T.end()); // T is a sorted copy of S

		map<int,int> ind; // ind[x] is the index position of item x in the sorted list
		for (int i = 0; i < n; i++)
		{
			ind[T[i]] = i;
		}
		if (debug)
		{
			for (int i = 0; i < n; i++)
			{
				cout << S[i] << " " << ind[S[i]] << endl;
			}
		}
		vector<int> tree;
		tree = create(n); // create fenwick tree of size n
		for (int i = 0; i < n; i++)
		{
			if (ind[S[i]] == 0)
				increase(tree, 0, 1);
			else
				increase(tree, ind[S[i]], 1+query(tree, 0, ind[S[i]]-1));
			if (debug) cout << i << " " << S[i] << " = " << query(tree, ind[S[i]], ind[S[i]]) << endl;
		}
		if (debug)
		{
			cout <<"**"<<endl;
			for (int i = 0; i < n; i++)
			{
				cout << tree[i] << endl;
			}
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
