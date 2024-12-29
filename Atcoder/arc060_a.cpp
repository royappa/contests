#include <bits/stdc++.h>

//http://arc060.contest.atcoder.jp/tasks/arc060_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;

int N, A;
vector<int> v(50);
LL memo[51][51][51*51];

LL f(int p, int k, int S) // return number of ways to make an average of A from remaining numbers [p,N) if so far we have k numbers adding up to S
{
	if (p == N)
		return (k > 0) && k*A == S;

	LL& res = memo[p][k][S];
	if (res != -1LL)
		return res;
	res = f(p+1, k, S);
	if (S+v[p] <= N*A)
		res += f(p+1, k+1, S+v[p]);
	return res;
}

int main()
{

	cin >> N >> A;
	for (int i = 0; i < N; i++)
	{
		cin >> v[i];
	}

	memset(memo, -1LL, sizeof(memo));
	cout << f(0, 0, 0) << endl;
	exit(0);
}
