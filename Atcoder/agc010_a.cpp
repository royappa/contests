#include <bits/stdc++.h>

//http://agc010.contest.atcoder.jp/tasks/agc010_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int N;
	cin >> N;
	LL x;
	int numE = 0, numO = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		numO += x%2;
	}
	numE = N-numO;
	numE += numO/2;
	numO %= 2;
	numE = numE>0;
	if (numO+numE == 1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	exit(0);
}
