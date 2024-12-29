/*
ID: royappa1
LANG: C++
PROG: transform
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

vector<string> rot(vector<string> v, int num)
{
	int n = v.size();
	for (int t = 0; t < num; t++) // transform num times
	{
		vector<string> v2;
		for (int i = 0; i < n; i++)
		{
			string r = "";
			for (int j = 0; j < n; j++)
			{
				r += v[n-j-1][i];
			}
			v2.push_back(r);
		}
		v = v2;
	}
	return v;
}

vector<string> ref(vector<string> v)
{
	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n/2; j++)
		{
			swap(v[i][j], v[i][n-j-1]);
		}
	}
	return v;
}


main ()
{
	ifstream fin("transform.in");
	ofstream fout("transform.out");

	int N;

	fin >> N;
	vector<string> vin, vout;

	for (int i = 0; i < N; i++)
	{
		string s;
		fin >> s;
		vin.push_back(s);
	}
	for (int i = 0; i < N; i++)
	{
		string s;
		fin >> s;
		vout.push_back(s);
	}

	if (rot(vin,1) == vout) fout << 1 << endl;
	else if (rot(vin,2) == vout) fout << 2 << endl;
	else if (rot(vin,3) == vout) fout << 3 << endl;
	else if (ref(vin) == vout) fout << 4 << endl;
	else if (rot(ref(vin),1) == vout || rot(ref(vin),2) == vout || rot(ref(vin),3) == vout) fout << 5 << endl;
	else if (vin == vout) fout << 6 << endl;
	else fout << 7 << endl;
	fout.close();
	exit (0);
}
