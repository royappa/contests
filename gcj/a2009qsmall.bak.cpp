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

typedef pair<int,int> pi;

bool matches(string &word, vector<string> &t)
{
	int L = word.size();
	for (int i = 0; i < L; i++)
	{
		if (t[i].find(word[i]) == -1)
			return false;
	}
	return true;
}

int numWords(vector<string> &v, string &S)
{
	vector<string> r;
	int n = S.size();
	int i = 0;
	while (i < n)
	{
		if (isalpha(S[i]))
		{
			r.push_back(S.substr(i,1));
		}
		else
		{
			string t = "";
			while (S[++i] != ')')
				t += S[i];
			r.push_back(t);
		}
		i++;
	}
	int ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (matches(v[i], tokens))
		{
			ret++;
		}
	}
	return ret;
}

int main()
{
	int L, N, D;
	cin >> L >> D >> N;

	string S;
	vector<string> v;
	for (int i = 0; i < D; i++)
	{
		cin >> S;
		v.push_back(S);
	}

	for (int testCase = 0; testCase < N; testCase++)
	{
		cin >> S;
		cout << "Case #" << testCase+1 << ": " << numWords(v, S) << endl;
	}
	return 0;
}
