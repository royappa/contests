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
		int ones = 0, zeros = 0;
		while (N--)
		{
			cin >> X;
			if (X)
				ones++;
			else
				zeros++;
		}
	}
}

