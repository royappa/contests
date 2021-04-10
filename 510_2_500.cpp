bool lucky(int x)
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

int find(int a, int b, int jLen, int bLen)
{
	vector<int> v(5000);
	v[0] = 0;
	for (int i = 1; i < 5000; i++)
	{
		v[i] = v[i-1];
		if (lucky(i))
		{
			v[i]++;
		}
	}
	// number of luckies in [i,j] = v[i]-v[j-1]

	int mb = 1000000, mj = 0;
	for (int i = a; i+jLen-1 <= b; i++)
	{
		int ei = i+jLen-1;
		for (int j = i; j+bLen-1 <= ei; j++)
		{
			int ej = j+bLen-1;
			int L = v[ej]-v[j-1];
			mb = min(L, mb);
			mj = max(mb, mj);
		}
	}
	return mj;
}

Problem Statement

John and Brus believe that the digits 4 and 7 are lucky and all others are not. According to them, a lucky number is a number that contains only lucky digits in its decimal representation.
John and Brus play the following game.

Initially, there is an interval of integers between a and b, inclusive.

First, John choose a subinterval of the initial interval that contains exactly jLen numbers.
Then, Brus chooses a subinterval of Johns subinterval that contains exactly bLen numbers. The outcome of the game is the total number of lucky numbers in Brus's subinterval.

John follows the optimal strategy that maximizes the outcome.
Brus follows the optimal strategy that minimizes the outcome.
Return the outcome of the game.

Definition

Class:
TheLuckyGameDivTwo
Method:
find
Parameters:
int, int, int, int
Returns:
int
Method signature:
int find(int a, int b, int jLen, int bLen)
(be sure your method is public)


Constraints
-
a will be between 1 and 4747, inclusive.
-
b will be between a and 4747, inclusive.
-
jLen will be between 1 and b-a+1, inclusive.
-
bLen will be between 1 and jLen, inclusive.
Examples
0)


1
10
2
1
Returns: 0
John will choose a subinterval containing two consecutive numbers. Then Brus will choose a subinterval containing just one of these two numbers. Since no two lucky numbers are consecutive, Brus will always be able to choose a subinterval containing no lucky numbers, so the outcome is 0.
1)


1
100
100
100
Returns: 6
Here, John and Brus have no choice. The outcome of the game is the number of lucky numbers between 1 and 100, inclusive.
2)


4
8
3
2
Returns: 1
John can choose one of the intervals [4; 6], [5; 7] or [6; 8]. In the first two cases Brus can choose a subinterval that contains no lucky numbers. However, in the last case, Brus will have to choose a subinterval that contains the lucky number 7. Therefore it is optimal for John to choose [6; 8], and the outcome is 1.
3)


1
100
75
50
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.