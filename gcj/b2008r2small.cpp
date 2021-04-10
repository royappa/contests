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
#include <queue>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))



typedef pair<int,int> pi;

int main()
{


	int C;
	cin >> C;
	for (int testCase = 0; testCase < C; testCase++)
	{
		int N, M, A;

		cin >> N >> M >> A;
		bool poss = false;


		int xA, yA, xB, yB, xC, yC;
		for (int xA = 0; xA <= 0; xA++)
		{
			for (int yA = 0; yA <= M; yA++)
			{
				for (int xB = 0; xB <= N; xB++)
				{
					for (int yB = 0; yB <= M; yB++)
					{
						if (xA == xB && yA == yB) continue;
						for (int xC = 0; xC <= N; xC++)
						{
							for (int yC = 0; yC <= M; yC++)
							{
								if (xC == xA && yC == yA) continue;
								if (xC == xB && yC == yB) continue;

								if (abs((xB*yA-xA*yB)+(xC*yB-xB*yC)+(xA*yC-xC*yA)) == A)
								{
									poss = true;
									goto outer;
								}
							}
						}
					}
				}
			}
		}
		for (int xA = 0; xA <= N; xA++)
		{
			for (int yA = 0; yA <= 0; yA++)
			{
				for (int xB = 0; xB <= N; xB++)
				{
					for (int yB = 0; yB <= M; yB++)
					{
						if (xA == xB && yA == yB) continue;
						for (int xC = 0; xC <= N; xC++)
						{
							for (int yC = 0; yC <= M; yC++)
							{
								if (xC == xA && yC == yA) continue;
								if (xC == xB && yC == yB) continue;

								if (abs((xB*yA-xA*yB)+(xC*yB-xB*yC)+(xA*yC-xC*yA)) == A)
								{
									poss = true;
									goto outer;
								}
							}
						}
					}
				}
			}
		}
		outer:
		if (poss)
		{
			printf("Case #%d: %d %d %d %d %d %d\n", testCase+1, xA, yA, xB, yB, xC, yC);
		}
		else
		{
			printf("Case #%d: IMPOSSIBLE\n", testCase+1);
		}
	}
	return 0;
}
