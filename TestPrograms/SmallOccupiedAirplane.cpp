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


class SmallOccupiedAirplane {
public:

string seat(int r, int c) {
	char buf[100];
	sprintf(buf, "%d%c", r+1, ('A'+c));
	return string(buf);
}

void single(vector<vector<bool>> &avail, vector<string> &seats) {
	int R = avail.size();
	vector<int> pref = {0, 5, 2, 3, 1, 4};
	for (int p = 0; p < 3; p++) {
		int a = pref[2*p], b = pref[2*p+1];
		for (int r = 0; r < R; r++) {
			if (avail[r][a]) { avail[r][a] = false; seats.push_back(seat(r, a)); return; }
			if (avail[r][b]) { avail[r][b] = false; seats.push_back(seat(r, b)); return; }
		}
	}
	return;			
}

void multiple(vector<vector<bool>> &avail, vector<string> &seats, int gs) {
	int R = avail.size();
	for (int r = 0; r < R; r++) {
		int fr = count(avail[r].begin(), avail[r].end(), true);
		if (fr >= gs) {
			for (int j = 0; j < 6 && gs > 0; j++) {
				if (avail[r][j]) {
					avail[r][j] = false;
					seats.push_back(seat(r, j));
					gs--;
				}
			}
			return;
		}
	}
	for (int i = 0; i < gs; i++) {
		single(avail, seats);
	}
	return;
}

vector <string> seat(int R, vector <int> groups) {
	vector<vector<bool>> avail;
	for (int i = 0; i < R; i++) {
		vector<bool> row(6, true);
		avail.push_back(row);
	}
	vector<string> seats;
	for (auto gs : groups) {
		if (gs == 1) {
			single(avail, seats);
		}
		else {
			multiple(avail, seats, gs);
		}
	}
	return seats;
}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, bool hasAnswer, vector <string> p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}";
	cout << "]" << endl;
	SmallOccupiedAirplane *obj;
	vector <string> answer;
	obj = new SmallOccupiedAirplane();
	clock_t startTime = clock();
	answer = obj->seat(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "{";
		for (int i = 0; int(p2.size()) > i; ++i) {
			if (i > 0) {
				cout << ",";
			}
			cout << "\"" << p2[i] << "\"";
		}
		cout << "}" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "{";
	for (int i = 0; int(answer.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << answer[i] << "\"";
	}
	cout << "}" << endl;
	if (hasAnswer) {
		if (answer.size() != p2.size()) {
			res = false;
		} else {
			for (int i = 0; int(answer.size()) > i; ++i) {
				if (answer[i] != p2[i]) {
					res = false;
				}
			}
		}
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
	
	int p0;
	vector <int> p1;
	vector <string> p2;
	
	{
	// ----- test 0 -----
	p0 = 1;
	int t1[] = {1,1,4};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1F","1B","1C","1D","1E"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 10;
	int t1[] = {2,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1B","1F"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	int t1[] = {1,1,1,3};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1F","1C","1B","1D","1E"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	int t1[] = {1,1,1,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1F","2A","2B","2C","2D","2E","2F"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 2;
	int t1[] = {1,1,1,1,1,5};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1F","2A","2F","1C","1D","2C","2D","1B","1E"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 3;
	int t1[] = {4,4,4,1,2,1,1,1};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	string t2[] = {"1A","1B","1C","1D","2A","2B","2C","2D","3A","3B","3C","3D","1F","2E","2F","3F","1E","3E"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 12;
	p1.clear() /*{}*/;
	p2.clear() /*{}*/;
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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