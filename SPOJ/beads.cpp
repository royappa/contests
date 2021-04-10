/*
ID: royappa1
LANG: C++
PROG: beads
*/
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
char beads[10000+1], safe[10000+1];


main ()
{

   	int D;

   	cin >> D;
   	for (int x = 0; x < D; x++)
   	{
		fin >> beads;

		strcpy(safe, beads);

		int maxLen = 0;
		for (int bp = 0; bp < N; bp++)
		{
			// start at bp+1, check up to N chars
			strcpy(beads, safe);
			int cur = (bp+1)%N;
			int len1 = 0;
			bool first = true;
			char color;
			for (int i = 0; i < N; i++)
			{
				if (beads[cur] == 'x')
					break;
				if (beads[cur] != 'w')
				{
					if (first)
					{
						color = beads[cur];
						first = false;
					}
					else if (beads[cur] != color)
					{
						break;
					}
				}
				beads[cur] = 'x';
				cur = (cur+1)%N;
				len1++;
			}
			first = true;
			cur = bp;
			int len2 = 0;
			for (int i = 0; i < N; i++)
			{
				if (beads[cur] == 'x')
					break;
				if (beads[cur] != 'w')
				{
					if (first)
					{
						color = beads[cur];
						first = false;
					}
					else if (beads[cur] != color)
					{
						break;
					}
				}
				beads[cur] = 'x';
				cur = ((cur-1)%N+N)%N;
				len2++;
			}
			if (len1+len2 > maxLen)
			{
				maxLen = len1+len2;
			}
		}
		fout << maxLen << endl;
	}
    exit (0);
}
