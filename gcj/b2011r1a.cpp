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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;
int debug = 0;
typedef long long LL;

set<int> A[26][1024];
set<int> B[26];

void preprocess(vector<string> &v)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			A[i][j].clear();
		}
		B[i].clear();
	}

	int n = v.size();
	for (int i = 0; i < n; i++)
	{
		int len = v[i].size();
		set<char> c;
		for (int p = 0; p < len; p++)
		{
			char L = v[i][p];
			c.insert(L);
		}
		for (typeof(c.begin()) it = c.begin(); it != c.end(); it++)
		{
			int mask = 0;
			for (int j = 0; j < len; j++)
			{
				if (v[i][j] == *it)
				{
					mask |= (1<<j);
				}
			}
			A[*it-'a'][mask].insert(i);
			B[*it-'a'].insert(i);
		}
	}
}

int cost(vector<string> &v, int p, string &letters)
{
	// how many guesses will it cost to find v[p] using given letters?
	int num = 0;
	int n = v.size();
	set<int> cand;
	int len = v[p].size();
	// initially, everybody of the same size is a candidate
	for (int i = 0; i < n; i++)
	{
		if (v[i].size() == len)
		{
			cand.insert(i);
		}
	}
	// cand contains all the candidate words - initially just those of same length
	int pos = 0;
	string mask = v[p];

	while (cand.size() > 1)
	{
		char L = letters[pos];
		pos++;

		// if there is at least one word that has this letter, and is consistent with previous guesses,
		// then we can try it. otherwise we skip that letter.
		//

		vector<int> res;
		set_intersection(cand.begin(), cand.end(), B[L-'a'].begin(), B[L-'a'].end(), back_inserter(res));
		if (res.size() == 0)
			continue; // L is not consistent with current candidates, so skip it

if (debug) cout << pos-1 << " " << L << "/" << letters << "/" << mask << endl;
		int mmask = 0;
		for (int i = 0; i < len; i++)
		{
			if (mask[i] == L)
			{
				mmask |= (1<<i);
				mask[i] = '.';
			}
		}
		if (mmask == 0)
		{
			num++;
			continue; // nothing was revealed, so, there is a penalty. The set of candidates stays same.
		}
		// something WAS revealed
		res.clear();
		set_intersection(cand.begin(), cand.end(), A[L-'a'][mmask].begin(), A[L-'a'][mmask].end(), back_inserter(res));

if (debug) cout << " res = " << res.size() << endl;
		cand.clear();
if (debug) cout << cand.size() << " before /" << v[p] << endl;
		cand.insert(res.begin(), res.end());
if (debug) cout << cand.size() << endl;
	}
if (debug) cout << "cost of " << v[p] << " = " << num << endl;
	return num;
}

string solve(vector<string> &v, string &letters)
{
	int n = v.size();
	string worst = "";
	int wc = -1;
	for (int i = 0; i < n; i++)
	{
//if ( letters == "jmgcuowzrqfpdxehsnvybiklta") debug=1; else debug=0;
		int c = cost(v, i, letters);
		if (c > wc)
		{
			wc = c;
			worst = v[i];
		}
	}
	return worst;
}

int main()
{
	int T;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		vector<string> v;
		int N, M;
		cin >> N >> M;
		for (int i = 0; i < N; i++)
		{
			string x;
			cin >> x;
			v.push_back(x);
		}
		//sort(v.begin(), v.end());
		preprocess(v);
		cout << "Case #" << testCase+1 << ":";
		for (int i = 0; i < M; i++)
		{
			string x;
			cin >> x;
			cout << " " << solve(v, x);
		}
		cout << endl;
	}
	return 0;
}
