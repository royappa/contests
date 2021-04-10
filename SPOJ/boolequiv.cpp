// My own problem for Sharat's contest
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
int debug = 1;


bool eval(string s, int val)
{
	vector<bool> stack;

	for (int i = 0; i < s.size(); i++)
	{
		if (isalpha(s[i]))
		{
			stack.push_back(!!(val & (1<<(s[i]-'A'))));
		}
		else if (s[i] == '!')
		{
			bool t = stack.back(); stack.pop_back();
			stack.push_back(!t);
		}
		else if (s[i] == '+')
		{
			bool t = stack.back(); stack.pop_back();
			bool r = stack.back(); stack.pop_back();
			stack.push_back(r || t);
		}
		else if (s[i] == '*')
		{
			bool t = stack.back(); stack.pop_back();
			bool r = stack.back(); stack.pop_back();
			stack.push_back(r && t);
		}
	}
	return stack.back();
}

bool equiv(string a, string b)
{
	for (int v = 0; v < (1<<10); v++)
	{
		bool va = eval(a, v);
		bool vb = eval(b, v);
		if (va != vb)
			return false;
	}
	return true;
}

int main()
{
	char buf[100];

	int t;
	gets(buf);
	sscanf(buf, "%d", &t);

	while (t-- > 0)
	{
		char b1[100], b2[100];
		gets(b1);
		gets(b2);
		b1[strlen(b1)-1] = '\0';
		b2[strlen(b2)-1] = '\0';

		printf(equiv(b1, b2) ? "YES\n" : "NO\n");
	}
	return 0;
}
