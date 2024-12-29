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
char buf[4096];

int memo[2000][200];

int f(int p, int last, vector<int> &q, int S)
{
	int n = q.size();
	if (p == n)
	{
		return 0;
	}
	int& r = memo[p][last];
	if (r != -1)
		return r;

	r = 1<<30;
	for (int s = 0; s < S; s++)
	{
		if (s != q[p])
		{
			r <?= f(p+1, s, q, S)+(s!=last);
		}
	}
	return r;
}

int main()
{
	int N;
	gets(buf);
	sscanf(buf, "%d", &N);
	for (int i = 0; i < N; i++)
	{
		int S, Q;
		gets(buf);
		sscanf(buf, "%d", &S);
		map<string,int> id;
		for (int j = 0; j < S; j++)
		{
			gets(buf);
			string se(buf);
			id[se] = j;
		}
		gets(buf);
		sscanf(buf, "%d", &Q);
		vector<int> q;
		for (int j = 0; j < Q; j++)
		{
			gets(buf);
			string se(buf);
			q.push_back(id[se]);
		}
		memset(memo, -1, sizeof(memo));
		printf("Case #%d: %d\n", i+1, f(0, 150, q, S));
	}
	return 0;
}
