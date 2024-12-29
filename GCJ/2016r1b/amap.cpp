#include <bits/stdc++.h>

// GCJ 2016, round 1B, problem A
using namespace std;
int debug = 1;
typedef long long LL;
typedef map<char,int> mci;

bool contains(mci s, mci sub)
{
	for (char x = 'a'; x <= 'z'; x++)
	{
		if (sub[x] > 0 && s[x] < sub[x])
		{
			return false;
		}
	}
	return true;
}
mci remdig(mci s, mci sub)
{
	for (char x = 'a'; x <= 'z'; x++)
	{
		if (sub[x] > 0)
			s[x] -= sub[x];
	}
	return s;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string s;
		cin >> s;
		for (auto &x : s) x = tolower(x);
		vector<string> sub = {"zero","two","four","six","eight","one","three","five","seven","nine"};
		vector<int> dig = {0,2,4,6,8,1,3,5,7,9};
		multiset<int> res;
		mci m;
		for (auto x : s) m[x]++;
		for (int i = 0; i <= 9; i++)
		{
			mci msub;
			for (auto x : sub[i]) msub[x]++;
			while (contains(m, msub))
			{
				res.insert(dig[i]);
				m = remdig(m, msub);
			}
		}
		cout << "Case #" << testCase << ": ";
		for (auto x : res)
			cout << x;
		cout << endl;
	}
	return 0;
}
