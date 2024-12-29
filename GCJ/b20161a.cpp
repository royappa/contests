#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

bool correct(vector<vector<int>>& v)
{
	int N = v.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N-1; j++)
		{
			if (v[i][j] >= v[i][j+1]) return false;
		}
	}
	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N-1; i++)
		{
			if (v[i][j] >= v[i+1][j]) return false;
		}
	}
	return true;
}

vector<int> missing(vector<vector<int>>& v, multiset<vector<int>>& vs)
{
	multiset<vector<int>> vs2;
	int N = v.size();
	for (auto r : v)
	{
		vs2.insert(r);
	}
	for (int j = 0; j < N; j++)
	{
		vector<int> c(N);
		for (int i = 0; i < N; i++)
			c[i] = v[i][j];
		vs2.insert(c);
	}
	for (auto r : vs2)
	{
		if (vs.count(r) != vs2.count(r))
			return r;
	}
	cout << " here " << endl;
	return vector<int> {};
}

bool allused(vector<vector<int>>& v, multiset<vector<int>> vs)
{
	int N = v.size();
	multiset<vector<int>> vs2;
	for (auto r : v)
	{
		vs2.insert(r);
	}
	for (int j = 0; j < N; j++)
	{
		vector<int> c(N);
		for (int i = 0; i < N; i++)
			c[i] = v[i][j];
		vs2.insert(c);
	}
	int num0 = 0, num1 = 0;
	for (auto r : vs2)
	{
		auto x = vs.find(r);
		vs.erase(x);
	}
	return vs.size() == 0;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;
		cin >> N;
		vector<vector<int>> v;
		multiset<vector<int>> vs;
		for (int i = 0; i < 2*N-1; i++)
		{
			vector<int> t(N);
			for (int j = 0; j < N; j++)
			{
				cin >> t[j];
			}
			v.push_back(t);
			vs.insert(t);
		}
		int k = 2*N-1;
		vector<int> r;
		bool found = false;
		for (int m = 0; m < (1<<k); m++)
		{
			if (__builtin_popcount(m) != N) continue;
			vector<vector<int>> w;
			for (int i = 0; i < k; i++)
			{
				if ((m & (1<<i)) == 0) continue;
				w.push_back(v[i]);
			}
			sort(w.begin(), w.end());
			if (correct(w) && allused(w, vs))
			{
				r = missing(w, vs);
				found = true;
				break;
			}
			for (int i = 0; i < N; i++) for (int j = 0; j < i; j++) swap(w[i][j], w[j][i]);
			if (correct(w) && allused(w, vs))
			{
				r = missing(w, vs);
				found = true;
				break;
			}
		}
		if (!found)
		{
			cout << "bad" << endl;
		}
		printf("Case #%d:", testCase);
		for (auto z : r) printf(" %d", z);
		printf("\n");
	}
	return 0;
}
