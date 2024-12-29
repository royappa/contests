// SEE COMMENTS FOR CODE ATTRIBUTIONS (IF ANY)
// CAN'T FIND RULES ABOUT USING CODE FOUND ON WEB
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
#include <queue>

using namespace std;

#define MOD 1000000007

typedef pair<int,int> pii;

// return min# of stops to reach the end if we are at p with a certain amount of fuel left
int f(int p, int fuel)
{
	if (p == LAST STOP)
	{
		return 0; // no more stops needed
	}
	else if (p == FIRST STOP)
	{
		return f(p+1, M-dist); // we don't count first position, so we start with full tank
	}
	else if (fuel < distance to next stop)
	{
		// must refuel here; fill up to max
		return 1 + f(p+1, M-dist);
	}
	else
	{
		// fuel >= distance to next stop - so we can choose if to stop here or not
		int way1 = 1+f(p+1, M-dist); // just stop and fill up here
		int way2 = f(p+1, fuel-dist); // go to next without stopping
		return min(way1, way2);
	}
}

int main()
{
	// find the least number of stops

	f(0, M);
}

