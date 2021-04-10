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
map<pi,string> memo;

// f(r, k) = smallest 1-0 number, that equals r mod n, using at most k digits. If none, return ""
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
	else if (k == 1 && r == 1)
	{
		ret = "1";
	}
	else if (k == 1) // r > 1
	{
		ret = "";
	}
	else
	{
		pi key = make_pair(r, k);
		if (memo.count(key) > 0)
		{
			ret = memo[key];
		}
		else
		{
			// k > 1, and r > 1
			string s = f(r, k-1); // try leading digit = 0
			if (s != "")
			{
				ret = s;
			}
			else
			{
				// try leading digit = 1
				// 10^(k-1)+x=r mod 9
				// if 10^(x-1)=p, then x = (r-p) % n
				int p = p10[k-1];
				int q = ((r-p)%n+100000*n)%n;
				s = f(q, k-1);
				if (s != "")
				{
					if (s == "0")
					{
						s = "";
					}
					string one = "1";
					s = one+string((k-1)-int(s.size()), '0')+s;
				}
				ret = s;
			}
			memo[key] = ret;
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
	memo.clear();
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
		int q = (n-p)%n;

		string s = f(q, k);
		if (s != "")
		{
			if (s == "0")
			{
				s = "";
			}
			string one = "1";
			string z(k-int(s.size()), '0');
			return one+z+s;
		}
	}
}


int main()
{
	printf("1\n");
	for (int i = 1; i <= 20000; i++)
	{
		printf("%d\n", i);
	}
	return 0;
}
