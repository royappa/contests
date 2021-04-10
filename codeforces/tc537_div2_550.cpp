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
#include <string>
#include <cstring>

using namespace std;

typedef long long LL;

int main()
{
	// inputs: A,B,X in [1..200]
	// A,B is current currency
	// X is one coin of new currency
	// all prices are some p*A+q*B
	// how many Y's are there such that for every p*A+q*B there is some r*X+s*Y = p*A+q*B? If infinite, return -1

	// if z = p*A+q*B and g = gcd(A,B) then g|z
	// so all z's are multiples of g
	// we need to find every Y such that w = r*X+s*Y includes every z = p*A+q*B
	// if X divides A and B, then there are infinite Y's
	// Y=1 is always a solution
	// Y = g is always a solution
	// We don't need to check any Y > max(A,B)
	// for other Y, how to check that for every z = p*A+q*B, there exists r,s such that z=r*A+s*B
	// for ONE z, how to check if it can be written as r*X+s*Y = z?
	// h = gcd(X,Y)
	// then EVERY r*X+s*Y = t*h for some t
	// means z = t*h
	// means z is divisible by h
	// we also know that z is divisible by g





	exit(0);
}

