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
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef int LL;

main()
{
	int n;

	LL ox = 25032213, oy = 29;
	LL x = 1;
	int A[101][101];
	for (int i = 0; i < 2000; i++)
	{

		memset(A, 0, sizeof(A));
		A[0][0] = x;
	}
	printf("%d\n", int(A[0][0]));
	exit(0);
}
