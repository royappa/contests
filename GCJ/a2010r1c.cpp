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

//g++ -std=c++11 $PROBLEM$.cpp

#define MAXVAL (1<<30)

int main()
{
	int T;
	cin >> T;
	for (int testCase = 1; testCase <= T; testCase++)
	{
		int N;

		cin >> N;
		vector<int> A(N), B(N);
		for (int i = 0; i < N; i++)
		{
			cin >> A[i] >> B[i];
		}
		int num = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				num += (A[i]-A[j])*(B[i]-B[j]) < 0;
			}
		}
		printf("Case #%d: %d\n", testCase, num);
	}
	return 0;
}
