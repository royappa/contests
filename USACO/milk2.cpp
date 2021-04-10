/*
ID: royappa1
LANG: C++
PROG: milk2
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
	ifstream fin("milk2.in");
	ofstream fout("milk2.out");

	int N;

	fin >> N;
	vector< pair<int,int> > v;

	set< pair<int,int> > pairs;

	for (int i = 0; i < N; i++)
	{
		int s, e;
		fin >> s >> e;
		if (s == e)
			continue;
		if (pairs.count(make_pair(s,e)) > 0)
			continue;
		pairs.insert(make_pair(s,e));
		v.push_back(make_pair(s,-e));
	}
	sort(v.begin(), v.end());
	int mm = 0, mi = 0;
	for (int i = 0; i < v.size();)
	{
		int start = v[i].first;
		int end = -v[i].second;
		mm >?= end-start;
		int j = i+1;
		while (j < v.size() && v[j].first >= start && v[j].first <= end)
		{
			end >?= -v[j].second;
			j++;
		}
		mm >?= end-start;
		i = j;
		if (i < v.size())
		{
			mi >?= v[i].first-end;
		}
	}
	fout << mm << " " << mi << endl;
	fout.close();
	exit (0);
}
