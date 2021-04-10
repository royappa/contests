#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int qa[1001], qb[1001];
int memo[1001][1001];
int M, N;

//https://www.hackerrank.com/contests/w19/challenges/two-robots

int f(int p1, int p2)
{
	if (max(p1, p2) == N)
		return 0;

	int& res = memo[p1][p2];
	if (res != -1)
		return res;

	int next = max(p1, p2)+1;
	int dist = abs(qa[next]-qb[next]);

	int r1 = (p1 == 0 ? 0 : abs(qa[next]-qb[p1])) + dist + f(next, p2);
	int r2 = (p2 == 0 ? 0 : abs(qa[next]-qb[p2])) + dist + f(p1, next);

	return res = min(r1, r2);
}
int main() {
    int testCases;
    cin >> testCases;
    while (testCases-- > 0)
    {
		cin >> M >> N;
		for (int i = 1; i <= N; i++)
		{
			cin >> qa[i] >> qb[i];
		}
		memset(memo, -1, sizeof(memo));
		cout << f(0, 0) << endl;
	}
    return 0;
}
