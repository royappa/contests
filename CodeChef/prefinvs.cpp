//https://www.codechef.com/LTIME48/problems/PREFINVS

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;


int main()
{
	string s;
	cin >> s;
	int n = s.size();
	int num = 0;
	int flip = 0;
	for (int i = n-1; i >= 0; i--) {
		int b = s[i]-'0';
		if ((b+flip)%2) {
			num++;
			flip = 1-flip;
		}
	}
	cout << num << endl;
}

