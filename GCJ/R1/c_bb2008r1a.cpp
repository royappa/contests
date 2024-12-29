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

int main()
{
	int N;
	int c = 1;
	while (gets(buf) != NULL)
	{
		string x = buf;
		int len = x.size();
		cout << "Case #" << c++ << ": " << x.substr(len-3) << endl;
	}

	return 0;
}
