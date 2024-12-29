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
int debug = 0;

//https://code.google.com/codejam/contest/11304486/dashboard

typedef long long LL;

#define MOD (1000000000+7)

int p2[10001];

int f(vector<int> &v) {
	int sum = 0;
	int n = v.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (v[j] == v[i]) continue;
			int k = j-i-1;
			sum = (sum+LL(v[j]-v[i])*p2[k]%MOD)%MOD;
		}
	}
	return sum;
}

int main()
{
	int T;
	cin >> T;

	p2[0] = 1;
	for (int i = 1; i <= 10000; i++) {
		p2[i] = 2*p2[i-1]%MOD;
	}
	for (int testCase = 0; testCase < T; testCase++)
	{
		int N;
		cin >> N;
		vector<int> v(N);
		for (int i = 0; i < N; i++) {
			cin >> v[i];
		}
		cout << "Case #" << testCase+1 << ": " << f(v) << endl;
	}
	return 0;
}
