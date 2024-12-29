
#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

// adjust memo size depending on desired size of M
int memo[10][2][2];

int getDigit(int M, int p)
{
	while (p--)
	{
		M /= 10;
	}
	return M%10;
}

int count(int p, bool prefixIsLess, int parity, int M)
{
	if (p == -1)
		return prefixIsLess && parity==0 ? 1 : 0;

	int& r = memo[p][prefixIsLess][parity];
	if (r != -1)
		return r;
	r = 0;
	int pM = getDigit(M, p);
	for (int d = 0; d <= (prefixIsLess?9:pM); d++)
	{
		r += count(p-1, prefixIsLess||(d<pM), (parity+(d==7))%2, M);
	}
	return r;
}
//
// Demo: for given decimal integer M, count how many integers are less than M, which contain an EVEN NUMBER OF "7" digits.
// E.g., we count numbers like 3, 177, or 2471777 and exclude ones like 7 or 70717.
// Using the "number generation" solution template, every time we generate a 7 in some digit position, we flip the parity of 7s counted so far
// ...and only count fully generated numbers whose parity is 0 (even)
// Without this solution template, such a problem requires a nasty amount of thinking (for me) and possibly a messy combinatorial solution (all numbers with zero 7s, two 7s, four 7s, etc.)

int main()
{
	int T;
	cout << "Enter number of test cases:" << endl;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int M;
		cout << "Enter M:" << endl;
		cin >> M;
		memset(memo, -1, sizeof(memo));
		cout << count(8, false, 0, M) << endl;
	}
	return 0;
}
