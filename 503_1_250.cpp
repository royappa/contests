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

class ToastXToast {
public:
vector<int> u, v;
int n, m;
int memo[52][52][52];

// return true if there are k types of bread in u[0,p] and v[0,q]
int f(int k, int p, int q)
{
	if (k == 1)
	{
		return u[p] < v[0];
	}
	if (p == 0 || q == 0)
	{
		return 0;
	}
	int& r = memo[k][p][q];
	if (r != -1)
		return r;
	r = 0;
	if (u[p] < v[q])
	{
		r = f(k-1, p-1, q-1) || f(k, p-1, q) || f(k, p, q-1);
	}
	return r;
}


int bake(vector <int> uu, vector <int> vv)
{
	u = uu;
	v = vv;
	sort(u.begin(), u.end());
	sort(v.begin(), v.end());
	n = u.size();
	m = v.size();

	for (int i = 1; i <= min(n,m); i++)
	{
		memset(memo, -1, sizeof(memo));
		if (f(i, n-1, m-1))
		{
			return i;
		}
	}
	return -1;
}
};


//Powered by [KawigiEdit]


Problem Statement

NOTE: This problem statement contains images that may not display properly if viewed outside of the applet.  Toastman is going to create several eye-popping slices of toast out of several types of bread.   Each type of bread has a positive number X (not necessarily integer) such that if a slice of bread of that type is toasted for less than X minutes, it becomes under toasted and if it is toasted for more than X minutes, it becomes over toasted. A slice of bread that is toasted for exactly X minutes becomes an eye-popping slice of toast.   Note that the number X for different types of bread may be different, but such numbers will be the same for every slice of bread of a particular bread type.  Toastman has toasted several slices of bread with the hope of creating an eye-popping slice of toast from several types of bread. Unfortunately he didn't know the exact value of X for any type of bread so all the slices of bread that he toasted became either under toasted or over toasted. You are given vector <int>s undertoasted and overtoasted denoting the slices of toast that were under toasted and over toasted, respectively. Each element will be an integer denoting the number of minutes that the corresponding slice of bread was toasted.  Toastman does not have a very good memory (his brain is made out of bread!). Although he forgot which type of bread was used for each slice of toast, he thinks that the following condition was satisfied:
Each type of bread was used for at least one under toasted slice of toast and at least one over toasted slice of toast.
Return the minumum number of types of bread that could statisfy this condition. If the condition can not be satisified return -1.
Definition

Class:
ToastXToast
Method:
bake
Parameters:
vector <int>, vector <int>
Returns:
int
Method signature:
int bake(vector <int> undertoasted, vector <int> overtoasted)
(be sure your method is public)


Notes
-
Assume that for any positive number X, there exists a bread type that needs to be toasted for exactly X minutes in order to become an eye-popping toast.
Constraints
-
undertoasted will contain between 1 and 50 elements, inclusive.
-
Each element of undertoasted will be between 1 and 1,000,000, inclusive.
-
All the elements of undertoasted will be distinct.
-
overtoasted will contain between 1 and 50 elements, inclusive.
-
Each element of overtoasted will be between 1 and 1,000,000, inclusive.
-
All the elements of overtoasted will be distinct.
-
overtoasted and undertoasted will not have an element in common.
Examples
0)


{2,4}
{5,6,3}
Returns: 2
Two types of bread is sufficient as illustrated below.
1)


{5}
{4}
Returns: -1

2)


{1,2,3}
{5,6,7}
Returns: 1

3)


{1,3,5}
{2,4,6}
Returns: 2

This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.