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

char buf[1024*1000];

bool palindromize(char buf[], int left, int right, bool inc)
{
	bool flag = false;
	if (left > right)
		return false;
	if (left == right)
	{
		if (buf[left] == '9' || !inc)
			return false;
		buf[left]++;
		return true;
	}
	if (buf[left] == buf[right])
	{
		bool action = palindromize(buf, left+1, right-1, inc);
		if (inc && !action) // needed to increase but couldn't
		{
			if (buf[left] == '9')
				return false;
			buf[left]++;
			buf[right]++;
			for (int i = left+1; i <= right-1; i++)
				buf[i] = '0';
			return true;
		}
		return action;
		}
	else if (buf[left] > buf[right])
	{
		while (buf[left] > buf[right])
			buf[right]++;
		bool action = palindromize(buf, left+1, right-1, false);
		return true;
	}
	else // buf[left] < buf[right]
	{
		bool action = palindromize(buf, left+1, right-1, true);
		if (action)
		{
			while (buf[left] < buf[right])
				buf[right]--;
		}
		else // needed to increase but unable to increase middle digits
		{
			buf[left]++;
			buf[right] = buf[left];
			for (int i = left+1; i <= right-1; i++)
				buf[i] = '0';
		}
		return true;
	}
}

string pal(string x)
{
	sprintf(buf, "%s", x.c_str());
	int n = strlen(buf);
	if (!palindromize(buf, 0, n-1, true))
	{
		buf[0] = '1';
		for (int i = 1; i <= n-1; i++)
		{
			buf[i] = '0';
		}
		buf[n] = '1';
		buf[n+1] = '\0';
	}
	return buf;
}

bool isPal(int num)
{
	char s[100];
	sprintf(s, "%d", num);
	int i = 0, j = strlen(s)-1;
	while (i < j)
	{
		if (s[i++] != s[j--]) return false;
	}
	return true;
}

int main()
{
	int t;

	scanf("%d\n", &t);

	for (int i = 0; i < t; i++)
	{
		gets(buf);

		int n = strlen(buf);
		if (!palindromize(buf, 0, n-1, true))
		{
			buf[0] = '1';
			for (int i = 1; i <= n-1; i++)
			{
				buf[i] = '0';
			}
			buf[n] = '1';
			buf[n+1] = '\0';
		}
		printf("%s\n", buf);
	}
	return 0;
}
