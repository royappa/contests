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

using namespace std;

typedef long long LL;
int debug = 0;

LL comb(int a, int b)
{
	LL total = 1LL, da = 1LL, db = 1LL;

	int i = 1, j = 1, k = 1;
	do
	{
		total *= i;
		i++;
		while (j <= a && total % j == 0)
		{
			total /= j;
			j++;
		}
		while (k <= b && total % k == 0)
		{
			total /= k;
			k++;
		}
	} while (i <= a+b);

	if (debug) printf("comb(%d,%d,%d) = %lld\n", a+b, a, b, total);
	return total;
}

string tz(string s)
{
	while (s.size() > 1 && s[0] == '0')
		s = s.substr(1);
	return s;
}

string sum(string x, string y)
{
	string z = "0", e = "";
	int len = max(x.size(), y.size());
	while (x.size() < len)
		x = z + x;
	while (y.size() < len)
		y = z + y;

	string s = "";
	int carry = 0;
	if (debug) cout << "pad " << x << " " << y << endl;
	for (int i = len-1; i >= 0; i--)
	{
		int xd = x[i]-'0', yd = y[i]-'0';
		int p = (xd + yd + carry) % 10;
		carry = (xd + yd + carry) / 10;
		s = (e + char('0' + p)) + s;
	if (debug) cout << s << " " << p << " " << carry << endl;
	}
	while (carry > 0)
	{
		s = (e+char('0'+carry%10))+s;
		carry /= 10;
	}
	if (debug) cout << x << " + " << y << " = " << tz(s) << endl;
	return tz(s);
}

string digProd(string x, char dc)
{
	string s = "0";
	int d = dc-'0';
	for (int i = 0; i < d; i++)
	{
		s = sum(s, x);
	}
	if (debug) cout << x << " x " << dc << " = " << tz(s) << endl;
	return tz(s);
}

string prod(string x, string y)
{
	string p = "0", z = "0";
	if (x.size() < y.size())
	{
		string t = x;
		x = y;
		y = t;
	}
	for (int i = x.size()-1; i >= 0; i--)
	{
		string s = digProd(y, x[i]);
		if (i != x.size()-1)
		{
			s += z;
			z += "0";
		}
		p = sum(p, s);
	}
	if (debug) cout << x << " * " << y << " = " << p << endl;
	return p;
}

string solve(int tree[], int root, int n)
{
	if (n <= 1)
	{
		if (debug) cout << tree[root] << " " << root << " " << n << " = " << n << endl;
		string m = "1";
		return m;
	}

	int i = 0;
	for (i = 0; i < n-1 && tree[root+1+i] < tree[root]; i++)
		;
	string cL = solve(tree, root+1, i);
	string cR = solve(tree, root+1+i, n-1-i);

	string m1 = prod(cL, cR);
	char buf[100];
	sprintf(buf, "%lld", comb(i, n-i-1));
	m1 = prod(m1, buf);

	//LL x = cL*cR*comb(i, n-i-1); // fact[n-1]/(fact[i]*fact[n-i-1]) ;
	if (debug) printf("%d %d %d cL=%s cR=%s comb=%s x=%s\n", tree[root], root, n, cL.c_str(), cR.c_str(), buf, m1.c_str());

	return m1;
}

int main()
{
	if (debug) cout << prod("80", "80") << endl;
	int d;
	scanf("%d", &d);

	for (int i = 0; i < d; i++)
	{
		int n, tree[50];

		cin >> n;
		for (int j = 0; j < n; j++)
		{
			cin >> tree[j];
		}
		cout << solve(tree, 0, n) << endl;
	}
	return 0;
}
