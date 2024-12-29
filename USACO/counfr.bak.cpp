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
vpi sched;

int f(int booth, int time) // booth is in original ordering
{
//cout << booth << " " << time << endl;

	pi key = make_pair(booth, time);
	if (memo.count(key) > 0)
		return memo[key];

	// check all other booths I can visit
	int r = p[booth] == time;
	int m = 0;

	for (int i = 0; i < n; i++)
	{
		if ((i != booth && p[i] >= time+t[booth][i]) || (i == booth && p[i] > time))
		{
			m = max(m, f(i, p[i]));
		}
	}
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
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fin >> t[i][j];
		}
	}
	// define f(i, t) = maximum number of prizes that can be gained if we are at booth #i at time t.
	// - this is with i in the original order
	// then answer is f(0, 0)
	fout << f(0, 0) << endl;
    exit (0);
}
