#include <bits/stdc++.h>

using namespace std;
int debug = 1;
typedef long long LL;
typedef pair<string,string> ps;

string itoa(int x, int len)
{
	string s = "";
	while (len--)
	{
		s += char('0'+x%10);
		x /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}

int satoi(string s) { return atoi(s.c_str()); }

vector<string> Clist, Jlist;
void fill (vector<string> &l, string s, int p, int n)

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		string C, J;
		cin >> C >> J;
		int n = C.size();
		for (int i = 0; i < n; i++)
		{
			if (C[i] == '?' && J[i] == '?')
			{
				C[i] = J[i] = '0';
			}
		}

		cout << "Case #" << testCase << ": " << bestc << " " << bestj << endl;

	}
	return 0;
}
