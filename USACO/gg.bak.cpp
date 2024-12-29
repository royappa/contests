/*
ID: royappa1
LANG: C++
PROG: dualpal
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
		s += d >= 10 ? char('A'+d-10) : char('0'+d);
		N /= B;
	}
	reverse(s.begin(), s.end());
	return s;
}

main ()
{
	ifstream fin("dualpal.in");
	ofstream fout("dualpal.out");

	int N, S;
	// N <= 15
	// S <= 10000
	// find the first N numbers larger than S which are palindromes in at least two bases


	fin >> N >> S;
	int cur = S+1;
	while (N > 0)
	{
		int num = 0;
		for (int B = 2; B <= 10 && num < 2; B++)
		{
			string s = toBase(cur, B);
			if (isPal(s))
			{
				num++;
			}
		}
		//cout << cur << " " << num << endl;
		if (num >= 2)
		{
			fout << cur << endl;
			N--;
		}
		cur++;
	}
	fout.close();
	exit (0);
}
