/*
ID: royappa1
LANG: C++
PROG: namenum
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

	ifstream fin("namenum.in");
	ofstream fout("namenum.out");

	string s;

	fin >> s;

	ifstream din("dict.txt");

	vector<string> vl;

	string t[] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" };
	for (int i = 0; i < 10; i++)
	{
		vl.push_back(t[i]);
	}

	set<string> dict;
	vector<string> r;
	while (!din.eof())
	{
		string t;
		din >> t;
		if (t.size() > 0 && isalpha(t[0]))
		{
			bool allFound = true;
			for (int i = 0; i < t.size(); i++)
			{
				bool allMatch = true;
				for (int j = 0; j < 10; j++)
				{
					int pos = vl[j].find(t[i]);
					if (!(pos != -1 && j == s[i]-'0'))
					{
						allMatch = false;
						break;
					}
				}
				if (!allMatch)
				{
					allFound = false;
					break;
				}
			}
			if (allFound)
			{
				r.push_back(t);
			}
		}
	}

	if (r.size() == 0)
	{
		fout << "NONE" << endl;
	}
	else
	{
		for (int i = 0; i < r.size(); i++)
		{
			fout << r[i] << endl;
		}
	}
	fout.close();
	exit (0);
}
