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

int debug = 0;
int f[100][100];
int p[100][100];

int cost[100][100];

void solve(int t, int K, int L, char keys[], char letters[], int freq[])
{
	for (int i = K; i >= 1; i--)
	{
		keys[i] = keys[i-1];
	}

	for (int i = L; i >= 1; i--)
	{
		letters[i] = letters[i-1];
		freq[i] = freq[i-1];
	}

	memset(cost, 0, sizeof(cost));
	for (int start = 1; start <= L; start++)
	{
		for (int len = 1; len <= L-start+1; len++)
		{
			cost[start][len] = cost[start][len-1] + len*freq[start+len-1];
		}
	}

	f[1][1] = freq[1];
	p[1][1] = 1;
	for (int i = 2; i <= L; i++)
	{
		f[1][i] = f[1][i-1]+i*freq[i];
		p[1][i] = 1;
	}
	for (int k = 2; k <= K; k++)
	{
		for (int j = k; j <= L; j++)
		{
			// compute f[k][j] = MIN(..)
			int m = 1<<30;
			int mpos;
			for (int i = j; i >= k; i--)
			{
				int c = f[k-1][i-1]+cost[i][j-i+1];
				if (c <= m)
				{
					m = c;
					mpos = i;
				}
			}
			f[k][j] = m;
			p[k][j] = mpos;
		}
	}

	vector<string> r;
	int pos = L;
	for (int i = K; i >= 1; i--)
	{
		char s[100];
		int len = pos-p[i][pos]+1;
		strncpy(s, &letters[p[i][pos]], len);
		s[len	] = '\0';
		r.push_back(s);
		pos = p[i][pos]-1;
	}
	reverse(r.begin(), r.end());
	printf("Keypad #%d:\n", t);
	for (int k = 1; k <= K; k++)
	{
		printf("%c: %s\n", keys[k], r[k-1].c_str());
	}
	printf("\n");
}
int main()
{
	int d;
	char buf[1024];

	gets(buf);
	sscanf(buf, "%d", &d);

	for (int t = 1; t <= d; t++)
	{
		int K, L;
		gets(buf);
		sscanf(buf, "%d%d", &K, &L);
		char keys[100], letters[100];

		gets(keys);
		gets(letters);

		int freq[100];
		for (int i = 0; i < L; i++)
		{
			gets(buf);
			sscanf(buf, "%d", &freq[i]);
		}
		solve(t, K, L, keys, letters, freq);
	}

	return 0;
}
