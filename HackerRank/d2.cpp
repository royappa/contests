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
#define ADD_MOD(a,b) (a) = ((a)+(b))%MOD

int f[80][80][80][80][2];

int main()
{
    int RR;
    int RB;
    int BB;
    int BR;
    cin >> RR >> RB >> BB >> BR;

    f[0][0][0][0][0] = f[0][0][0][0][1] = 1;

	for (int rr = 0; rr <= RR; rr++)
	{
		for (int rb = 0; rb <= RB; rb++)
		{
			for (int bb = 0; bb <= BB; bb++)
			{
				for (int br = 0; br <= BR; br++)
				{
					if (rr+rb+bb+br == 0) continue;
					f[rr][rb][bb][br][0] = 0;
					if (rr > 0) ADD_MOD(f[rr][rb][bb][br][0], f[rr-1][rb][bb][br][0]);
					if (rb > 0) ADD_MOD(f[rr][rb][bb][br][1], f[rr][rb-1][bb][br][0]);
					if (bb > 0) ADD_MOD(f[rr][rb][bb][br][1], f[rr][rb][bb-1][br][1]);
					if (br > 0) ADD_MOD(f[rr][rb][bb][br][0], f[rr][rb][bb][br-1][1]);
				}
			}
		}
	}

    cout << (f[RR][RB][BB][BR][0]+f[RR][RB][BB][BR][1])%MOD << endl;
    return 0;
}
