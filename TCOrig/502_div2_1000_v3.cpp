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

// we can't declare an array f[10001][48][1000] like we need to
// but in the recurrence relation, f[p][][] only depends on f[p-1][][]
// so we only need to store 2 slices and keep swapping between them

int f[2][48][1000];
// the recurrence is f[p][s][r] = f[p-1][s-1][m]+f[p-1][s][r]

int find(int N, int K)
{

    for (int p = 1; p <= N; p++)
    {
    	for (int s = 0; s <= K; s++)
    	{
    		for (int r = 0; r < N; r++)
    		{
    			int val;
    			if (p < s)
    			{
 					val = 0;
 				}
 				else if (s == 0)
 				{
 					val = r == 0 ? 1 : 0;
 				}
 				else if (s == 1)
 				{
 					val = r < p ? 1 : 0;
 				}
 				else
 				{
    				int m = r-(p-1);
    				m = ((m+N)%N+N)%N;
    				val = (f[(p-1)%2][s-1][m]+f[(p-1)%2][s][r])%MOD;
    			}
    			f[p%2][s][r] = val;
    		}
    	}
    }
    return f[N%2][K][0];
}

};

