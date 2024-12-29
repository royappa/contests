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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#include "trankhdr.cpp"

main ()
{

   	int n;

   	scanf("%d", &n);

	map<string,int> pos;
	for (int i = 0; i < 120; i++)
	{
		pos[v[i]] = i;
	}

	vector<int> given;
   	while (n > 0)
   	{
   		given.resize(n, 0);
		for (int i = 0; i < n; i++)
		{
			char buf[10];
			scanf("%s", buf);
			given[i] = pos[buf];
		}
		int dm = 1<<30, dmp = 0;
		for (int i = 0; i < 120; i++)
		{
			int d = 0;
			for (int j = 0; j < n; j++)
			{
				int pj = given[j];
				d += dist[max(i,pj)][min(i,pj)];
			}
			if (d < dm)
			{
				dm = d;
				dmp = i;
			}
		}
		printf("%s is the median ranking with value %d.\n", v[dmp].c_str(), dm);

		scanf("%d", &n);
	}
    exit (0);
}
