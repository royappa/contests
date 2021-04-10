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
char buf[1024];

#define C(x)  (char('0'+(x)))

bool better(int f[], int g[])
{
	int cf[10], cg[10];
	cf[0] = f[0];
	cg[0] = g[0];
	for (int i = 1; i < 10; i++)
	{
		cf[i] = cf[i-1]+f[i];
		cg[i] = cg[i-1]+g[i];
	}
	for (int i = 9; i >= 0; i--)
	{
		if (cf[i] != cg[i])
		{
			return cf[i] > cg[i];
		}
		if (f[i] != g[i])
		{
			return f[i] > g[i];
		}
	}
	return false;
}

void print(int f[][10])
{
	for (int q = 0; q < 3; q++)
	{
		for (int i = 0; i < 10; i++)
		{
			printf("%3d", f[q][i]);
		}
		printf("\n");
	}
}

void div15(string buf)
{
	vector<int> d;
	int n = buf.size();
	int nz = 0, nf = 0;
	for (int i = 0; i < n; i++)
	{
		if (buf[i] != '0')
		{
			d.push_back(buf[i]-'0');
		}
		else
		{
			nz++;
		}
		if (buf[i] == '5')
		{
			nf++;
		}
	}

	int f1[3][10], f2[3][10];
	memset(f1, 0, sizeof(f1));
	memset(f2, 0, sizeof(f2));

	int nz1, nz2;

	if (nz > 0 && d.size() > 0)
	{
		nz1 = nz-1;

		int f[3][10], g[3][10], s[3];
		memset(f, 0, sizeof(f));
		memset(s, 0, sizeof(s));
		f[d[0]%3][d[0]] = 1;
		s[d[0]%3] = 1;

		n = d.size();
		for (int k = 1; k < n; k++)
		{
			memcpy(g, f, sizeof(g));
			for (int q = 0; q < 3; q++)
			{
				if (q == 0 || s[q] > 0)
				{
					int r = (q + d[k]) % 3;
if (debug) printf("r = %d k = %d q = %d\n", r, k, q);
					f[q][d[k]]++;
					if (better(f[q], g[r]))
					{
						memcpy(g[r], f[q], sizeof(g[0]));
					}
					f[q][d[k]]--;
				}
			}
			memcpy(f, g, sizeof(f));
			for (int q = 0; q < 3; q++)
			{
				int sum = 0;
				for (int i = 0; i < 10; i++)
				{
					sum += f[q][i];
				}
				s[q] = sum;
			}
		}
		memcpy(f1, f, sizeof(f1));
	}
if (debug)
{
	printf("f1 final\n");
	print(f1);
}
	if (nf > 0 && n > 1)
	{
		vector<int>::iterator fp = find(d.begin(), d.end(), 5);
		assert(fp != d.end());
		d.erase(fp);
		nz2 = nz;
if (debug)
{
	for (int i = 0; i < d.size(); i++)
	{
		printf("%3d", d[i]);
	}
	printf("\n");
}
		int f[3][10], g[3][10], s[3];
		memset(f, 0, sizeof(f));
		memset(s, 0, sizeof(s));

		f[d[0]%3][d[0]] = 1;
		s[d[0]%3] = 1;

		n = d.size();
		for (int k = 1; k < n; k++)
		{
if (debug)
{
	printf("f before k=%d\n", k);
	print(f);
}
			memcpy(g, f, sizeof(g));
			for (int q = 0; q < 3; q++)
			{
				if (q == 0 || s[q] > 0)
				{
					int r = (q + d[k]) % 3;
if (debug) printf("r = %d k = %d q = %d s[q] = %d\n", r, k, q, s[q]);
					f[q][d[k]]++;
					if (better(f[q], g[r]))
					{
						memcpy(g[r], f[q], sizeof(g[0]));
					}
					f[q][d[k]]--;
				}
			}
			memcpy(f, g, sizeof(f));
			for (int q = 0; q < 3; q++)
			{
				int sum = 0;
				for (int i = 0; i < 10; i++)
				{
					sum += f[q][i];
				}
				s[q] = sum;
			}

if (debug)
{
	printf("f after k=%d\n", k);
	print(f);
}
		}
		memcpy(f2, f, sizeof(f2));
	}
if (debug)
{
	printf("f2 final\n");
	print(f2);
}
	string ret1 = "";
	for (int i = 9; i >= 0; i--)
	{
		char ch = C(i);
		for (int j = 0; j < f1[0][i]; j++)
		{
			ret1 += ch;
		}
	}
	if (ret1 == "" && nz > 0)
	{
		ret1 = "0";
	}
	else if (nz > 0)
	{
		while (nz > 0)
		{
			ret1 += "0";
			nz--;
		}
	}
	string ret2 = "";
	for (int i = 9; i >= 0; i--)
	{
		char ch = C(i);
		for (int j = 0; j < f2[1][i]; j++)
		{
			ret2 += ch;
		}
	}
	if (ret2 != "")
	{
		while (nz2 > 0)
		{
			ret2 += "0";
			nz2--;
		}
		ret2 += "5";
	}
if (debug)
{
	printf("r1=%s\nr2=%s\n", ret1.c_str(), ret2.c_str());
}
	if (ret1 == "" && ret2 == "")
	{
		printf("impossible\n");
	}
	else if (ret2 == "")
	{
		printf("%s\n", ret1.c_str());
	}
	else if (ret1 == "")
	{
		printf("%s\n", ret2.c_str());
	}
	else
	{
		if (ret1.size() > ret2.size())
		{
			printf("%s\n", ret1.c_str());
		}
		else if (ret2.size() > ret1.size())
		{
			printf("%s\n", ret2.c_str());
		}
		else
		{
			for (int i = 0; i < ret1.size(); i++)
			{
				if (ret1[i] != ret2[i])
				{
					printf("%s\n", ret1[i]>ret2[i] ? ret1.c_str() : ret2.c_str());
					return;
				}
			}
		}
	}
	return;
}

int main()
{
	int t;
	cin >> t;

	while (t-- > 0)
	{
		string s;
		cin >> s;
		div15(s);
	}

	return 0;
}
