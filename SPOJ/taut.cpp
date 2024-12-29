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

bool eval(string e, int val[])
{
	int n = e.size();

	bool st[256];
	int top = -1;
	bool value = false;

	for (int p = n-1; p >= 0; p--)
	{
		if (islower(e[p]))
		{
			bool b = val[e[p]-'a'];
			st[++top] = b;
		}
		else if (e[p] == 'C') // AND
		{
			bool b = st[top] && st[top-1];
			st[--top] = b;
		}
		else if (e[p] == 'D') // OR
		{
			bool b = st[top] || st[top-1];
			st[--top] = b;
		}
		else if (e[p] == 'N') // NOT
		{
			bool b = !st[top];
			st[top] = b;
		}
		else if (e[p] == 'I') // IMPLIES
		{
			bool b = st[top-1] || !st[top];
			st[--top] = b;
		}
		else // EQUIV
		{
			bool b = st[top-1] == st[top];
			st[--top] = b;
		}
	}
	if (debug) printf("value = %d\n", st[0]);
	return st[0];
}

bool taut(string e)
{
	string orig = e;
	sort(e.begin(), e.end());
	e.erase(unique(e.begin(), e.end()), e.end());
	string vars = "";
	int n = e.size()-1;
	while (n >= 0 && islower(e[n]))
	{
		vars += e[n];
		n--;
	}
	if (vars.size() == 0)
		return true;

	n = vars.size();
	int val[26];
	for (int mask = 0; mask < (1<<n); mask++)
	{
		e = orig;
		for (int i = 0; i < 26; i++)
		{
			val[i] = 0;
		}
		for (int i = 0; i < n; i++)
		{
			val[vars[i]-'a'] = (mask&(1<<i)) != 0 ? 1 : 0;
		}
		if (debug)
		{
			printf("evaluating %s mask = %d\n", e.c_str(), mask);
			for (int i = 0; i < n; i++)
			{
				printf("%c=%d ", vars[i], val[vars[i]-'a']);
			}
			printf("\n");
		}
		if (!eval(e, val))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int t;
	char buf[1024];

	scanf("%d", &t);

	for (int i = 0; i < t; i++)
	{
		scanf("%s\n", buf);
		printf("%s\n", taut(buf) ? "YES" : "NO");
	}
	return 0;
}
