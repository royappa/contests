/*
ID: royappa1
LANG: C++
PROG: radar
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

long long reverse(long long x)
{
	int d[100], dn = 0;

	// assume x > 0
	while (x > 0)
	{
		d[dn++] = x % 10;
		x /= 10;
	}
	long long rev = 0;
	for (int i = 0; i < dn; i++)
	{
		rev = rev*10 + d[i];
	}
	return rev;
}

bool isPal(long long num)
{
	return num == reverse(num);
}

void getSteps(int N, int& steps, int& val)
{
	long long num = N;

	steps = 0;
	while (!isPal(num))
	{
		steps++;
		num += reverse(num);
	}
	val = int(num);
	return;
}

main ()
{
    ifstream fin("radar.in");
    ofstream fout("radar.out");

    int N;
    fin >> N;

	int steps, val;
	getSteps(N, steps, val);
	fout << steps << " " << val << endl;

    exit (0);
}
