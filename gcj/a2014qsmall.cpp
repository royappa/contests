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
#include <string.h>

using namespace std;
int debug = 0;
char buf[4096];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))

typedef pair<int,int> pi;

int main()
{


	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int A[4][4], B[4][4];
		int rowA, rowB;
		cin >> rowA;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> A[i][j];
			}
		}
		cin >> rowB;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> B[i][j];
			}
		}
		vector<int> solutions;

		// find all numbers common to both rows; those are the solutions
		vector<bool> vA(17, false), vB(17, false);
		for (int j = 0; j < 4; j++)
		{
			vA[A[rowA-1][j]] = true;
			vB[B[rowB-1][j]] = true;
		}
		for (int i = 1; i <= 16; i++)
		{
			if (vA[i] && vB[i])
			{
				solutions.push_back(i);
			}
		}
		printf("Case #%d: ", testCase);
		int num = solutions.size();
		if (num == 1)
		{
			printf("%d\n", solutions[0]);
		}
		else if (num > 1)
		{
			printf("Bad magician!\n");
		}
		else
		{
			printf("Volunteer cheated!\n");
		}
	}
	return 0;
}
