#include <bits/stdc++.h>

//http://codeforces.com/contest/785/problem/D

using namespace std;

typedef long long LL;
typedef pair<LL,LL> pp;


int main()
{
	int n;
	cin >> n;
	LL sides = 0;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sides += (s == "Cube") ? 6 :
				 (s == "Tetrahedron") ? 4 :
				 (s == "Octahedron") ? 8 :
				 (s == "Dodecahedron") ? 12 : 20;
	}
	cout << sides << endl;
	exit(0);
}
