/*
ID: royappa1
LANG: C++
PROG: lineup
*/

/*
** Acknowledgement: Used C++ STL documentation from the web at http://www.sgi.com/tech/stl/.
** The rules mentioned "Java API documentation from the web" is ** allowed, as is system help files.
** I don't keep C++ STL help files on my system so I used the web.
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

int cow[110000];

int calc(int n, int k)
{
	if (n == 1)
		return (cow[0] == (1<<(k-1))) || (cow[0] == 0);

	// n >= 2
	int bs = int(sqrt(double(n))); // block size. Last block size may be smaller than bs.

	int nb = (n+bs-1)/bs; // round up

	int lastbs = n % bs;
	if (lastbs == 0)
		lastbs = bs;

	for (int b = 0; b < nb; b++) // process each block
	{
		int blen = min(bs, lastbs);
		for (int i = 0; i < blen; i++)
		{
			for (int j = 1; j <= blen; j++)
			{



main ()
{
    FILE *fin, *fout;
	char buf[1024];

	fin = fopen("lineup.in", "r");
	fout = fopen("lineup.out", "w");

	fgets(buf, sizeof(buf), fin);

    int n, k;
    sscanf(buf, "%d%d", &n, &k);

	vpi sched;

	for (int i = 0; i < n; i++)
	{
		fgets(buf, sizeof(buf), fin);
		sscanf(buf, "%d", &cow[i]);
	}

	/* O(n^2*k) algorithm
	for (i)
		zero an array count[1..b]
		for (j = i..n)
			// check i.. j
			for p = 1..b
				if (cow[j] has bit p)
					count[p]++;
			check count[1]..count[p] are same, if so, [i..j] is balanced

	*/

	/*
	// total O(n^.5 * n * k) = O(n^1.5*k)
	for (each chunk of size sqrt(n))
	{
		perform above naive algorithm  = O(sqrt(n)^2*k) = O(n*k)
		// keep track of balanced interval from beginning and end of chunk
	}
	for (each chunk of size sqrt(n))
	{
		merge overlapping ones ..
	}
	*/

	int result = calc(n, k);

	sprintf(buf, "%d\n", result);
	fputs(buf, fout);
	fclose(fout);
	fclose(fin);

    exit (0);
}
