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

int main()
{
	int N;
	cin >> N;
	for (int testCase = 0; testCase < N; testCase++)
	{
		int P, K, L;
		cin >> P >> K >> L;
		vector<LL> h(L,0);
		for (int i = 0; i < L; i++)
		{
			cin >> h[i];
		}
		sort(h.rbegin(), h.rend());
		vector<LL> keys(K,0); // keys[i] = number of letters assigned to key #i
		LL t = 0;
		for (int i = 0; i < L; i++)
		{
			keys[i%K]++;
			t += keys[i%K]*h(i);
		}
		cout << "Case #" << testCase+1 << ": " << t << endl;
	}
	return 0;
}
