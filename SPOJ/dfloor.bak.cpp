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
#include <queue>

using namespace std;
#define debug 0

int A[20][20];

int main()
{
	int t;
	char buf[1024];

	gets(buf);
	int w, h;
	sscanf(buf, "%d%d", &w, &h);

	// search for dfloor discussion on forums
	while (w != 0 || h != 0)
	{
		for (int i = 0; i < h; i++)
		{
			gets(buf);
			for (int j = 0; j < w; j++)
			{
				A[i][j] = buf[j]-'0';
			}
		}
		gets(buf);
		sscanf(buf, "%d%d", &w, &h);
	}

	return 0;
}
