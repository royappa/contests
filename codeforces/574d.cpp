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


int main()
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	int left = 0, right = n-1;
	int ops = 0;
	while (left < right)
	{
		int lh = v[left];
		for (int i = left+1; i < right; i++)
		{
			int tmp = v[i];
			v[i] = max(0, v[i]-1);
			v[i] = min(v[i], min(lh, v[i+1]));
			lh = tmp;
		}
		v[left] = v[right] = 0;
		while (left < right && v[left] == 0)
			left++;
		while (left < right && v[right] == 0)
			right--;
		ops++;
	}
	if (v[left] > 0 || v[right] > 0)
		ops++;
	cout << ops << endl;
	exit(0);
}

