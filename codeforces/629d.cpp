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
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL,int> ppSize;
typedef pair<int,LL> ppInd;

int main()
{
	int n;
	cin >> n;
	vector<LL> r(n), h(n);
	double M_PI = 4.0*atan(1.0);
	vector<ppSize> v(n), v_orig;

	for (int i = 0; i < n; i++)
	{
		cin >> r[i] >> h[i];
		v[i] = make_pair(r[i]*r[i]*h[i], i);
	}
	v_orig = v;
	sort(v.begin(), v.end()); // cakes sorted by size, but not by index (except when size is equal).


	// We now build set A iteratively starting with the biggest simple cake, downwards
	// It is a set of pairs <i,T>
	// If A has pair<i,T>, then T is the total volume of all cakes starting with index i
	// At the end, we want the biggest T value from all pairs in A

	set<ppInd> A;

	for (int i = n-1; i >= 0; i--)
	{
		int j = v[i].second;
		// find the first item in A which has a larger index k > j. Its T will be the max sum possible for chains starting with k
		// STL lower_bound() will find the first item with an index which is NOT LESS than j
		// Since there is no pair with index EQUAL to j in the set, it will return the first item with index k > j

		auto p = A.lower_bound(make_pair(j, LL(0)));
		LL t;
		if (p == A.end()) // this means either A is empty, or, j is bigger than any index in the set
		{
			A.insert(make_pair(j, v_orig[j].first)); // In this case we start a new chain with index j
		}
		else if (v_orig[p->first].first != v_orig[j].first) // don't add a cake if a simple cake of this size was already added
		{
			A.insert(make_pair(j, v_orig[j].first+p->second)); // add index j and its size to the total of the chain starting at k > j
		}
	}
	LL best = 0;
	for (auto x : A)
	{
		best = max(x.second, best);
	}

	printf("%.12lf\n", best*M_PI);
}

