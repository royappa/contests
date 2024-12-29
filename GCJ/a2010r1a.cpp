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

bool check2(vector<string> &v, int r, int c, char ch, int K, int dr, int dc)
{
	int N = v.size();
	for (int i = 0; i < K; i++)
	{
		if (v[r][c] != ch) return false;
		r += dr;
		c += dc;
		if (i == K-1) break;
		if (r < 0 || r >= N || c < 0 || c >= N) return false;
	}
	return true;
}

bool check(vector<string> &v, int K, char ch)
{
	int N = v.size();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (check2(v, i, j, ch, K, -1, -1)) return true;
			if (check2(v, i, j, ch, K, -1,  1)) return true;
			if (check2(v, i, j, ch, K, -1,  0)) return true;
			if (check2(v, i, j, ch, K,  0,  1)) return true;
			if (check2(v, i, j, ch, K,  1,  1)) return true;
			if (check2(v, i, j, ch, K,  1,  0)) return true;
			if (check2(v, i, j, ch, K,  1, -1)) return true;
			if (check2(v, i, j, ch, K,  0, -1)) return true;
		}
	}
	return false;
}

string f(vector<string> &v, int K)
{
	int N = v.size();
	vector<string> w;
	for (int c = 0; c < N; c++)
	{
		string s = "";
		for (int r = N-1; r >= 0; r--)
		{
			s += v[r][c];
		}
		w.push_back(s);
	}
	// drop
	for (int c = 0; c < N; c++)
	{
		for (int r = N-1; r >= 0; r--)
		{
			int t = r;
			if (w[t][c] == '.') continue;
			while (t < N-1 && w[t+1][c] == '.')
			{
				swap(w[t][c], w[t+1][c]);
				t++;
			}
		}
	}
//cout << "*"<<endl;
//for (int i = 0; i < N; i++)  {cout<<w[i] << endl;}
//cout << check2(w, 2, 0, 'B', K, 0, 1) << endl;

	bool red = check(w, K, 'R');
	bool blue = check(w, K, 'B');
	string s;
	if (red && blue)
	{
		s = "Both";
	}
	else if (red)
	{
		s = "Red";
	}
	else if (blue)
	{
		s = "Blue";
	}
	else
	{
		s = "Neither";
	}
	return s;
}

int main()
{
	int T;
	string s;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int K, N;
		cin >> N >> K;
		vector<string> v;
		for (int i = 0; i < N; i++)
		{
			cin >> s;
			v.push_back(s);
		}
		printf("Case #%d: %s\n", testCase+1, f(v, K).c_str());
	}
	return 0;
}
