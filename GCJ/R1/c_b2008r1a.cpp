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
int debug = 1;
char buf[4096];

typedef pair<int,int> pi;

vector<int> v1, v2;
int main()
{
	int T;
	cin >> T;
	printf("scale=600\n");
	printf("s=sqrt(5)\n");
	for (int testCase = 0; testCase < T; testCase++)
	{
		int n;
		cin >> n;
		printf("(3+s)^%d\n", n);
	}
	return 0;
}
