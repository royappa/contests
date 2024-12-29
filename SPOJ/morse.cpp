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
typedef long long LL;
int debug = 0;
char buf[1024*10];
char wdict[1024*10][21];
char mdict[1024*10][21*5];
int wordLen[1024*10];

int nw; // number of words
char *morse[] =
{
".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..",
"--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
};

int memo[1024*10];

int find(int len)
{
	if (len == 0)
	{
		return 1;
	}
	int &c = memo[len];
	if (c != -1)
		return c;

	c = 0;
	for (int i = 0; i < nw; i++)
	{
		int wLen = wordLen[i];
		if (len >= wLen && !strncmp(buf+len-wLen, mdict[i], wLen))
		{
			c += find(len-wLen);
		}
	}
	return c;
}

int main()
{
	int tests;
	scanf("%d", &tests);
	while (tests-- > 0)
	{
		scanf("%s", buf);
		scanf("%d", &nw);
		for (int i = 0; i < nw; i++)
		{
			scanf("%s", wdict[i]);
			strcpy(mdict[i], "");
			for (int j = 0; j < strlen(wdict[i]); j++)
			{
				strcat(mdict[i], morse[wdict[i][j]-'A']);
			}
			if (debug) printf("%s\n", mdict[i]);
			wordLen[i] = strlen(mdict[i]);
		}
		int len = strlen(buf);
		memset(memo, -1, (len+1)*sizeof(int));
		printf("%d\n", find(len));
	}

	return 0;
}
