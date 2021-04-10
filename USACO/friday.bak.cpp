/*
ID: royappa1
LANG: C++
PROG: friday
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

main ()
{
	ifstream fin("friday.in");
	ofstream fout("friday.out");

	int N;

	fin >> N;

	vector<int> dow(7,0);

	int cur = 2; // Monday
	for (int y = 1900+0; y < 1900+N; y++)
	{
		int m[] = {31,28,31,30,31,30,31,31,30,31,30,31};
		m[1] += y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
		cout << y << " " << m[1] << endl;
		for (int i = 0; i < 12; i++)
		{
			for (int d = 0; d < m[i]; d++)
			{
				if (d == 12)
				{
					dow[cur]++;
				}
				cur = (cur + 1) % 7;
			}
		}
	}

	for (int i = 0; i < 7; i++)
	{
		fout << dow[i] << (i < 6 ? " " : "");
	}
	fout << endl;
	fout.close();
	exit (0);
}
