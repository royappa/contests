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
char buf[16384];
typedef long long LL;
// returns a%m where a may be negative
#define MF(a,m) (((a)%(m)+(m))%(m))


int main()
{
	int T;
	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N, K;
		cin >> N >> K; // number of snappers and snaps
		int N2 = 1<<N;
		cout << "Case #" << testCase+1 << ": " << (K%N2==N2-1 ? "ON" : "OFF") << endl;
	}
	return 0;
}
