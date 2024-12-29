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
char buf[16384];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

typedef pair<int,int> pi;
typedef vector<LL> vi;

LL load(vi &q, int K)
{
	LL rev = 0;
	int i;
	for (i = 0; i < q.size(); i++)
	{
		if (q[i] > K-rev)
			break;
		rev += q[i];
	}
	rotate(q.begin(), q.begin()+i, q.end());
	return rev;
}

bool repeated(vector<vi> &runs, int &start, int &end)
{
	int n = runs.size();
	if (n == 1)
		return false;
	end = n-1;
	start = n-2;
	while (start >= 0 && runs[start] != runs[end])
	{
		start--;
	}
	return start >= 0;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int R, K, N;
		cin >> R >> K >> N;
		vi g(N);
		for (int i = 0; i < N; i++)
		{
			cin >> g[i];
		}
		vector<vi> runs;
		vi revs;
		LL rev = 0;
		int start, end;
		int r = 0;
if (debug) {for (int i = 0; i < N; i++) cout << g[i] << " "; cout << endl;}
		do
		{
			int t = load(g, K);
			rev += t;
			runs.push_back(g);
			revs.push_back(t);
if (debug) {for (int i = 0; i < N; i++) cout << g[i] << " "; cout << endl;}
			r++;
		}
		while (r < R && !repeated(runs, start, end));
		if (r < R)
		{
if (debug) {cout << "here " << r << " " << start << " " << end << endl;}
for (int i = 0; i < N; i++) cout << g[i] << " "; cout << endl;
			int left = R-r;
			LL period = 0;
			for (int i = start+1; i <= end; i++)
			{
				period += revs[i];
			}
if (debug) {cout << period << endl;}
			LL cycleLen = end-start;
			LL cycles = left / cycleLen;
			rev += period*cycles;
			left -= cycles*cycleLen;
			while (left > 0)
			{
				rev += load(g, K);
				left--;
			}
		}
		cout << "Case #" << testCase+1 << ": " << rev << endl;
	}
	return 0;
}
