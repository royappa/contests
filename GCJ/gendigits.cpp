
#include <iostream>
#include <string.h>

using namespace std;

typedef long long LL;

// adjust memo size depending on desired size of M
int memo[10][2];

int getDigit(int M, int p)
{
	while (p--)
	{
		M /= 10;
	}
	return M%10;
}

// Function count(...,M) provides a template for counting the number of integers less than M
// Given a decimal integer M, it returns exactly M.
// However, the method of counting can be adapted to answer many questions of the type "How many integers less than M satisfy some condition".

// More specifically, count(p, prefixIsLess, M) is counting those numbers which satisfy the following conditions:
//    Their "prefix" of digits to the left of position p, are either LESS THAN, or EQUAL TO, the corresponding prefix of M,
//	  as indicated by the parameter prefixIsLess:
//		if that parameter is true, then count those numbers for whom their prefix is LESS
//	  	otherwise count those numbers for whom the prefix is EQUAL TO the same prefix of M.
//
// Note that p=0 is the least significant digit position.
//
// Example: suppose M = 56789
// count(2, true,   M) will return the count for any pattern such as 55dxx, 54dxx, 53dxx,..., 00dxx.
// 		In this case the prefix is LESS. So, digit "d" in position p=2 can range from 0..9, because any number with such a prefix is less than M already.
//		Say the prefix is 54.
//		The return value is 1000 because dxx from range from 000..999 and all such numbers 54000..54999 are less than M.
//
// count(2, false,  M) will return count of all the numbers with the pattern 56dxx
//		In this case, the prefix is EQUAL to 56. So the digit in position p (indicated by "c" above) can only count up to 7.
//		The return value is 789 because dxx can range from 000..788 and the numbers 56000..56788 are less than M.
//
// Because these "dxx" types of subproblems are repeatedly calculated recursively, memoization is used to cache the results
//
// We can start out with "p" being in some far left position that is guaranteed to be bigger than M, so the first few prefixes we build are all 0.
//
int count(int p, bool prefixIsLess, int M)
{
	if (p == -1)
		return prefixIsLess ? 1 : 0;

	int& r = memo[p][prefixIsLess];
	if (r != -1)
		return r;
	r = 0;
	int pM = getDigit(M, p);
	// Generate the possible digits in position p, based on the prefix status of EQUAL or LESS
	// If the status is LESS then position p can range up to 9
	// Otherwise status is EQUAL, and position p can range only up to whatever is in position p of M
	for (int d = 0; d <= (prefixIsLess?9:pM); d++)
	{
		r += count(p-1, prefixIsLess||(d<pM), M); // Update the prefix status of the new prefix which is one digit longer
	}
	return r;
}

int main()
{
	int T;
	// some samples
	memset(memo, -1, sizeof(memo));
	cout << count(2, false, 56789) << endl;
	memset(memo, -1, sizeof(memo));
	cout << count(2, true, 56789) << endl;

	cout << "Enter number of test cases:" << endl;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int M;
		cout << "Enter M:" << endl;
		cin >> M;
		memset(memo, -1, sizeof(memo));
		cout << count(8, false, M) << endl; // boring output
	}
	return 0;
}
