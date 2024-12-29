//https://www.codechef.com/SNCKQL17/problems/SNAKEEAT
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

void process(vector<int> &v, int Q) {
	int n = v.size();
	int num = 0;
	auto good = lower_bound(v.begin(), v.end(), Q);
	if (good != v.end()) {
		num += v.end()-good;
		n = good-v.begin();
	}
//cout << "n = " << n << endl;
	// all numbers >= Q have been removed. Now we have to combine snakes to form more.
	// each biggest snake is paired with however many smaller snakes it needs to eat, until we can't form more
	int p = 0;
	while (n > 0) {
		int req = Q-v[n-1];
		if (n-p-1 < req)
			break;
		//auto top = lower_bound(v.begin(), v.end(), v[n-1]);
 		auto top = lower_bound(v.begin()+p, v.begin()+n, v[n-1]);
		int t = top-v.begin(); // p <= t < n  and t is where the top snakes start
		int k = n-t; // there are k top snakes, we process them as a group.
		//The groups will have deficiencies from Q of 1,2,3,4.. in the worst case
		// So the outer loop will run O(sqrt(n)) times so this solution is O(sqrt(n)*log(n)) for each Q.
		// thus overall for each test case is O(n*sqrt(n)*log(n))

		// find largest r >= 0 such that r <= k and p+r*req < n-r
		// can this be done in constant time:    r*(req+1) < n-p =>  r < (n-p)/(req+1)
		int lo = 0; // r = 0, meets the conditions
		int hi = k+1; // does not meet conditions
		while (hi != lo+1) {
			int r = (lo+hi)/2;
			if (r <= k && p+r*req <= n-r) {
				lo = r;
			}
			else {
				hi = r;
			}
		}
		//end
		int r = lo;
//cout << "p = " << p << " n = " << n << " k = " << k << " req = " << req << " r = " << r << endl;
		num += r;
		p += r*req;
		n -= r;
		if (r < k)
			break;
	}
	cout << num << endl;
}

int main()
{
	int T;
	cin >> T;
	while (T-- > 0) {
		int N, NQ;
		cin >> N >> NQ;
		vector<int> L(N);
		for (int i = 0; i < N; i++) {
			cin >> L[i];
		}
		sort(L.begin(), L.end());
		for (int i = 0; i < NQ; i++) {
			int Q;
			cin >> Q;
			process(L, Q);
		}
	}
}

