//https://www.codechef.com/SNCKQL17/problems/TEMPLELA
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
		int n;
		cin >> n;
		vector<int> h(n);
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		bool valid = true;
		if (n%2 == 0 || h[0] != 1) {
			valid = false;
		}
		else {
			for (int i = 0; i < n/2; i++) {
				if (h[i]+1 != h[i+1]) {
					valid = false;
					break;
				}
			}
			if (valid) {
				for (int i = n/2; i < n-1; i++) {
					if (h[i] != h[i+1]+1) {
						valid = false;
						break;
					}
				}
			}
		}
		cout << (valid ? "yes" : "no") << endl;
	}
}

