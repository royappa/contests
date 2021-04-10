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
typedef pair<int,int> pi;
typedef vector<pi> vpi;
vpi stops;

int main()
{
	int t;
	scanf("%d", &t);

	while (t-- > 0)
	{
		stops.clear();
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int sd, sa;
			scanf("%d%d", &sd, &sa);
			stops.push_back(make_pair(sd, sa));
		}
		int L, P;
		scanf("%d%d", &L, &P);
		for (int i = 0; i < n; i++)
		{
			stops[i].first = L-stops[i].first;
		}

		printf("%d\n", recsolve(b, c, r, n-1)); // Note the "n-1" because the solver starts the index of a[i] at 0
	}
	return 0;
}
