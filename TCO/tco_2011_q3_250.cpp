int gcd(int a, int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int lcm(vector<int> &v, int m)
{
	int K = v.size();
	int t = 1;
	for (int i = 0; i < K; i++)
	{
		if ((m&(1<<i)) == 0) continue;
		t = (t*v[i])/gcd(t,v[i]);
	}
	return t;
}

bool eligible(vector<int> v, int t, int m)
{
	int K = v.size();
	for (int i = 0; i < K; i++)
	{
		if ((m&(1<<i)) ) continue;
		if (t%v[i] == 0) return false;
	}
	return true;
}

int getMinimum(vector <int> v)
{
	int K = v.size();
	int r = -1;
	for (int i = 0; i < (1<<K); i++)
	{
		if (__builtin_popcount(i) != K-1) continue;
		int t = lcm(v, i);
		if (r == -1 || (t < r && eligible(v, t, i)))
		{
			r = t;
		}
	}
	return r;
}

Problem Statement

You are given a vector <int> divisors containing K elements. Find a positive integer n such that exactly K-1 elements of divisors are exact divisors of n. If there are several such numbers n, return the smallest possible one. If no such number n exists, return -1 instead.
Definition

Class:
AllButOneDivisor
Method:
getMinimum
Parameters:
vector <int>
Returns:
int
Method signature:
int getMinimum(vector <int> divisors)
(be sure your method is public)


Notes
-
A number x is an exact divisor of y if y divided by x yields an integer result.
-
If x is an exact divisor of y then we call y a multiple of x.
Constraints
-
divisors will contain between 2 and 6 elements, inclusive.
-
Each element of divisors will be distinct.
-
Each element of divisors will be between 1 and 15, inclusive.
Examples
0)


{2,3,5}
Returns: 6
There are many possible values for n in this case. For example: 6, 15, 75 and 12. 6 is the smallest of them.
1)


{2,4,3,9}
Returns: 12

2)


{3,2,6}
Returns: -1
Every multiple of 3 and 2 is also a multiple of 6. Every multiple of 6 is also a multiple of 2 and 3.  Therefore, a number that is a multiple of exactly 2 out of the three elements in this array cannot exist.
3)


{6,7,8,9,10}
Returns: 360

4)


{10,6,15}
Returns: -1

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.