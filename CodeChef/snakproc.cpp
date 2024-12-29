//https://www.codechef.com/SNCKQL17/problems/SNAKPROC
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



int main()
{
	int T;
	cin >> T;
	while (T-- > 0) {
		int len;
		cin >> len;
		string s;
		cin >> s;
		char next = 'H';
		bool valid = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '.') continue;
			if (s[i] != next) {
				valid = false;
				break;
			}
			next = next == 'H' ? 'T' : 'H';
		}
		if (!valid || next == 'T') {
			cout << "Invalid";
		}
		else {
			cout << "Valid";
		}
		cout << endl;
	}
}

