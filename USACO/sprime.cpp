/*
ID: royappa1
LANG: C++
PROG: sprime
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

int pdig[] = { 1, 2, 3, 5, 7, 9 };

bool isPrime(int n)
{
	if (n < 2 || (n > 2 && n%2 == 0))
		return false;

	int d = 3;
	while (d*d <= n)
	{
		if (n % d == 0)
			return false;
		d += 2;
	}
	return true;
}

void find(int pre, int len, int N, ofstream& 	fout)
{
	if (len == N)
	{
		fout << pre << endl;
	}

	for (int i = 0; i < 6; i++)
	{
		int num = pre*10+pdig[i];
		if (isPrime(num))
		{
			find(num, len+1, N, fout);
		}
	}
	return;
}


main ()
{
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int N;
    fin >> N;

	find(0, 0, N, fout);

    exit (0);
}
