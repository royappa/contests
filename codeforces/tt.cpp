#include <bits/stdc++.h>

//http://codeforces.com/contest/673/problem/C

using namespace std;

typedef long long LL;


int main()
{
	int n = 5000;
	cout << n << endl;
	srand(time(0));
	for (int i = 1; i <= n; i++)
		cout << 1+rand()%n << " ";
	cout << endl;
	exit(0);
}
