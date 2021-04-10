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

class TheTicketsDivTwo {
public:
int m, n;
typedef long double LD;
int done[1100][11][11];
LD memo[1100][11][11];

// f(mask,rot,k) = probability that m'th friend is picked
// given that mask describes the remaining friends, and that they are rotated such that "rot" is the first in line
// the first friend in line may be eliminated

LD f(int mask, int rot, int k)
{
	if (done[mask][rot][k])
		return memo[mask][rot][k];

	// no friends left
	if (mask == 0)
		return 0.0;

	done[mask][rot][k] = 1;
	// find the first friend in line
	int q = rot;
	for (int i = 0; i < n; i++)
	{
		if ((mask & (1<<q)) != 0)
		{
			break;
		}
		q = (q+1)%n;
	}
	if (k == 0) // he has made k throws, and some friends are left, take the first friend
	{
		return memo[mask][rot][k] = q == m ? 1.0 : 0.0;
	}
	// 1,3,5  4   2,6
	LD p = 0.0;
	int newmask1 = mask;
	int t = (1<<q);
	int newmask2 = mask&(~t);
	if (q == m)
	{
		p = (1.0/6.0)+(3.0/6.0)*f(newmask1,(rot+1)%n,k-1)+(2.0/6.0)*f(newmask2,(rot+1)%n,k-1);
	}
	else
	{
		p = (3.0/6.0)*f(newmask1,(rot+1)%n,k-1)+(2.0/6.0)*f(newmask2,(rot+1)%n,k-1);
	}
	return memo[mask][rot][k] = p;
}

double find(int n_, int m_, int k)
{
	m = m_-1;
	n = n_;

	memset(done, 0, sizeof(done));
	return (double) f((1<<n)-1, 0, k);
}
};


//Powered by [KawigiEdit]

Problem Statement

John has two tickets for the basketball game - one for himself and one for a friend.

However, he has n friends who want to go with him. He decides to use the following strategy to choose one of them.

First, he tells his friends to form a straight single file line.
Then, he repeats the following step until he has made a choice. If there is only one friend in line, John chooses him.
Otherwise, he throws a standard six-sided die.
If the number 4 is on top, he chooses the friend who is currently first in line.
Otherwise, if the number is odd, the first friend in line must move to the end of the line, and if the number is even, the first friend in line must leave the line and go home.

While the initial John's intention is to throw a die until some friend is chosen, in practice he gets tired quickly.
If after k throws of a die he still hasn't chosen a friend, he prefers to stop the process and to choose the friend who is currently first in line.

You are given an int m, the 1-based index of a friend in the initial line.

The index of the first friend is 1, and the index of the last friend is n. Return the probability that the m-th friend in the initial line is ultimately chosen by John.

Definition

Class:
TheTicketsDivTwo
Method:
find
Parameters:
int, int, int
Returns:
double
Method signature:
double find(int n, int m, int k)
(be sure your method is public)


Notes
-
The returned value must be accurate to within a relative or absolute value of 1E-9.
Constraints
-
n will be between 1 and 10, inclusive.
-
m will be between 1 and n, inclusive.
-
k will be between 1 and 10, inclusive.
Examples
0)


2
1
1
Returns: 0.16666666666666666
There is 1/6 probability that John will choose the first friend after the first throw of a die.
1)


2
1
2
Returns: 0.5833333333333334
The first friend will go to the game if John chooses him after the first throw, or if he goes to the end of the line after the first throw and Jonh doesn't choose the second friend after the second throw. The overall probability is 1/6 + 1/2 * 5/6.
2)


7
7
4
Returns: 0.0
There's no chance for the last friend in the line to be chosen.
3)


4
2
10
Returns: 0.25264033564814814

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.