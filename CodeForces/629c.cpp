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


using namespace std;


typedef long long LL;


int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int bal = 0, numL = 0, numR = 0;
	for (int i = 0; i < m; i++)
	{
		if (s[i] == '(') { numL++; bal++; }
		else { numR++; bal--; }

	cout << num*2 << endl;
}
