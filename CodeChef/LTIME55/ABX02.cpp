#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

#define MODULUS (int(1e9+7))
int p, q, N;
int b0, b1;
int s0, s1;
int memo[51][51][51][51][2];

int f(int num0, int num1, int open0, int open1, int next)
{
	if ((num0+num1) > N || num0 > p || num1 > q || open0 > b0 || open1 > b1) {
		return 0;
	}
	if (num0+num1 == N) {
		return 1;
	}

	int& res = memo[num0][num1][open0][open1][next];
	if (res != -1) {
		return res;
	}
	res = 0;
	if (next == 0) {
		for (int i = 1; i <= s0; i++) {
			res = (res + f(num0+i, num1, open0+1, open1, 1))%MODULUS;
		}
	}
	else {
		for (int i = 1; i <= s1; i++) {
			res = (res + f(num0, num1+i, open0, open1+1, 0))%MODULUS;
		}
	}
	return res;

}
int main()
{
	int T;
	cin >> T;


	while (T-- > 0)
	{
		cin >> p >> q >> N;
		cin >> b0 >> b1;
		cin >> s0 >> s1;
		memset(memo, -1, sizeof(memo));
		cout << (f(0, 0, 0, 0, 0)+f(0, 0, 0, 0, 1))%MODULUS << endl;
	}
}

