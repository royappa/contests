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

using namespace std;

typedef long long LL;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> f(n), b(n);
	map<int,int> fm, bm;
	for (int i = 0; i < n; i++)
	{
		cin >> f[i];
		fm[f[i]]++;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
		bm[b[i]]++;
		if (fm.count(b[i]) == 0)
		{
			cout << "Impossible" << endl;
			exit(0);
		}
	}
	// b[i] = f[a[i]]


	exit(0);
}

