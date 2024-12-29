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

using namespace std;

typedef long long LL;


int main()
{
	int n;
	cin >> n;
	vector<char> sex(n);
	vector<int> start(n), end(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sex[i] >> start[i] >> end[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << sex[i] << ":" << start[i] << ":" << end[i] << endl;
	}
	cout << num/2 << endl;
}

