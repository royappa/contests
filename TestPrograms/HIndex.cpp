#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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

typedef long long LL;

class HIndex {
public:

bool valid(LL h, vector<int> &r, LL b, LL p) {
	int n = r.size();
	if (h > n) return false;
	for (int i = 0; i < h; i++) {
		if (r[i] < h) {
			LL need = h - r[i];
			if (b < need * p) {
				return false;
			}
			b -= need * p;
		}
	}
	return true;
}

int cheat(vector <int> r, int b, int p) {
	sort(r.rbegin(), r.rend());
	LL lo = 0, hi = 300*1e9+1;
	while (hi != lo+1) {
		LL mid = lo + (hi - lo)/2;
		if (valid(mid, r, b, p)) {
			lo = mid;
		}
		else {
			hi = mid;
		}
	}
	return lo;
}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1 << "," << p2;
	cout << "]" << endl;
	HIndex *obj;
	int answer;
	obj = new HIndex();
	clock_t startTime = clock();
	answer = obj->cheat(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	vector <int> p0;
	int p1;
	int p2;
	int p3;
	
	{
	// ----- test 0 -----
	int t0[] = {25,3,5,3,8,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 447;
	p2 = 1000;
	p3 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {25,3,5,3,8,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1447;
	p2 = 1000;
	p3 = 4;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {0,0,0,2,0,0,1,0,0,0,0,0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 140000;
	p2 = 10000;
	p3 = 4;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {0,0,0};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 999999999;
	p2 = 1000000000;
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!