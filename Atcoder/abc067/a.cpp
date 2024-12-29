#include <bits/stdc++.h>

//http://abc067.contest.atcoder.jp/tasks/abc067_a

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int A, B;
	cin >> A >> B;
	if (A%3 == 0 || B%3 == 0 || (A+B)%3 == 0) {
		cout << "Possible";
	}
	else {
		cout << "Impossible";
	}
	cout << endl;
	exit(0);
}
