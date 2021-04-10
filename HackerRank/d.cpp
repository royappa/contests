#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
#define MOD int(1e9+1)

int memo[60][60][60][60][2];

int f(int RR, int RB, int BB, int BR, int last)
{
	if (RR+RB+BB+BR == 0)
		return 1;
	int& r = memo[RR][RB][BB][BR][last];
	if (r != -1)
		return r;
	r = 0;
	if (last == 0)
	{
		if (RR > 0) r = (r + f(RR-1, RB, BB, BR, 0))%MOD;
		if (RB > 0) r = (r + f(RR, RB-1, BB, BR, 1))%MOD;
	}
	else
	{
		if (BB > 0) r = (r + f(RR, RB, BB-1, BR, 1))%MOD;
		if (BR > 0) r = (r + f(RR, RB, BB, BR-1, 0))%MOD;
	}
	return r;
}


int main()
{
    int RR;
    int RB;
    int BB;
    int BR;
    cin >> RR >> RB >> BB >> BR;
    memset(memo, -1, sizeof(memo));
    int a = f(RR-1, RB, BB, BR, 0);
    a = (a + f(RR, RB-1, BB, BR, 1))%MOD;
    a = (a + f(RR, RB, BB-1, BR, 1))%MOD;
    a = (a + f(RR, RB, BB, BR-1, 0))%MOD;

    cout << a << endl;
    return 0;
}
