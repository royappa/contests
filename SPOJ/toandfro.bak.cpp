// negative base conversion to negative bases
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
	int c;

	cin >> c;

	while (c > 0)
	{
		string s;
		cin >> s;
		int n = s.size();

		string res = "";
		for (int i = 0; i < n/c; i++)
		{
			if (i % 2 == 0)
			{
				res += s.substr(i*c, c);
			}
			else
			{
				string sub = s.substr(i*c, c);
				reverse(sub.begin(), sub.end());
				res += sub;
			}
		}
		string d = "";
		cout << res << endl;
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < n/c; j++)
			{
				d += res[i+j*c];
			}
		}
		cout << d << endl;
		cin >> c;
	}
	return 0;
}

