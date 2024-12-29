#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FoxAverageSequence {
public:

int n;
vector<int> seq;
#define MOD 1000000007

int memo[41][1601][41][2];

int f(int p, int sum, int last, int incr)
{
	if (p == n)
		return 1;

	int& r = memo[p][sum][last][incr];
	if (r != -1)
		return r;

	r = 0;
	for (int i = 0; i <= 40; i++)
	{
		if (seq[p] != -1 && seq[p] != i) continue;
		if (p == 0 || i <= sum/p)
		{
			if (p < 2)
			{
				r = (r+f(p+1, sum+i, i, i >= last))%MOD;
			}
			else
			{
				if (incr)
				{
					r = (r+f(p+1, sum+i, i, i >= last))%MOD;
				}
				else if (i >= last)
				{
					r = (r+f(p+1, sum+i, i, 1))%MOD;
				}
			}
		}
	}
	return r;
}

int theCount(vector <int> seq_)
{
	seq = seq_;
	n = seq.size();
	memset(memo, -1, sizeof(memo));
	return f(0, 0, 0, 0);
}
};


Problem Statement

Fox Ciel likes sequences of integers. She especially likes sequences which she considers to be beautiful.
A sequence (A[0], A[1], ..., A[N-1]), N >= 1, is beautiful if and only if it satisfies the following conditions:

Each element of the sequence is an integer between 0 and 40, inclusive.
Each element of the sequence is less than or equal to the arithmetic mean of the previous elements.
That is, for each i, 1 <= i < N, we have A[i] <= (A[0] + A[1] + ... + A[i-1]) / i.

There are no three consecutive elements in the sequence that follow in strictly decreasing order.
In other words, there must be no index i, 0 <= i < N-2, such that A[i] > A[i+1] > A[i+2].

You are given a vector <int> seq that describes some sequences.
Each element in seq is between -1 and 40, inclusive.
You can change each occurrence of -1 in seq into an arbitrary integer between 0 and 40, inclusive.
Different occurrences can be changed into different integers.

Return the number of different beautiful sequences that can be obtained in this way, modulo 1,000,000,007.

Definition

Class:
FoxAverageSequence
Method:
theCount
Parameters:
vector <int>
Returns:
int
Method signature:
int theCount(vector <int> seq)
(be sure your method is public)


Notes
-
Two sequences of the same length are different if there is at least one position at which their elements are different.
Constraints
-
seq will contain between 1 and 40 elements, inclusive.
-
Each element of seq seq will be between -1 and 40, inclusive.
Examples
0)


{3, -1}
Returns: 4
{3, 0}, {3, 1}, {3, 2} and {3, 3} are valid sequences.
1)


{5, 3, -1}
Returns: 2
{5, 3, 3} and {5, 3, 4} are valid sequences.
2)


{-1, 0, 40}
Returns: 0
There are no valid sequences.
3)


{-1, 40, -1, -1, -1, 10, -1, -1, -1, 21, -1}
Returns: 579347890

4)


{-1, 12, 25, 0, 18, -1}
Returns: 58

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.