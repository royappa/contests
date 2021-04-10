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
typedef long long LL;

class CubeColoring {
public:
long long theCount(vector <string> v)
{
	int n = v[0].size();

	LL tot = 0;
	for (int i = 0; i < n; i++)
	{
		if (v[0][i] == 'N') continue;
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			if (v[1][j] == 'N') continue;
			for (int k = 0; k < n; k++)
			{
				if (k == i) continue;
				if (v[3][k] == 'N') continue;
				for (int w = 0; w < n; w++)
				{
					if (w == i) continue;
					if (v[4][w] == 'N') continue;
					string s2 = v[2], s5 = v[5], s7 = v[7];
					s2[j] = s2[k] = 'N';
					s5[j] = s5[w] = 'N';
					s7[k] = s7[w] = 'N';
					LL num2, num5, num7;
					num2 = num5 = num7 = 0;
					for (int t = 0; t < n; t++)
					{
						if (s2[t] == 'Y') num2++;
						if (s5[t] == 'Y') num5++;
						if (s7[t] == 'Y') num7++;
					}
					cout << i << " " << j << " " << k << " " << w << " : " << s2 << "/" << s5 << "/" << s7 << endl;
					for (int x = 0; x < n; x++)
					{
						int d2 = 0, d5 = 0, d7 = 0;
						if (v[6][x] == 'N') continue;
						if (s2[x] == 'Y') d2 = 1;
						if (s5[x] == 'Y') d5 = 1;
						if (s7[x] == 'Y') d7 = 1;
						tot += (num2-d2)*(num5-d5)*(num7-d7);
					}
				}
			}
		}
	}
	return tot;
}
};


//Powered by [KawigiEdit]
