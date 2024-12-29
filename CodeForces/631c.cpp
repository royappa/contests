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

typedef pair<int,int> pi;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	vector<int> a = v;

	sort(v.begin(), v.end());

	vector<int> w = v;
	reverse(w.begin(), w.end());

	int maxr = 0, maxt = 0;
	for (int i = 0; i < m; i++)
	{
		int t, r;
		cin >> t >> r;
		if (r > maxr)
		{
			maxr = r;
			maxt = t;
		}
	}

	//... for each element a[i] need to know if it was last part of the UNSORTED(0), UPSORTED(1) or DOWNSORTED(2) series
	for (int i = 0; i < n; i++)
	{
		if (i

}
