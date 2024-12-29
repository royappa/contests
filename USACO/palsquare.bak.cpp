/*
ID: royappa1
LANG: C++
PROG: palsquare
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

bool isPal(string s)
{
	int n = s.size();
	return n <= 1 ? true : (s[0] == s[n-1]) && isPal(s.substr(1,n-2));
}

string toBase(int N, int B)
{
	string s = "";
	if (N == 0)
		return "0";

	while (N > 0)
	{
		int d = N % B;
		s += d > 10 ? char('A'+d-10) : char('0'+d);
		N /= B;
	}
	reverse(s.begin(), s.end());
	return s;
}

main ()
{
	ifstream fin("palsquare.in");
	ofstream fout("palsquare.out");

	int B;

	fin >> B;

	for (int N = 1; N <= 300; N++)
	{
		string s = toBase(N*N, B);
		if (isPal(s))
		{
			fout << toBase(N, B) << " " << s << endl;
		}
	}
	fout.close();
	exit (0);
}
