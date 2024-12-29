
Problem Statement
    
Farmer John had N cows numbered 0 to N-1. One day he saw K cows running away from his farm. Fox Brus computed the sum of the numbers of the escaped cows. She only told John that the sum was divisible by N.  Your task is to help John by counting the number of possible sets of escaped cows. This number may be very big, so return it modulo 1,000,000,007.
Definition
    
Class:
TheCowDivTwo
Method:
find
Parameters:
int, int
Returns:
int
Method signature:
int find(int N, int K)
(be sure your method is public)
Limits
    
Time limit (s):
2.000
Memory limit (MB):
64
Constraints
-
N will be between 1 and 1,000, inclusive.
-
K will be between 1 and 47, inclusive.
-
K will be less than or equal to N.
Examples
0)

    
7
4
Returns: 5
7 cows are numbered 0 to 6 and 4 of them run away. Possible sets of escaped cows are {0, 1, 2, 4}, {0, 3, 5, 6}, {1, 2, 5, 6}, {1, 3, 4, 6}, {2, 3, 4, 5}.
1)

    
1
1
Returns: 1

2)

    
58
4
Returns: 7322

3)

    
502
7
Returns: 704466492

4)

    
1000
47
Returns: 219736903

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.