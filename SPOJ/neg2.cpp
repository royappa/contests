// negative base conversion to negative bases
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

int main()
{
	int t;

	scanf("%d", &t);

	if (t == 0)
	{
		printf("0\n");
		return 0;
	}
	string r = "";
	while (abs(t) > 0)
	{
		int last = abs(t) % 2;
		r = char('0'+last)+r;
		if (t > 0)
			t /= -2;
		else
			t = (t-1) / -2;
	}
	printf("%s\n", r.c_str());
	return 0;
}

