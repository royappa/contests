/*
ID: royappa1
LANG: C++
PROG: events
*/

/*
** Acknowledgement: Used C++ STL documentation from the web at http://www.sgi.com/tech/stl/. The rules mentioned "Java API documentation from the web" is ** allowed, as is system help files. I don't keep C++ STL help files on my system so I used the web.
** I understand that this may result in disqualification if my interpretation of the rules was wrong.
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

typedef pair<int,int> pi;
typedef vector<pi> vpi;

int f[10005];

main ()
{
    ifstream fin("events.in");
    ofstream fout("events.out");

    int n;
    fin >> n;

	vpi sched;

	for (int i = 0; i < n; i++)
	{
		int s, len;
		fin >> s >> len;
		sched.push_back(make_pair(s, len));
	}

	sort(sched.begin(), sched.end());
	multimap<int,pi> t;
	for (int i = 0; i < sched.size(); i++)
	{
		int s = sched[i].first;
		t.insert(make_pair(s, make_pair(s, i)));
	}
	// define f[i] = maximum number of events that can be visited starting at the i'th event
	// (assuming the events are sorted in non-desc order by start time)
	// then answer is f[0]

	f[n-1] = 1;
	for (int i = n-2; i >= 0; i--)
	{
		// compute f[i]
		// do we include event i or not?
		// 	If we do, the best is 1 + f[the first event following the end of i]
		//  If we don't, the best is f[i+1]
		multimap<int,pi>::iterator it = t.lower_bound(sched[i].first+sched[i].second);
		int x = 0;
		if (it != t.end())
		{
			int next = it->second;
			x = 1 + f[next];
		}
		// thus f[i] is the max of these two
		f[i] = max(x, f[i+1]);
	}
	fout << f[0] << endl;

    exit (0);
}
