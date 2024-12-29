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
	int len = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] >= Q) {
			num += n-i;
			break;
		}
		if (v[i]+1+(len-1) >= Q) {
			len = 0;
			num++;
		}
		else {
			len++;
		}
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

