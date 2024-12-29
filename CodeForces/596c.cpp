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
	int n;
	cin >> n;
	map<int,int> m;

	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		sx.insert(make_pair(x,y));
		sy.insert(make_pair(y,x));
	}
	for (int i = 0; i < n; i++)
	{
		int w;
		cin >> w;
		m[w]++;
	}
	int sx = 0, sy = 0;

	exit(0);
}

