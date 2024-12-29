/*
ID: royappa1
LANG: C++
PROG: counfr
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

int t[500][500];
int p[500];
int n;
map<pi,int> memo;
multimap<int,int> sched;

int f(int booth, int time) // booth is in original ordering
{
cout << booth << " " << time << endl;
	/*
	pi key = make_pair(booth, time);
	if (memo.count(key) > 0)
		return memo[key];
	*/
	// check all other booths I can visit
	int r = p[booth] == time;
	int m = 0;
	multimap<int,int>::iterator it;
	for ( it = sched.lower_bound(time+1); it != sched.end() && it->first >= time+t[booth][it->second]; it++)
	{
		cout << booth << "/" << time << ":" << it->second << "/" << it->first << endl;
		m = max(m, f(it->second, it->first));
	}
if (it != sched.end())
	cout << "***" << booth << "/" << time << ":" << it->second << "/" << it->first << ":" << time+t[booth][it->second] << endl;
cout << booth << " " << time << " = " << m+r << endl;
	return m+r;
}
main ()
{
    ifstream fin("counfr.in");
    ofstream fout("counfr.out");

    fin >> n;

	for (int i = 0; i < n; i++)
	{
		fin >> p[i];
		sched.insert(make_pair(p[i], i));
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> t[i][j];
		}
	}
for (multimap<int,int>::iterator it = sched.lower_bound(0); it != sched.end(); it++)
	cout << it->first << " " << it->second << endl;
cout << "--\n";
	// define f(i, t) = maximum number of prizes that can be gained if we are at booth #i at time t.
	// - this is with i in the original order
	// then answer is f(0, 0)

	fout << f(0, 0) << endl;
    exit (0);
}
