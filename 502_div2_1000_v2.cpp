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

class TheCowDivTwo {
public:

#define MOD 1000000007

int N;
typedef pair<pair<int,int>,int> piii;

map<piii,int> memo;
//
// f(p, s, r) = number of subsets consisting of numbers (cows) 0..p-1, of size s, such that the remainder of each subset modulo N is r
int f(int p, int s, int r)
{
	piii key = make_pair(make_pair(p,s),r);
	if (memo.count(key) > 0)
		return memo[key];
		
	if (p < s)
	{
		return 0;	// not enough values (cows) to make a subset of size s
	}
	if (s == 0)
	{
		return r == 0 ? 1 : 0; // empty set has a sum of 0, so its remainder mod N is 0
	}
	// s > 0, p >= s
	// two choices: use cow #p-1, or don't use it
	
	int res = 0;
	// we need subsets whose sum modulo N equals r (that's the definiton of the function)
	
	// first we add in how many subsets we get if we use cow# p-1
	// in that case the desired remainder m for the remaining cows must satisfy: (m+p-1)%N = r
	// so we "solve" for m
	int m = r-(p-1);
	// now we need to convert m to "mod N" again, and also, it may be negative. So convert m to a positive number mod N
	// the first mod may leave it negative, so we add N and do another mod (standard trick)
	
	m = ((m+N)%N+N)%N;
	res = (res+f(p-1, s-1, m))%MOD;
	
	// second we add in now many subsets we get if we skip cow#p-1
	res = (res+f(p-1, s, r))%MOD;
	
	return  memo[key] = res;

}

int find(int N_, int K) 
{
	N = N_; // save the N globally
	
    return f(N, K, 0);  // the MOD needs to be done inside the function, this is just for clarity  
}
};


//Powered by [KawigiEdit]


//Powered by [KawigiEdit]


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