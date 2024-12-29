// @JUDGE_ID:  55118HH  10714  C++  "Problem B: Ants"

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

using namespace std;

main()
{

	int s;
	cin >> s;

	while (s-- > 0)
	{
		int len, n;
		cin >> len >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++)
		{
			cin >> p[i];
		}
		int least = 0, most = 0;
		for (int i = 0; i < n; i++)
		{
			least = max(least, min(p[i], len-p[i]));
			most = max(most, max(p[i], len-p[i]));
		}
		cout << least << " " << len << endl;
	}
	exit(0);
}
