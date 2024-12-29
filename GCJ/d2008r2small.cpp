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
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))


int rle(string s)
{
	int n = s.size();
	char last = '.';
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] != last)
		{
			num++;
		}
		last = s[i];
	}
	return num;
}

string permute(vector<int>& p, string& s)
{
	int n = s.size();
	int k = p.size();
	string t(n,' ');
	for (int i = 0; i < n/k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			t[i*k+j] = s[i*k+p[j]];
		}
	}
	return t;
}

int main()
{
	int N;
	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int k;
		string S;
		cin >> k;
		cin >> S;
		if (debug) cout << k << " " << S << endl;

		vector<int> p;
		for (int i = 0; i < k; i++)
		{
			p.push_back(i);
		}
		int best = 100000;
		do
		{
			string T = S;
			best <?= rle(permute(p, T));
		}
		while (next_permutation(p.begin(), p.end()));


		printf("Case #%d: %d\n", testCase+1, best);
	}
	return 0;
}
