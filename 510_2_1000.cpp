typedef long long LL;

bool lucky(LL x)
{
	if (x == 0) return false;
	while (x)
	{
		int d = x%10;
		if (d != 4 && d != 7) return false;
		x /= 10;
	}
	return true;
}

factorize(LL x, vector<LL> &v)
{
	for (LL d = 2; d*d <= x; d++)
	{
		if (x % d == 0) v.push_back(d);
		if (x % (x/d) == 0) v.push_back(x/d);
	}
	v.push_back(x);
}

bool luckyBase(LL n, LL B)
{
	while (n)
	{
		if (n%B != 4 && n%B != 7) return false;
		n /= B;
	}
	return true;
}

long long find(long long n)
{
	if (lucky(n)) return -1;

	if (n < 4) return 0;

	vector<LL> v;
	factorize(n-4, v); // all bases in which the last digit is 4
	factorize(n-7, v); // all bases in which the last digit is 7
	sort(v.begin(), v.end());
	erase(unique(v.begin(), v.end()), v.end());

	int r = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (luckyBase(n, v[i]))
			r++;
	}
	return r;
}

Problem Statement

John and Brus believe that the digits 4 and 7 are lucky and all others are not.
Recently, they became interested in numeral systems with different bases.
Normally, people use the numeral system with base 10 to represent numbers, however, there exist numeral systems with other bases.
More exactly, for each integer B, B >= 2, there exists a numeral system with base B. In this system, there are B different digits, used to represent numbers from 0 to B-1, inclusive. In order to represent a positive integer A in such system, it's necessary to find such digits a[n], a[n-1], ..., a[0], that A = a[n] * B^n + a[n-1] * B^(n-1) + ... + a[0] * B^0 (here ^ denotes the power operator), and then write these digits from left to right, in this exact order. For example, 255 = 4 * 62 + 7, therefore representation of number 255 in the numeral system with base 62 consists of two digits, the leftmost digit is 4 and the rightmost digit is 7.


The base of numeral system B is called lucky for some integer number A if all digits of the number A represented in numeral system with base B are the lucky digits (i.e. 4 and 7). For example, base 62 is lucky for the number 255.

You are given a long long n. Return the total number of lucky bases for the number n. If there are infinitely many such lucky bases, return -1 instead.


n %b = 4 means n = 4+k*b  means b divides (n-4)

so initial b's are factors of (n-4) and (n-7)

Definition

Class:
TheLuckyBasesDivTwo
Method:
find
Parameters:
long long
Returns:
long long
Method signature:
long long find(long long n)
(be sure your method is public)


Constraints
-
n will be between 1 and 10^12, inclusive.
Examples
0)


255
Returns: 1
The only lucky base for the number 255 is 62.
Note that base 52 is not lucky. Representation of 255 in this base contains digits 4 and 47. The digit 47 is not lucky, even though its decimal representation contains only lucky digits. Only the digits 4 and 7 are considered to be lucky.
1)


4
Returns: -1
All bases greater than 4 are lucky.
2)


13
Returns: 0
No lucky bases here.
3)


60
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.