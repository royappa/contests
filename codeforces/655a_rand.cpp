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
#include <string>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long LL;


int main()
{
	vector<string>  b(2), a(2);

	cin >> a[0] >> a[1] >> b[0] >> b[1];

	map<vector<string>,int> m;
	int xi, xj, di, dj;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] == 'X')
			{
				xi = i;
				xj = j;
			}
		}
	}
	vector<int> v = {0,0, 0,1, 1,0, 1,1};
	srand(time(NULL));

	// Analysis: there are 4! possible boards available by repeated swapping = 24 boards
	// if we try randomly there is a 23/24 chance of picking the wrong board
	// probability of picking wrong k times in a row is (23/24)^k
	// probability of not picking wrong k times in a row is 1-(23/24)^k
	// there are 90 system tests, all must be passed
	// so overall probability of passing all tests is  (1-(23/24)^k)^90
	//
	for (int k = 0; k < 500; k++)
	{
		int p = rand()%4;
		di = v[2*p];
		dj = v[2*p+1];
		if ((xi == di || xj == dj) && !(xi == di && xj == dj))
		{
			swap(a[xi][xj], a[di][dj]);
			if (a == b)
			{
				cout << "YES" << endl;
				exit(0);
			}
			xi = di;
			xj = dj;
		}
	}
	cout << "NO" << endl;
	exit(0);
}
