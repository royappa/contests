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

int debug = 0;

using namespace std;

int n;
int p10[100];


typedef pair<int,int> pi;
//map<pi,string> memo;

string memo[20000][30];
int used[20000][30];

// f(r, k) = smallest 1-0 number, that equals r mod n, using at most k digits, starting with 1. If none, return ""
string f(int r, int k)
{
if (debug) cout << r << "/" << k << endl;
	string ret;
	if (k == 0)
	{
		ret = "";
	}
	else if (r == 0) // k >= 1
	{
		ret = "0";
	}
	else if (r == 1)
	{
		ret = "1";
	}
	else if (k == 1 && r > 1)
	{
		ret = "";
	}
	else
	{
		//pi key = make_pair(r, k);
		if (used[r][k]) // memo.count(key) > 0)
		{
			//ret = memo[key];
			ret = memo[r][k];
		}
		else
		{
			// k > 1, and r >= 1
			if (p10[k-1] == r)
			{
				string one = "1";
				string z(k-1, '0');
				ret = one+z;
			}
			else if ((p10[k-1]+1)%n == r)
			{
				string one = "1";
				string z(k-2, '0');
				ret = one+z+one;
			}
			else
			{
				// search for 10^(k-1)+x, where x starts with 1, thus x = 10^j+y where j <= k-1
				// 10^(k-1)+x=r mod n
				// if 10^(k-1)=p, then x = (r-p) % n
				ret = "";
				for (int j = 2; j <= k; j++)
				{
					int p = p10[j-1];
					int q = ((r-p)%n+100000*n)%n;
					string s = f(q, j-1);
					ret = s;
					if (s != "")
					{
						string one = "1";
						s = one+string((j-1)-int(s.size()), '0')+s;
						ret = s;
						break;
					}
				}
			}
			//memo[key] = ret;
			memo[r][k] = ret;
			used[r][k] = 1;
		}
	}
if (debug) cout << r << "/" << k << "/" << ret << "/" << endl;
	return ret;
}

string onezero()
{
	if (n == 1)
	{
		return "1";
	}
	//memo.clear();
	memset(used, 0, sizeof(used));
	// Find smallest 1-0 number that equals 0 mod n
	// This 1-0 number starts with 1 and is at least 2 digits long
	// => this 1-0 number is of the form 10^k+x, k >= 1, where x is also a 1-0 number, and the smallest one which qualifies
	// => we must find smallest k such that 10^k+x = 0 mod n, and must find smallest x
	// Now, if 10^k = p mod n, then x = (n-p) mod n
	// x has at most k digits
	// Therefore, we need to find smallest x such that x = (n-p) mod n, and x has at most k digits (if it exists)
	for (int k = 1; ; k++)
	{
		int p = p10[k];
		if (p == 0)
		{
			string one = "1";
			string z(k, '0');
			return one+z;
		}
		// search for x's starting with 1, if any
		int q = (n-p)%n;
		string s = f(q, k);
		if (s != "")
		{
			string one = "1";
			string z(k-int(s.size()), '0');
			return one+z+s;
		}
	}
}


int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		cin >> n;

		p10[0] = 1;
		for (int i = 1; i < 100; i++)
		{
			p10[i] = (p10[i-1] * 10) % n;
		}

		string s = onezero();
		printf("%s\n", s.c_str());
	}

	return 0;
}
