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

int s[1001][12][1001];  // s[L][S][M] = smallest number, L digits long, whose digits add up to S, and whose remainder mod n is M

main()
{


	for (int i = 0; i < 50; i++)
	{
		memset(s, -1, sizeof(s));
	}
	exit(0);
}
