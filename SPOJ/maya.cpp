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

vector<string> split_nonre(string s, string sep)
{
	char *sC = (char *) malloc(s.size()+1);
	strcpy(sC, s.c_str());
	char *sepC = (char *) sep.c_str();
	char *status = NULL;

	char *word;
	vector<string> results;
	while ((word = strtok_r(sC, sepC, &status)) != NULL)
	{
		results.push_back(word);
		sC = NULL;
	}
	return results;
}


typedef vector<string> vs;
typedef vector<vs> vvs;

int digitValue(vs dig)
{
	if (dig[0] == "S")
		return 0;

	int dc = 0, sc = 0;
	for (int i = 0; i < dig.size(); i++)
	{
		if (dig[i][0] == '.')
		{
			dc += dig[i].size();
		}
		else
		{
			sc++;
		}
	}
	return dc+sc*5;
}

int value(vvs num)
{
	int mul[] = {1, 20, 360, 0, 0, 0, 0};
	for (int i = 3; i < 7; i++)
		mul[i] = 20*mul[i-1];
	reverse(num.begin(), num.end());
	int total = 0;
	for (int i = 0; i < num.size(); i++)
	{
		total += digitValue(num[i])*mul[i];
	}
	return total;
}

int main()
{
	char buf[1024];
	int n;
	gets(buf);
	sscanf(buf, "%d", &n);
	while (n != 0)
	{
		vvs num;
		for (int i = 0; i < n; i++)
		{
			gets(buf);
			int k = strlen(buf)-1;
			while (buf[k] == 10 || buf[k] == 13)
			{
				buf[k--] = 0;
			}
			vs dig = split_nonre(buf, " ");
			num.push_back(dig);
		}
		printf("%d\n", value(num));
		gets(buf); // blank line
		gets(buf);
		sscanf(buf, "%d", &n);
	}
	return 0;
}
