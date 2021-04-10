#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

LL memo[32][2][2][2];

int getBit(int M, int p)
{
	return (M>>p)&1;
}

LL gendig(int p, bool prefixIsLessA, bool prefixIsLessB, bool prefixIsLessK, int A, int B, int K)
{
	if (p == -1)
		return prefixIsLessA && prefixIsLessB && prefixIsLessK ? 1 : 0;

	LL& r = memo[p][prefixIsLessA][prefixIsLessB][prefixIsLessK];
	if (r != -1LL)
		return r;
	r = 0;
	int pA = getBit(A, p);
	int pB = getBit(B, p);
	int pK = getBit(K, p);
	// Using the decimal template, we just generate all combinations of the bits in position "p" for A,B,K
	// Of course since this is binary we can range only up to 1, not 9
	// We only count those combinations which are legal for the problem requirements
	// This implementation is of course not as efficient or as short as the reference solution (although asymptotically the same time)
	// But it requires less case analysis: we are just trying all combos
	for (int bA = 0; bA <= (prefixIsLessA?1:pA); bA++)
	{
		for (int bB = 0; bB <= (prefixIsLessB?1:pB); bB++)
		{
			for (int bK = 0; bK <= (prefixIsLessK?1:pK); bK++)
			{
				if ((bA & bB) == bK)
				{
					r += gendig(p-1, prefixIsLessA||(bA<pA), prefixIsLessB||(bB<pB), prefixIsLessK||(bK<pK), A, B, K);
				}
			}
		}
	}
	return r;
}

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int A, B, K;
		cin >> A >> B >> K;
		memset(memo, -1LL, sizeof(memo));
		cout << "Case #" << testCase << ": ";
		cout << gendig(31, false, false, false, A, B, K) << endl;
	}
	return 0;
}
