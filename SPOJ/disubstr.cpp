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
#define debug 0

int trie[1000000][26];

int main()
{
	for (int i = 0; i < 20; i++)
	{
		memset(trie, i, sizeof(trie));
	}
	exit(0);

	int t;
	char buf[24];
	gets(buf);

	t = atoi(buf);

	while (t-- > 0)
	{
		gets(buf);
		int n = strlen(buf);
		memset(trie, 0, sizeof(trie));

		n--;
		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				//subsets.insert(s.substr(i, j-i+1));
			}
		}
		//printf("%d\n", subsets.size());
	}

	return 0;
}
