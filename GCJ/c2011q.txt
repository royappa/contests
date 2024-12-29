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
typedef map<string,string> mss;
typedef set<string> ss;

string f(mss com, ss opp, string s)
{
	string r = "";
	for (int i = 0; i < s.size(); i++)
	{
		r += s[i];
		int n = r.size();
		if (n < 2) continue;
		string suff = r.substr(n-2);
		sort(suff.begin(), suff.end());
		if (com.count(suff) > 0)
		{
			r = r.substr(0, n-2);
			r += com[suff];
			continue;
		}
		for (int j = 0; j < n-1; j++)
		{
			string x = "";
			x += s[i];
			x += r[j];
			sort(x.begin(), x.end());
			if (opp.count(x) > 0)
			{
				r = "";
				break;
			}
		}
	}
	string res = "[";
	string z = "";
	for (int i = 0; i < r.size(); i++)
	{
		z += ", ";
		z += r[i];
	}
	return res+(z.size() >= 2 ? z.substr(2) : "")+"]";

}

int main()
{
	int N;

	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int C, D;
		mss com;
		ss opp;
		cin >> C;
		for (int i = 0; i < C; i++)
		{
			string t;
			cin >> t;
			string x = t.substr(0, 2);
			sort(x.begin(), x.end());
			string y = t.substr(2, 1);
			com[x] = y;
		}
		cin >> D;
		for (int i = 0; i < D; i++)
		{
			string t;
			cin >> t;
			sort(t.begin(), t.end());
			opp.insert(t);
		}
		int dummy;
		cin >> dummy;
		string s;
		cin >> s;
		cout << "Case #" << testCase+1 << ": " << f(com, opp, s) << endl;
	}
	return 0;
}
