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
	int a, b, c, L;

	cin >> a >> b >> c >> L;


	int z = a, y = b, x = c;

	LL r = 0;
	for (int i = 0; i <= L; i++)
	{
		int n = L-(z+i);
		if (x+y+n <= z+i)
			continue;
		for (int d = n; x+y+d > z+i; d--)
			r += d+1;
	}
	r++;
	cout << r << endl;
}

