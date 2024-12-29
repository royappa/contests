// version 1 - the correct recursive solution. will not work for large values of inputs
// version 2 - will use memoization to increase inputs
// version 3 - will convert to table-driven DP to handle all inputs
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

//
// f(p, s, r) = number of subsets consisting of numbers (cows) 0..p-1, of size s, such that the remainder of each subset modulo N is r
int f(int p, int s, int r)
{
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
	res += f(p-1, s-1, m);

	// second we add in now many subsets we get if we skip cow#p-1
	res += f(p-1, s, r);

	return res;

}

int find(int N_, int K)
{
	N = N_; // save the N globally
    return f(N, K, 0)%MOD;  // the MOD needs to be done inside the function, this is just for clarity
}
};


//Powered by [KawigiEdit]
