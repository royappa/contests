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

using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T-- > 0)
	{
		int N;
		cin >> N;
		int c2 = 0, c5 = 0;
		int X = N;
		while (X >= 2)
		{
			c2 += X/2;
			X /= 2;
		}
		X = N;
		while (X >= 5)
		{
			c5 += X/5;
			X /= 5;
		}
		cout << min(c2, c5) << endl;
	}
}

